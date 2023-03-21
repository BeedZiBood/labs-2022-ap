#ifndef COUNTAFTERMAX_H
#define COUNTAFTERMAX_H

struct CountAfterMax
{
  int count_after_max = 0;
  int max_value = 0;

  void operator()(int value);
};

#endif
