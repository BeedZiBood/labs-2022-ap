#ifndef PRINTTABLE_HPP
#define PRINTTABLE_HPP
#include <cstddef>
#include <ostream>

void printTable(std::ostream& out, double abs_error, double step, double x_start, double x_end, size_t number_max);

#endif
