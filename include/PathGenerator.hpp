#pragma once
#include <vector>

/**
 * @brief Path generator interface
 *
 * A class following this interface implements the logic for price series generation
 */
class PathGenerator {

public:
    /**
     * @brief virtual deconstructor
     */
    virtual ~PathGenerator() = default;

    /**
     * @brief generates a price path
     * @return A vector of doubles representing the asset price over time
     */
    virtual std::vector<double> generatePath(int numSteps) = 0;

    /**
     * @brief price generation for 1 time step
     */
    virtual double generatePrice() = 0;
};