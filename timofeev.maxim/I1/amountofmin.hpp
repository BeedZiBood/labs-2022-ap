#ifndef AMOUNTOFMIN_HPP
#define AMOUNTOFMIN_HPP

struct MinValue
{
  int min;
  unsigned int counter;

  void operator()(int value);
};

#endif

