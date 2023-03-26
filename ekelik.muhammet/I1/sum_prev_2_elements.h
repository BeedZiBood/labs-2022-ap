#ifndef SUM_PREV_2_ELEMENTS_H
#define SUM_PREV_2_ELEMENTS_H

struct SumPrev2Elements
{
  int numEqualToSum = 0;

  void operator()(int prev1, int prev2, int current);
};

#endif
