#pragma once
#include "PathGenerator.hpp"
#include <random>

/**
 * @brief Concrete implementation of GBM (Geometric Brownian Motion)
 * This class handles the stochastic math for the simulation.
 */
class GBMPathGenerator : public PathGenerator {
private:
    double S;      // Spot Price
    double r;      // Risk-free rate
    double sigma;  // Volatility
    double T;      // Time to maturity

    // 'mutable' allows these to change inside the const generatePrice() method
    mutable std::mt19937 gen;
    mutable std::normal_distribution<double> dist;

public:

    /**
     * @brief Constructor to initialize market parameters
     */
    GBMPathGenerator(double spot, double rate, double vol, double time);


    /**
     * @brief Destructor marked noexcept to match the interface and prevent crashes
     */
    virtual ~GBMPathGenerator() noexcept override = default;


    /**
     * @brief The core GBM math for a single price point
     */
    double generatePrice() const override;
};