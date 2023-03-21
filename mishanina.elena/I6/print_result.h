#ifndef PRINT_RESULT_H
#define PRINT_RESULT_H
#include <iosfwd>
#include <iomanip>
#include <cmath>
#include "sqr_one_minus_x_to_power_of_minus_zero_point_five.h"

void printResult(std::ostream& out, double x, unsigned members, double error);

#endif
