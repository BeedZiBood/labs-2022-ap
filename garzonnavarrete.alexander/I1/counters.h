#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTERS_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTERS_H
struct CounterMoreNext
{
  unsigned int count;
  int prev;
  CounterMoreNext();
  void operator()(int next);
};
struct CounterDecreasing
{
  unsigned int count;
  unsigned int max_count;
  int prev;
  CounterDecreasing();
  void operator()(int next);
};
#endif
