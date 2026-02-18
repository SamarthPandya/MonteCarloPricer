# Monte Carlo Pricer

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com/samarthpandya134/MonteCarloPricer)

A high-performance Monte Carlo pricing engine for financial derivatives, written in C++ with an elegant Python interface provided by `pybind11`.

This project provides a flexible framework for pricing options by simulating the underlying asset's price path. The core engine is implemented in modern C++ for speed, while `pybind11` provides a simple and intuitive Python API for scripting, integration, and analysis.

## Features

- **High-Performance C++ Core:** The simulation and pricing logic is written in C++17 for maximum performance.
- **Clean Python API:** Easily interact with the pricing engine from Python for quick prototyping and analysis.
- **Extensible Design:**
  - Implement new path generators for different stochastic processes.
  - Define custom payoff functions for various exotic options.
- **Geometric Brownian Motion (GBM):** Includes a path generator for GBM, a standard model for stock prices.
- **European Options:** Comes with a `EuropeanCall` payoff function as an example.
- **Statistical Analysis:** The engine automatically computes the mean and standard error of the simulation results.

## Requirements

- A C++17 compatible compiler (e.g., GCC, Clang, MSVC)
- CMake (version 3.12+)
- Python (version 3.6+)
- `pybind11` (handled automatically by CMake's `FetchContent`)

## Build Instructions

To build the project, follow these steps from the root directory:

```bash
# 1. Clone the repository (if you haven't already)
git clone https://github.com/your-username/MonteCarloPricer.git
cd MonteCarloPricer

# 2. Create a build directory
mkdir build
cd build

# 3. Configure the project with CMake
cmake ..

# 4. Build the project
make
```

This will create a Python module (e.g., `monte_carlo_pricer.so` on Linux or `monte_carlo_pricer.pyd` on Windows) in your build directory.

## Usage

You can use the compiled module directly in Python. The following example demonstrates how to price a European call option.

### Example: Pricing a European Call Option

The script below (`test.py`) shows a complete example of setting up the parameters, running the simulation, and printing the results.

```python
import monte_carlo_pricer as mcp
import math

# 1. Setup Parameters
spot = 100.0
strike = 105.0
expiry = 1.0      # 1 year
vol = 0.2         # 20%
risk_free = 0.05  # 5%
paths = 10000

# 2. Initialize the C++ Components
path_gen = mcp.GBMPathGenerator(spot, risk_free, vol, expiry)
call_option = mcp.EuropeanCall(strike)

# 3. Setup Engine
engine = mcp.PricerEngine(risk_free, expiry, paths)

# 4. Run Simulation
stats = engine.runSimulation(path_gen, call_option)

print(f"Option Price: {stats.getMean():.4f}")
print(f"Std Error:    {stats.getStdError():.4f}")
```

### Running the Example

Make sure the compiled module is in your `PYTHONPATH` or simply run the script from the `build` directory.

```bash
cd build
python ../test.py
```

### Example Output

The output will be similar to this (due to the stochastic nature of the simulation, the exact numbers will vary slightly):

```
Option Price: 8.0169
Std Error:    0.1381
```

## Project Components

- **`GBMPathGenerator`**: Generates paths for an asset following Geometric Brownian Motion.
- **`EuropeanCall`**: Calculates the payoff for a European call option at expiry.
- **`PricerEngine`**: The main engine that runs the simulation. It takes a path generator and a payoff function, simulates multiple paths, and computes statistics on the discounted payoffs.
- **`Statistics`**: A simple class to gather statistics (mean, standard error) from the simulation.