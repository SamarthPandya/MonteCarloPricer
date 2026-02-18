#include <pybind11/pybind11.h>
#include "PricerEngine.hpp"
#include "GBMPathGenerator.hpp"
#include "Option.hpp"
#include "Statistics.hpp"

namespace py = pybind11;

// Trampoline class for Option to allow overriding payoff in Python
class PyOption : public Option {
public:
    using Option::Option; // Inherit constructors
    double payoff(double finalPrice) const override {
        PYBIND11_OVERRIDE_PURE(
            double,      // Return type
            Option,      // Parent class
            payoff,      // Name of function in C++ (must match Python name)
            finalPrice   // Argument(s)
        );
    }
};

// Trampoline class for PathGenerator to allow custom generators in Python
class PyPathGenerator : public PathGenerator {
public:
    using PathGenerator::PathGenerator;
    double generatePrice() const override {
        PYBIND11_OVERRIDE_PURE(
            double,         // Return type
            PathGenerator,  // Parent class
            generatePrice,  // Name of function in C++
            // No arguments
            );
    }
};

PYBIND11_MODULE(monte_carlo_pricer, m) {
    m.doc() = "Monte Carlo Pricer C++ Extension";

    // Bind Statistics
    py::class_<Statistics>(m, "Statistics")
        .def(py::init<>())
        .def("getMean", &Statistics::getMean)
        .def("getVariance", &Statistics::getVariance)
        .def("getStdError", &Statistics::getStdError);

    // Bind Option with Trampoline
    py::class_<Option, PyOption>(m, "Option")
        .def(py::init<>())
        .def("payoff", &Option::payoff);

    py::class_<EuropeanCall, Option>(m, "EuropeanCall")
        .def(py::init<double>());

    py::class_<EuropeanPut, Option>(m, "EuropeanPut")
        .def(py::init<double>());

    // Bind PathGenerator with Trampoline
    py::class_<PathGenerator, PyPathGenerator>(m, "PathGenerator")
        .def(py::init<>())
        .def("generatePrice", &PathGenerator::generatePrice);

    py::class_<GBMPathGenerator, PathGenerator>(m, "GBMPathGenerator")
        .def(py::init<double, double, double, double>());

    // Bind PricerEngine
    py::class_<PricerEngine>(m, "PricerEngine")
        .def(py::init<double, double, unsigned long>())
        .def("runSimulation", &PricerEngine::runSimulation);
}