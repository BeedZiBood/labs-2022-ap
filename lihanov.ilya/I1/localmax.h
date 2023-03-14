
#ifndef LOCALMAX_H
#define LOCALMAX_H

struct LocalMax
{
  void operator()(unsigned int currentValue);

  unsigned int previousValue;
  unsigned int beforePreviousValue;
  unsigned int count;
};

#endif
