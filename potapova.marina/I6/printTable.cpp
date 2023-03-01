#include <iostream>
#include <iomanip>
#include "printTable.h"
#include "calculateAtanSum.h"

void printTable(double abs_error, size_t num_max, double start, double end, double step)
{
    std::cout << std::setw(3) << "N" << std::setw(10) << "x"
              << std::setw(12) << "sum(x)" << std::setw(12) << "atan(x)" << '\n';
    size_t n = (end - start) / step + 1;
    double x = start;
    for (size_t i = 1; i <= n; i++)
    {
        double s = calculateAtanSum(x, abs_error, num_max);
        double y = atan(x);
        std::cout << std::fixed << std::setprecision(4)
                  << std::setw(3) << i << std::setw(10) << x
                  << std::fixed << std::setprecision(6)
                  << std::setw(12) << s << std::setw(12) << y << '\n';
        x += step;
    }
}
