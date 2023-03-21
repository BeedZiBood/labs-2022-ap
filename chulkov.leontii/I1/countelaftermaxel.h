#ifndef COUNTELAFTERMAXEL_H
#define COUNTELAFTERMAXEL_H

struct CountElAfterMaxEl
{
  int max;
  unsigned count;
  void operator()(int el);
};
#endif
