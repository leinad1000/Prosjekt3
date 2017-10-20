#ifndef PERIHELION_H
#define PERIHELION_H

#pragma once
#include "initialcondition.h"
#include <string>

class Perihelion : public InitialCondition {
public:
    Perihelion() {}
    void setupParticles(class System& system);
    std::string getName();
};

#endif // PERIHELION_H
