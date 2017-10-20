#include "examples.h"
#include "system.h"
#include "particle.h"
#include "eulercromer.h"
#include "velocityverlet.h"
#include "newtoniangravity.h"
//#include "nopotential.h"
#include "twobody.h"
#include "threebody.h"
#include "tenbody.h"
#include <iostream>
#include <cmath>
#include "perihelion.h"


void Examples::twoBodyProblem(double GM, double delta_t, int n) {
    
    System* twoBodySystem = new System();
    twoBodySystem->setIntegrator        (new VelocityVerlet(twoBodySystem));
    twoBodySystem->setPotential         (new NewtonianGravity(GM));
    twoBodySystem->setInitialCondition  (new TwoBody());
    twoBodySystem->setDt                (delta_t);
    twoBodySystem->setFileWriting       (true);
    //twoBodySystem->removeLinearMomentum (); // The Sun is fixed
    twoBodySystem->integrate            (n);
}

void Examples::threeBodyProblem(double GM, double delta_t, int n) {
    System* threeBodySystem = new System();
    threeBodySystem->setIntegrator        (new VelocityVerlet(threeBodySystem));
    threeBodySystem->setPotential         (new NewtonianGravity(GM));
    threeBodySystem->setInitialCondition  (new ThreeBody());
    threeBodySystem->setDt                (delta_t);
    threeBodySystem->setFileWriting       (true);
    threeBodySystem->removeLinearMomentum (); // Comment out this line when the Sun is supposed to fixed
    threeBodySystem->integrate            (n);
}

void Examples::tenBodyProblem(double GM, double delta_t, int n) {
    System* tenBodySystem = new System();
    tenBodySystem->setIntegrator(new VelocityVerlet(tenBodySystem));
    tenBodySystem->setPotential(new NewtonianGravity(GM));
    tenBodySystem->setInitialCondition(new TenBody());
    tenBodySystem->setDt(delta_t);
    tenBodySystem->setFileWriting(true);
    tenBodySystem->removeLinearMomentum();
    tenBodySystem->integrate(n);
}

void Examples::perihelion(double GM, double delta_t, int n, double T) {
    System* perihelion = new System(n,T);
    perihelion->setIntegrator(new VelocityVerlet(perihelion));
    perihelion->setPotential(new NewtonianGravity(GM));
    perihelion->setInitialCondition(new Perihelion());
    perihelion->setDt(delta_t);
    perihelion->setFileWriting(true);
    perihelion->removeLinearMomentum();
    perihelion->integrate(n);
}
