#ifndef TWOBODY_H
#define TWOBODY_H

#pragma once
#include "initialcondition.h"
#include "particle.h"
#include <vector>
#include <string>


class TwoBody : public InitialCondition {
public:
    TwoBody() {}
    void setupParticles(class System& system);
    std::string getName();
};

#endif // TWOBODY_H
