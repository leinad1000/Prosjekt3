#include "system.h"
#include "integrator.h"
#include "potential.h"
#include "initialcondition.h"
#include "particle.h"
#include <cmath>

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

System::System(int n, double T)
{
    m_nTimeSteps = n;
    m_T = T;
    m_days = 365.242199*m_T;
    m_rounds = m_days/m_orbital_period_mercury;
    m_data_points_per_round = ((double) m_nTimeSteps)/m_rounds;
    m_i_one_round = (int) m_data_points_per_round;

}
void System::computeForces() {
    resetAllForces();
    m_potential->resetPotentialEnergy();
    for(int i=0;i<m_numberOfParticles-1;i++){
        for(int j=i+1;j<m_numberOfParticles;j++){
            m_potential->computeForces(*m_particles.at(i),*m_particles.at(j));

        }
    } 
    // Removing the forces working on the Sun, when the Sun is to be the center of mass
    //m_particles.at(0)->resetForces();// Comment out this line when the sun is no longer supposed to be fixed
    m_potentialEnergy = m_potential->getPotentialEnergy();
}

void System::resetAllForces() {
    for (int i=0; i<m_numberOfParticles; i++) {
        m_particles.at(i)->resetForces();
    }
}

void System::setPotential(Potential* potential) {
    m_potential = potential;
}

void System::setIntegrator(Integrator* integrator) {
    m_integrator = integrator;
}

void System::setInitialCondition(InitialCondition* initialCondition) {
    m_initialCondition = initialCondition;
    m_initialCondition->setupParticles(*this);
}

void System::setDt(double dt) {
    m_integrator->setDt(dt);
}




void System::integrate(int numberOfSteps) {
    m_integrateSteps = numberOfSteps;
    computeForces();
    printIntegrateInfo(0);

    for (int i=1; i<numberOfSteps+1; i++) {
        m_integrator->integrateOneStep(m_particles);
        printIntegrateInfo(i);

        perihelion(i); // Only use this when the perihelion precession of Mercury is to be found. Otherwise comment out

        writePositionsToFile();
    }

    m_potential->resetPotentialEnergy();
    closeOutFile();
}

void System::addParticle(Particle* p) {
    m_particles.push_back(p);
    m_numberOfParticles += 1;
}

double System::computeKineticEnergy() {
    m_kineticEnergy = 0;
    for(int i=0;i<m_numberOfParticles;i++){
        Particle* p = m_particles.at(i);
        m_kineticEnergy+=0.5*(p->getVelocity().lengthSquared() * p->getMass());
    }
    return m_kineticEnergy;
}

double System::computeMomentum(){
    vec3 momentumVec;
    momentumVec.zeros();
    for(int i=0;i<m_numberOfParticles;i++){
        Particle* p = m_particles.at(i);
        momentumVec += p->getVelocity() * p->getMass();

    }
    return momentumVec.length();
}

void System::printIntegrateInfo(int stepNumber) {
    if (stepNumber == 0) {
        cout << endl
             << " STARTING INTEGRATION "    << endl
             << "-------------------------" << endl
             << "  o Number of steps:     " << m_integrateSteps << endl
             << "  o Time step, dt:       " << m_integrator->getDt() << endl
             << "  o Initial condition:   " << m_initialCondition->getName() << endl
             << "  o Number of particles: " << m_particles.size() << endl
             << "  o Potential in use:    " << m_potential->getName() << endl
             << "  o Integrator in use:   " << m_integrator->getName() << endl
             << endl;
    } else if (stepNumber % 1000 == 0) {
        m_momentum          = computeMomentum();
        m_kineticEnergy     = computeKineticEnergy();
        m_potentialEnergy   = m_potential->getPotentialEnergy();
        m_totalEnergy       = m_kineticEnergy + m_potentialEnergy;
        printf("Step: %5d    E =%10.5f   Ek =%10.5f    Ep =%10.5f, Mom =%10.5f\n",
               stepNumber, m_totalEnergy, m_kineticEnergy, m_potentialEnergy, m_momentum);
        fflush(stdout);
    }
}

void System::removeLinearMomentum() {
   
    vec3 totalMomentum = vec3(0,0,0);
    double totalMass = 0.0;
    
    for(int i=0;i<m_numberOfParticles;i++){
        Particle* p = m_particles.at(i);
        totalMomentum += (p->getVelocity() * p->getMass());
        totalMass += p->getMass();
    }
    m_particles.at(0)->getVelocity() -= (totalMomentum / m_particles.at(0)->getMass());
}

void System::setFileWriting(bool writeToFile) {
    m_writeToFile = writeToFile;
}

void System::writePositionsToFile() {
    if (m_outFileOpen == false) {
        m_outFile.open("../Project3/perihelion", std::ios::out);
        m_outFileOpen = true;
    }

    for(int i=0;i<m_particles.size();i++){
        Particle* p = m_particles.at(i);
        for(int j=0;j<3;j++){
            m_outFile << setw(15) << setprecision(8) << p->getPosition()[j] << "\t";
        }
    }
    m_outFile << endl;
}

void System::closeOutFile() {
    if (m_writeToFile == true) {
        m_outFile.close();
        m_outFileOpen = false;
        m_outFile2.close();
        m_outFileOpen2 = false;
    }
}

void System::perihelion(int stepNumber) {

    Particle* sun = m_particles.at(0);
    Particle* mercury = m_particles.at(1);
    vec3 relative_position = mercury->getPosition() - sun->getPosition();

    if (relative_position.length() < m_avstand){
        m_avstand = relative_position.length();
        m_x_p = relative_position[0];
        m_y_p = relative_position[1];
    }

    if (stepNumber == m_i_one_round*m_revolutions) {
        m_theta_p = atan2(m_y_p,m_x_p);
        m_theta_p = fabs((m_theta_p/m_pi)*180); // Converting to degrees
        if (m_outFileOpen2 == false) {
            m_outFile2.open("../Project3/theta", std::ios::out);
            m_outFileOpen2 = true;
        }
        m_outFile2 << setw(15) << setprecision(8) << m_theta_p << endl;

        m_avstand = 1.0;
        m_revolutions += 1;
    }


}
