#ifndef QUANTITYSIGNCHANGE_H
#define QUANTITYSIGNCHANGE_H

struct QuantitySignChange
{
  unsigned int sign_change = 0;
  int prev_val = 0;
  int before_prev_val = 0;

  void operator()(int current_val);
};

#endif
