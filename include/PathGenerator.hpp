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
    virtual ~PathGenerator() noexcept = default;



    /**
     * @brief price generation for 1 time step
     * @return new price after one time step
     */
    virtual double generatePrice() const = 0;
};