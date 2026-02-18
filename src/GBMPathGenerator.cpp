#include "GBMPathGenerator.hpp"

GBMPathGenerator::GBMPathGenerator(double spot, double rate, double vol, double time) :
    S(spot), r(rate), sigma(vol), T(time), gen(std::random_device{}()), dist(0.0, 1.0) {
}


double GBMPathGenerator::generatePrice() const {

    double drift = (r - 0.5 * sigma * sigma) * T;
    double diffusion = sigma * std::sqrt(T) * dist(gen);

    return S * std::exp(drift + diffusion);
}