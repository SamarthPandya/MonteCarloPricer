# Monte Carlo Pricer

A high-performance C++ engine designed to price financial derivatives using Monte Carlo simulation. This project demonstrates a modular architecture, separating financial payoffs from stochastic path generation and statistical analysis.


## Project Structure

The project follows the **Standard C++ Project Layout** to ensure modularity, fast compilation, and clean separation of concerns.

```text
MonteCarloPricer/
├── CMakeLists.txt                  # Build system configuration
├── include/                        # Header Files (The "What")
│   ├── Option.hpp                  # Abstract base for payoffs (Call, Put, etc.)
│   ├── PathGenerator.hpp           # Stochastic modeling logic
│   ├── Statistics.hpp              # Statistics gatherer declaration
│   ├── GBMPathGenerator.hpp        # Specific Stochastic Model: GBM
│   └── PricerEngine.hpp            # Orchestration & Simulation logic
|   
├── src/                            # Source Files
│   ├── Statistics.cpp              # Implementation of running statistical tallies
│   ├── GBMPathGenerator.cpp        # Implementation of GBM
│   └── PricerEngine.cpp            # Loop execution and discounting logic
├── tests/                          # Validation
│   └── test_math.cpp               # Unit tests against Black-Scholes
└── main.cpp                        # Execution entry point and demo