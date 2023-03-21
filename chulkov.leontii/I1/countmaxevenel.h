#ifndef COUNTMAXEVENEL_H
#define COUNTMAXEVENEL_H

struct CountMaxEvenEl
{
  unsigned maxEvenCount;
  unsigned evenCount;
  void operator()(int el);
};
#endif
