#ifndef COUNTLARG_H
#define COUNTLARG_H

struct CountLargest
{
  int largest_val;
  unsigned count_amount;

  void operator()(int curr_val);
};

#endif
