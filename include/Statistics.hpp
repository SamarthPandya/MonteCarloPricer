#pragma once

class Statistics{
private:
    double sum;
    unsigned long long count;
    double sum_sq; // sum of squares

public:

    Statistics() : sum(0.0), count(0), sum_sq(0.0) {}

    void addDataPoint(double point);

    // outputs
    void getMean() const;       // mean of all data points
    void getStdError() const;   // standard error


};