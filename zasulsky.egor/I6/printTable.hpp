#ifndef PRINTTABLE_HPP
#define PRINTTABLE_HPP
#include <iosfwd>

namespace zasulsky
{
  void printTable(std::ostream& out, double l, double r, double step, double absError, unsigned numberMax);
}

#endif
