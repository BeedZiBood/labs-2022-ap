#include "calculateAtanSum.h"

double calculateAtanSum(double x, double abs_error, size_t num_max)
{
    double numerator = x;
    double summation = x;
    int sign = 1;
    int num_summation = 1;
    double sum_res = 0;
    while (fabs(summation) > abs_error)
    {
        summation = sign * numerator / (2 * num_summation - 1);
        sum_res += summation;
        numerator *= x * x;
        sign = -sign;
        num_summation++;
    }
    return sum_res;
}
