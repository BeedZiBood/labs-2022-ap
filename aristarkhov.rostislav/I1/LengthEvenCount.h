#ifndef LENGTHEVENCOUNT_H
#define LENGTHEVENCOUNT_H

struct LenEvenCounter
{
  unsigned count_even;
  unsigned count_len_even;

  void operator()(int curr_val);
};

#endif
