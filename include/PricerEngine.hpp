#pragma once
#include "Option.hpp"
#include "PathGenerator.hpp"
#include "Statistics.hpp"

/**
 * @brief blueprint for the class that runs the simulation
 */
class PricerEngine {

private:
    double r;               // risk free rate
    double T;               // time to maturity in years
    unsigned long paths;    // number of Monte Carlo Iterations

public:


    PricerEngine(double riskFreeRate, double timeToExpiry, unsigned long numPaths);

    /**
     * @brief starting point of simulations
     * @param model model which to use for generating Monte Carlo simulation
     */
    Statistics runSimulation(PathGenerator& model, Option& product) const;

};