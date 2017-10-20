#ifndef TENBODY_H
#define TENBODY_H

#pragma once
#include "initialcondition.h"
#include "particle.h"
#include <vector>
#include <string>

class TenBody : public InitialCondition {
public:
    TenBody() {}
    void setupParticles(class System& system);
    std::string getName();
};

#endif // TENBODY_H
