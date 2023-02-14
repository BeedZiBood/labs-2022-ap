#ifndef CALCULATEATANSUM_H
#define CALCULATEATANSUM_H

#include <cstddef>

double calculateAtanSum(double x, double abs_error, size_t num_max);
void printTable(double abs_error, size_t num_max, double start,
                double end, double step);

#endif
