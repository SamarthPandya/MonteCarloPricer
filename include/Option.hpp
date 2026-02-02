#pragma once
#include <algorithm>



/**
 * @brief Option interface
 */
class Option {
public:

    /**
     * @brief virtual deconstructor to ensure that the derived class is cleaned up
     * when a pointer to Option is deleted
     */
    virtual ~Option() = default;

    /**
     * @brief virtual function for payoff, any child must implement internal logic
     * @param finalPrice The asset price at maturity (S_T)
     * @return the value of the option
     */
    virtual double payoff(double finalPrice) const = 0;
};

/**
 * @brief European call option
 * payoff = max(S - k, 0) :
 */
class EuropeanCall : public Option {
private:
    double strike;
public:
    explicit EuropeanCall(double K) : strike(K) {}
    double payoff(double S) const override {
        return std::max(S - strike, 0.0);
    }
};

/**
 * @brief European put option
 * payoff = max(K - S, 0)
 */
class EuropeanPut : public Option {
private:
    double strike;
public:
    explicit EuropeanPut(double K) : strike(K) {}
    double payoff(double S) const override {
        return std::max(strike - S, 0.0);
    }
};