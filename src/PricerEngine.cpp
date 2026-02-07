#include "PricerEngine.hpp"
#include <cmath>

PricerEngine::PricerEngine(double riskFreeRate, double timeToExpiry, unsigned long numPaths) :
    r(riskFreeRate), T(timeToExpiry), paths(numPaths) {
}

Statistics PricerEngine::runSimulation(PathGenerator& model, Option& product) const {

    Statistics stats;

    for (unsigned long i = 1; i <= paths; i++) {

        double spotAtMaturity = model.generatePrice();

        double payOff = product.payoff(spotAtMaturity);

        stats.addPrice(payOff);

    }

    return stats;
}