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
     * @param finalPrice asset price at maturity (S_T)
     * @return value of the option
     */
    virtual double payoff(double finalPrice) const = 0;
};


/**
 * @brief european call option
 * payoff = max(S - k, 0) :
 */
class EuropeanCall : public Option {
private:
    double strikePrice;
public:
    explicit EuropeanCall(double K) : strikePrice(K) {}


    double payoff(double spotPrice) const override {
        return std::max(spotPrice - strikePrice, 0.0);
    }
};


/**
 * @brief european put option
 * payoff = max(K - S, 0)
 */
class EuropeanPut : public Option {
private:
    double strikePrice;
public:
    explicit EuropeanPut(double K) : strikePrice(K) {}
    double payoff(double spotPrice) const override {
        return std::max(strikePrice - spotPrice, 0.0);
    }
};