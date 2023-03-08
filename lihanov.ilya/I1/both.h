#ifndef BOTH_H
#define BOTH_H
#include "localmax.h"
#include "equal_elements.h"

struct BothTasks
{
  LocalMax t1;
  Equal t2;
  void operator()(unsigned int currentValue)
  {
    t1(currentValue);
    t2(currentValue);
  }
};

#endif
