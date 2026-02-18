cmake_minimum_required(VERSION 3.14)
project(MonteCarloPricer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Shared Source files
set(SOURCES
    src/Statistics.cpp
    src/GBMPathGenerator.cpp
    src/PricerEngine.cpp
)

# 1. Build the C++ Executable (Original functionality)
add_executable(MonteCarloPricer main.cpp ${SOURCES})

# 2. Build the Python Extension
# Fetch pybind11 automatically
include(FetchContent)
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG        v2.11.1
)
FetchContent_MakeAvailable(pybind11)

# Create the python module "monte_carlo_pricer"
pybind11_add_module(monte_carlo_pricer src/bindings.cpp ${SOURCES})

# 3. Tests
enable_testing()
add_executable(test_math tests/test_math.cpp ${SOURCES})
add_test(NAME test_math COMMAND test_math)