#pragma once

class Statistics {
private:
    double sum;
    unsigned long long count;
    double sum_sq; // sum of squares

public:

    Statistics() : sum(0.0), count(0), sum_sq(0.0) {}

    // note: addPrice and getMean are kept inline as they are frequently called and are simple.

    /**
     * @brief adds data price inline, we provide definition since this behaviour largely
     * remains the same
     *
     * @param price new price point to add
     */
    inline void addPrice(double price) {
        sum += price;
        count++;
        sum_sq += price * price;
    }


    /**
     * @brief mean of all prices
     */
    inline double getMean() const {
        return count == 0 ? 0.0 : sum / static_cast<double>(count);
    }


    /**
     * @brief variance of all prices
     */
    inline double getVariance() const {

        if (count <= 1) {
            return 0.0;
        }

        double mean = getMean();
        return (sum_sq / static_cast<double>(count)) - (mean * mean);

    }


    /**
     * @brief standard error
     */
    double getStdError() const;   // standard error


};