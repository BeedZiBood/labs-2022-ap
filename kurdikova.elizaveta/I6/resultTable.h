#ifndef RESULTTABLE_H
#define RESULTTABLE_H
#include <cstddef>
#include <iosfwd>

void printTable(std::ostream& out, double left, double right, double step, size_t numberMax, double absError);

#endif
