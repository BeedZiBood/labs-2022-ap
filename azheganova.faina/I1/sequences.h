#ifndef SEQUENCES_H
#define SEQUENCES_H

struct Localminimals
{
  Localminimals();
  unsigned int countlocalmin;
  int current;
  int next;
  void operator()(int previous);
};

struct Minsrmax
{
  Minsrmax();
  unsigned int countofsequenceelements;
  unsigned int countminsrmax;
  int current;
  int next;
  void operator()(int previous);
};
#endif
