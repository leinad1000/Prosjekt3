#ifndef SYSTEM_H
#define SYSTEM_H

#pragma once
#include "particle.h"
#include <vector>
#include <fstream>
#include <cmath>

class System {
private:
    bool                        m_writeToFile       = false;
    bool                        m_outFileOpen       = false;
    bool                        m_outFileOpen2      = false;
    int                         m_integrateSteps    = 0;
    int                         m_nTimeSteps        = 0;
    int                         m_numberOfParticles = 0;
    int                         m_revolutions       = 1;
    int                         m_i_one_round       = 0;
    double                      m_avstand           = 1.0;
    double                      m_orbital_period_mercury = 87.969257;
    double                      m_days              = 0;
    double                      m_rounds            = 0;
    double                      m_data_points_per_round = 0;
    double                      m_theta_p           = 0;
    double                      m_x_p               = 0;
    double                      m_y_p               = 0;
    double                      m_pi                = M_PI;
    double                      m_T                 = 0;
    double                      m_momentum          = 0;
    double                      m_kineticEnergy     = 0;
    double                      m_totalEnergy       = 0;
    double                      m_potentialEnergy   = 0;
    class Integrator*           m_integrator        = nullptr;
    class Potential*            m_potential         = nullptr;
    class InitialCondition*     m_initialCondition  = nullptr;
    std::ofstream               m_outFile;
    std::ofstream               m_outFile2;
    std::vector<Particle*>      m_particles;

public:
    System(int n, double T);
    System() {}
    void computeForces          ();
    void resetAllForces         ();
    void setPotential           (class Potential* potential);
    void setIntegrator          (class Integrator* integrator);
    void setInitialCondition    (class InitialCondition* initialCondition);
    void setDt                  (double dt);
    void integrate              (int numberOfSteps);
    void addParticle            (Particle* p);
    void printIntegrateInfo     (int stepNumber);
    void removeLinearMomentum   ();
    void setFileWriting         (bool writeToFile);
    void writePositionsToFile   ();
    void closeOutFile           ();
    void perihelion             (int stepNumber);
    double computeKineticEnergy ();
    double computeMomentum      ();
};

#endif // SYSTEM_H
