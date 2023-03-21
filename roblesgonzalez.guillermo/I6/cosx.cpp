#include "cosx.h"
#include <cmath>
#include <stdexcept>
double cosx(double x, double error, unsigned int cos_members)
{
    double result = 1.0;
    double term = 1.0;
    double termError = 1.0;
    unsigned int n = 1;
    while (n < cos_members && termError > error)
    {
        term *= -x * x / (2 * n - 1) / (2 * n);
        result += term;
        termError = std::fabs(term / result);
        n++;
    }
    if (n > cos_members || termError > error || std::isnan(result))
    {
        throw std::runtime_error("Failed to converge to the desired accuracy ");
    }
    return result;
}
