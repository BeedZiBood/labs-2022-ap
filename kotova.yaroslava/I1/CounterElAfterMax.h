#ifndef COUNTERELAFTERMAX_H
#define COUNTERELAFTERMAX_H

struct CounterElAfterMax
{
  int maxval = 0;
  int count = 0;
  void operator()(int curr);
};
#endif
