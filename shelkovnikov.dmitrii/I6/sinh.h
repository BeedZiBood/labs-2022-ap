#ifndef SPBSPU_LABS_2022_AAP_904_A_SINH_H
#define SPBSPU_LABS_2022_AAP_904_A_SINH_H
#include <iostream>
double sinh(double x, double error, unsigned count);
void print_table(const std::ostream &out, double left, double right, double step, double error, unsigned k);
#endif
