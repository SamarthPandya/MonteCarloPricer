#include <iostream>
#include <cmath>
#include <cassert>
#include "PricerEngine.hpp"
#include "Option.hpp"
#include "GBMPathGenerator.hpp"

// Standard Black-Scholes for a Call to act as the "Ground Truth"
double blackScholesCall(double S, double K, double r, double sigma, double T) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    // Using standard normal cumulative distribution
    auto N = [](double x) { return 0.5 * std::erfc(-x * std::sqrt(0.5)); };

    return S * N(d1) - K * std::exp(-r * T) * N(d2);
}

int main() {
    // Parameters
    double S = 100.0, K = 100.0, r = 0.05, v = 0.2, T = 1.0;

    // Run MC with enough paths for convergence
    GBMPathGenerator model(S, r, v, T);
    EuropeanCall product(K);
    PricerEngine engine(r, T, 1000000);

    double mcPrice = engine.runSimulation(model, product).getMean();
    double bsPrice = blackScholesCall(S, K, r, v, T);

    std::cout << "Testing Convergence..." << std::endl;
    std::cout << "MC: " << mcPrice << " | BS: " << bsPrice << std::endl;

    // Professional check: Is the error less than 0.1%?
    if (std::abs(mcPrice - bsPrice) < 0.1) {
        std::cout << "TEST PASSED: Simulation converged." << std::endl;
    }
    else {
        std::cout << "TEST FAILED: Check math or path count." << std::endl;
    }

    return 0;
}