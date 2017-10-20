#ifndef NEWTONIANGRAVITY_H
#define NEWTONIANGRAVITY_H

#pragma once
#include "particle.h"
#include "potential.h"
#include <string>

class NewtonianGravity : public Potential {
private:
    double m_G;

public:
    NewtonianGravity(double MG);
    void computeForces(Particle& a, Particle& b);
    std::string getName();
};

#endif // NEWTONIANGRAVITY_H

