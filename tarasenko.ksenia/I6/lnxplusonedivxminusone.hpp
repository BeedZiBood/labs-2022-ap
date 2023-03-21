#ifndef LNXPLUSONEDIVXMINUSONE_HPP
#define LNXPLUSONEDIVXMINUSONE_HPP

class LnXPlusOneDivXMinusOne
{
  public:
   explicit LnXPlusOneDivXMinusOne(double x);
   double operator()();
  private:
   double x_;
   double x0_;
   double member_;
   unsigned number_;
};

#endif
