#ifndef SHENANIGANS_H
#define SHENANIGANS_H
#include <iostream>
#include <cmath>

struct term1 {
public:
  explicit term1(double x);
  double operator()();
private:
  double x_;
  double value_;
  size_t index_;
};

struct term2 {
public:
  term2(double x, double value);
  double operator()();
private:
  double x_;
  double value_;
  size_t index_;
};

double getCustomCos(double x, double error, size_t maxNum);
double getCustomArth(double x, double error, size_t maxNum);

void printTable(std::ostream& stream, double lb, double rb, double error, size_t maxNum, double step);

#endif
