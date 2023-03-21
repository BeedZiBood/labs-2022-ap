#ifndef PRINTROW_H
#define PRINTROW_H
#include <iosfwd>

void printTable(std::ostream & out, double borderleft, double borderright, double step, unsigned maxnumber, double absError);
#endif
