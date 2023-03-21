#ifndef QUANTITYLOCALMIN_H
#define QUANTITYLOCALMIN_H

struct QuantityLocalMin
{
  unsigned int local_min = 0;
  int prev_val = 0;
  int before_prev_val = 0;

  void operator()(int current_val);
};

#endif
