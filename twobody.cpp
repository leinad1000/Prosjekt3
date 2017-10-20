#include "twobody.h"
#include "vec3.h"
#include "system.h"
#include <cmath>


void TwoBody::setupParticles(System &system) {

    double pi = M_PI;
    
    Particle* Sun = new Particle(vec3(0,0,0), vec3(0,0,0), (1.99/5.974)*(1e6));
    Particle* Earth = new Particle(vec3(1,0,0), vec3(0,2*pi,0), 1.0);
    
    system.addParticle(Sun);
    system.addParticle(Earth);
}

std::string TwoBody::getName() {
    return "Two-body";
}
