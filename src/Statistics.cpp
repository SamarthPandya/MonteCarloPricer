#include "Statistics.hpp"
#include <cmath>


/**
 * @brief std error = (variace / count)^(1/2)
 */
double Statistics::getStdError() const {

    return sqrt(getVariance() / static_cast<double>(count));

}