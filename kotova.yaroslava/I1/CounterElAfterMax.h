#ifndef COUNTERELAFTERMAX_H
#define COUNTERELAFTERMAX_H

struct CounterElAfterMax
{
  int maxchislo = 0;
  int count = 0;
  void operator()(int curr);
};
#endif
