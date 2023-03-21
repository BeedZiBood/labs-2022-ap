#ifndef ARCCOS_H
#define ARCCOS_H

double countArccos(double x, double absError, unsigned maxnumber);

class findMemberOfRow
{
  public:
    explicit findMemberOfRow(double x);
    double operator()();
  private:
    double x;
    unsigned factorialinnumerator;
    unsigned number;
    unsigned factorialindeminator;
    unsigned countmembers;
};
#endif
