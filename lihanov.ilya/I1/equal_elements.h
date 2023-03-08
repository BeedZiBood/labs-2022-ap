#ifndef EQUAL_ELEMENTS_H
#define EQUAL_ELEMENTS_H

struct Equal
{
  void operator()(unsigned int currentValue);
  unsigned int previousValue;
  unsigned int beforePreviousValue;
  unsigned int countV;
};

#endif

