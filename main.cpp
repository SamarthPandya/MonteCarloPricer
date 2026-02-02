#include <iostream>
#include "Option.hpp"




int main() {

    Option* european_call = new EuropeanCall(200.0);

    std::cout << "Payoff at 205.32: " << european_call->payoff(205.32) << '\n';
    std::cout << "Payoff at 199: " << european_call->payoff(99.0);
}