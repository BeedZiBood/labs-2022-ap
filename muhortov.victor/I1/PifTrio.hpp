#ifndef PIFTRIO_HPP
#define PIFTRIO_HPP

struct FindPifTrio
{
  unsigned int PifCounter;
  int y, z;

  void operator()(int x);
};
#endif
