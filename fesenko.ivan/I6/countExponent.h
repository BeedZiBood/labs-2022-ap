#ifndef COUNTEXPONENT_H
#define COUNTEXPONENT_H
double countExponent(double x, double absError, unsigned numberMax);

class ElementOfRow {
public:
  explicit ElementOfRow(double x);
  double operator()();

private:
  double x;
  unsigned factorial;
  unsigned number;
};
#endif
