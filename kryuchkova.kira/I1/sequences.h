#ifndef SEQUENCES_H
#define SEQUENCES_H

struct MaxCounter
{
  int max;
  unsigned int count_max;

  MaxCounter();
  void operator()(int current_value);
};

struct MinCounter
{
  int min;
  unsigned int count_min;

  MinCounter();
  void operator()(int current_value);
};

#endif
