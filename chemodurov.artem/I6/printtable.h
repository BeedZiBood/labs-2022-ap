#ifndef PRINTTABLE_H
#define PRINTTABLE_H
#include <cstddef>
#include <iosfwd>

namespace chemodurov
{
  void printTable(std::ostream & out, double left, double right, double step, size_t max_members, double error);
}

#endif
