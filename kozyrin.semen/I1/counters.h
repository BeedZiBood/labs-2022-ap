#ifndef COUNTERS_H
#define COUNTERS_H

struct dividendCounter {
  unsigned int cnt;
  int prev;
  void operator()(int num);
};

struct equalToSumCounter {
  unsigned int cnt;
  int prev[2];
  void operator()(int num);
};

#endif
