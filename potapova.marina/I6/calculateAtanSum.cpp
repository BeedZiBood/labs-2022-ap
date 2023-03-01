#include <cmath>
#include <stdexcept>
#include "calculateAtanSum.h"

double calculateAtanSum(double x, double abs_error, size_t num_max)
{
    if (fabs(x) > 1)
    {
        throw std::domain_error("Wrong x interval");
    }
    double numerator = x;
    double summation = x;
    int sign = 1;
    size_t num_summation = 1;
    double sum_res = 0;
    while (fabs(summation) > abs_error)
    {
        if (num_summation > num_max)
        {
            throw std::logic_error("The num_summation doesn't converge");
        }
        summation = sign * numerator / (2 * num_summation - 1);
        sum_res += summation;
        numerator *= x * x;
        sign = -sign;
        num_summation++;
    }
    return sum_res;
}
