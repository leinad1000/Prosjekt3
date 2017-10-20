#include "eulercromer.h"
#include "system.h"

EulerCromer::EulerCromer(System* system)
    : Integrator(system) {
}

void EulerCromer::integrateOneStep(std::vector<Particle*> particles) {
    
    for (int i=0; i<particles.size(); i++) {
        Particle *p = particles.at(i);

        p-> getPosition() += p->getVelocity() * m_dt;
        p-> getVelocity() += p->getForce() / p->getMass() * m_dt;
        
    }
    m_system->computeForces();
}

std::string EulerCromer::getName() {
    return "Euler-Cromer";
}
