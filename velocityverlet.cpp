#include "velocityverlet.h"
#include "system.h"

VelocityVerlet::VelocityVerlet(System* system)
    : Integrator(system) {
}

std::string VelocityVerlet::getName() {
    return "Velocity verlet";
}

void VelocityVerlet::integrateOneStep(std::vector<Particle*> particles) {
    for (int i=0; i<particles.size(); i++) {       
        Particle* p = particles.at(i);
        
        // The position
        p-> getPosition() += ((p->getVelocity() * m_dt) + (p->getForce() / p->getMass() * ((m_dt*m_dt)/2.0) ) );

        // The velocity
        p-> getVelocity() += (p->getForce() / p->getMass() * (m_dt/2.0));// The first term to be added to the velocity
    }

    /* Computing the forces with the new position, so that the acceleration at the next
    time-step can be used to calculate the final velocity at THIS time-step */
    m_system->computeForces();
    
    for (int i=0; i<particles.size(); i++){
        Particle* p = particles.at(i);
        p-> getVelocity() += (p->getForce() / p->getMass() * (m_dt/2.0)); // The second term to be added to the velocity
    }

}
