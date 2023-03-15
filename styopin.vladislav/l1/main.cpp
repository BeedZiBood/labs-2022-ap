#include <iostream>
#include "Count.h"

int main()
{
  size_t counterMinimum = 0;
  size_t counterSignChanges = 0;
  int checking = 0;
  int value = 0;
  int previous_value = 0;

  do {
    std::cin >> value;

    try {
      countMin(counterMinimum, previous_value, value, checking);
      countSignChanges(counterSignChanges, previous_value, value);
    } catch (const std::overflow_error& e) {
      std::cout << e.what() << '\n';
      return 1;
    }

    previous_value = value;
  }
  while (value && std::cin);

  if (!std::cin) {
    std::cout << "Error...\n";
  }
  std::cout << "Number of local minimums: " << counterMinimum << "\n";
  std::cout << "Number of sign changes: " << counterSignChanges << "\n";
}
