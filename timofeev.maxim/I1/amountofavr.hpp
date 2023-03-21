#ifndef AMOUNTOFAVR_HPP
#define AMOUNTIFAVR_HPP

struct Average
{
  int curval = 0;
  int avg = 0;
  int bef = 0;
  unsigned int counter1 = 0;

  void operator()(int value);
};

#endif
