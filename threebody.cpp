#include "threebody.h"
#include "vec3.h"
#include "system.h"
#include <cmath>


void ThreeBody::setupParticles(System &system) {
    
    double pi = M_PI;
    double dager = 365.2522;
    
    // Get initial conditions from NASA's public service. Data below are as of october 12th, 2017.
    Particle* Sun = new Particle(vec3(2.249742341967526E-03,5.702259020296952E-03,-1.308868418264601E-04), dager * vec3(-5.176331796449613E-06,5.522815922934838E-06,1.208552996089031E-07), (1.99/5.974)*(1e6));
    Particle* Earth = new Particle(vec3(9.480957405756560E-01,3.242804441221033E-01,-1.465820905998789E-04), dager * vec3(-5.777303447041140E-03,1.624711177600315E-02,-5.327530311212426E-07), 1.0);
    Particle* Jupiter = new Particle(vec3(-4.604440597510837,-2.891007523243876,1.149787438139007E-01), dager * vec3(3.925073055856761E-03,-6.032031115361013E-03,-6.270510562667993E-05), (1.9/5.974)*(1e3));
    
    system.addParticle(Sun);
    system.addParticle(Earth);
    system.addParticle(Jupiter);
}

std::string ThreeBody::getName() {
    return "Three-body";
}
