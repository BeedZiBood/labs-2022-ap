#ifndef COUNTER_HPP
#define COUNTER_HPP

namespace zasulsky {
  struct SecondLargestFinder {
    int secondLargestVal;
    int largestVal;
    SecondLargestFinder();
    void operator()(int val);
  };
  struct FibonacciCounter {
    unsigned count;
    int lastVal;
    int curVal;
    FibonacciCounter();
    void operator()(int val);
  };
}

#endif
