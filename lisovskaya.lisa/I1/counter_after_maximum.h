#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTER_AFTER_MAXIMUM_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTER_AFTER_MAXIMUM_H
struct CounterAfterMaximum
{
  unsigned int count;
  int max;
  void operator()(int next);
};
#endif
