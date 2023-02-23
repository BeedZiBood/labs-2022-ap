#ifndef PRINTTABLE_H
#define PRINTTABLE_H

#include <iostream>
#include <iomanip>
#include <cstddef>

void printTableRow(std::ostream& out, double x, double taylor, double actual);
void printTable(std::ostream& out, double step, double x_start, double x_end, size_t number_max, double abs_error);

#endif
