#ifndef PRINTTABLE_H
#define PRINTTABLE_H

#include <cstddef>
#include <ostream>

void printTable(std::ostream& out, double absError, double mStep, double m1, double m2, size_t maxNumber);

#endif
