#ifndef CHANGESIGNCOUNTER_HPP
#define CHANGESIGNCOUNTER_HPP

struct CountSignChanges
{
  unsigned int ChangeSignCounter;
  int y;

  void operator()(int x);
};
#endif
