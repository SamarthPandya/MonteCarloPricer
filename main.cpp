#include <iostream>
#include "Option.hpp"
#include <iomanip> // For std::fixed and std::setprecision
#include "GBMPathGenerator.hpp"
#include "PricerEngine.hpp"

int main() {
    // 1. Define Parameters
    double spot = 100.0;
    double strike = 105.0;
    double r = 0.05;
    double vol = 0.2;
    double T = 1.0;
    unsigned long paths = 100000;

    // 2. Instantiate Objects
    EuropeanCall the_call(strike);
    GBMPathGenerator the_model(spot, r, vol, T);
    PricerEngine the_engine(r, T, paths);

    // 3. Run the Simulation
    Statistics results = the_engine.runSimulation(the_model, the_call);

    std::cout << std::fixed << std::setprecision(4);

    // 4. Display Results
    std::cout << "European Call Option Price" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Spot:       " << spot << std::endl;
    std::cout << "Strike:     " << strike << std::endl;
    std::cout << "Rate:       " << r << std::endl;
    std::cout << "Volatility: " << vol << std::endl;
    std::cout << "Maturity:   " << T << " year(s)" << std::endl;
    std::cout << "Paths:      " << paths << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Price:      " << results.getMean() << std::endl;
    std::cout << "Std Error:  " << results.getStdError() << std::endl;
    std::cout << "--------------------------" << std::endl;

    return 0;
}