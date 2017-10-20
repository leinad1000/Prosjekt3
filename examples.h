#ifndef EXAMPLES_H
#define EXAMPLES_H

#pragma once

class Examples {
public:
    static void twoBodyProblem(double GM, double delta_t, int n);
    static void threeBodyProblem(double GM, double delta_t, int n);
    static void tenBodyProblem(double GM, double delta_t, int n);
    static void perihelion(double GM, double delta_t, int n, double T);
};

#endif // EXAMPLES_H

