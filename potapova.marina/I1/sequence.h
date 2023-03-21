#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <cstddef>
struct CounterPythagoreanTriplets {
  void operator()(int currval);
  int predval;
  int predpredval;
  size_t count;
};

struct CounterSignChange {
  void operator()(int currval);
  int predval;
  size_t count;
};
#endif
