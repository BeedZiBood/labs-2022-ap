#include "sequence.h"
#include <iostream>
int main() {
  CounterPythagoreanTriplets pythcnt{0, 0, 0};
  CounterSignChange signchangecnt{0, 0};
  int currval = 0;
  do {
    std::cin >> currval;
    if (!std::cin){
      std::cout << "Error...\n";
      return 1;
    }
    pythcnt(currval);
    signchangecnt(currval);
  } while (std::cin && currval);
  std::cout << pythcnt.count << "\n";
  std::cout << signchangecnt.count << "\n";
  return 0;
}
