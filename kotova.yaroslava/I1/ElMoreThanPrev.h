#ifndef ELMORETHANPREV_H
#define ELMORETHANPREV_H
struct ElMoreThanPrev
{
  int prev = 0;
  int count = 0;
  void operator()(int curr);
};
#endif
