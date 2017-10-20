#include "newtoniangravity.h"
#include <iostream>
#include <cmath>

using namespace std;

NewtonianGravity::NewtonianGravity(double GM) : m_G(GM) {

}

void NewtonianGravity::computeForces(Particle& a, Particle& b) {
    double M_sun = (1.99/5.974)*(1e6); // Relative to Earth
    double F, Fx, Fy, Fz, phi, V, c, l;
    double pi = M_PI;

    vec3 relative_position = b.getPosition() - a.getPosition();

    //Changing the gravitational law to non-sense
    //F = (m_G*(a.getMass()*b.getMass())/M_sun)/pow(relative_position.lengthSquared(),3.0/2.0);

    F = (m_G*(a.getMass()*b.getMass())/M_sun)/relative_position.lengthSquared();

    //Changing the gravitational law for the perihelion precession of Mercury
    l = ( relative_position.cross(b.getVelocity()) ).length();
    c = ((3*365.2522*24*3600)/1.496)*(1e-3);
    F *= (1 + (3*l*l)/(relative_position.lengthSquared()*c*c));

    phi = atan((relative_position[2])/relative_position.lengthProjected());
    Fx = (F*(relative_position[0])*cos(phi))/relative_position.lengthProjected();
    Fy = (F*(relative_position[1])*cos(phi))/relative_position.lengthProjected();
    Fz = F*sin(phi);
    V = -F*relative_position.length(); // Calculating the potential energy

    // Adding forces and potential energy
    a.addForce(Fx,Fy,Fz);
    b.addForce(-Fx,-Fy,-Fz);
    m_potentialEnergy += V;

    
}

std::string NewtonianGravity::getName() {
    return "Newtonian gravity";
}
