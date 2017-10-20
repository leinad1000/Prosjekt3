#include "perihelion.h"
#include "vec3.h"
#include "system.h"
#include <cmath>


void Perihelion::setupParticles(System &system) {

    double pi = M_PI;
    double dager = 365.2522;

    Particle* Sun = new Particle(vec3(0,0,0), vec3(0,0,0), (1.99/5.974)*(1e6));
    Particle* Mercury = new Particle(vec3(0.3075,0,0), vec3(0,12.44,0), 0.0549882826);

    system.addParticle(Sun);
    system.addParticle(Mercury);
}

std::string Perihelion::getName() {
    return "Perihelion-precession";
}
