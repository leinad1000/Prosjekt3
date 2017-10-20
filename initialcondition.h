#ifndef INITIALCONDITION_H
#define INITIALCONDITION_H

#pragma once
#include <vector>
#include <string>
#include "particle.h"

class InitialCondition {
public:
    InitialCondition() {}
    virtual void setupParticles(class System& system) = 0;
    virtual std::string getName();
};

#endif // INITIALCONDITION_H
