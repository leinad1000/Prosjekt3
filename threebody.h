#ifndef THREEBODY_H
#define THREEBODY_H

#pragma once
#include "initialcondition.h"
#include "particle.h"
#include <vector>
#include <string>

class ThreeBody : public InitialCondition {
public:
    ThreeBody() {}
    void setupParticles(class System& system);
    std::string getName();
};

#endif // THREEBODY_H
