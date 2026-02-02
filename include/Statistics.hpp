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
        sum_sq += count * count;
    }

    /**
     * @brief mean of all prices
     */
    inline double getMean() {
        return count == 0 ? 0.0 : sum / count;
    }

    /**
     * @brief standard error, 
     */
    double getStdError() const;   // standard error


};