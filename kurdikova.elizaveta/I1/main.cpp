#include <iostream>
#include "CounterLocalMin.h"
#include "CounterChanges.h"

int main()
{
  unsigned int countMin = 0;
  int checking = 0;
  int value = 0;
  int prevV = 0;
  unsigned int countSignChanges = 0;

  do {
    std::cin >> value;

    try {
      counterMin(countMin, prevV, value, checking);
      counterSignChanges(countSignChanges, prevV, value);
    } catch (const std::overflow_error& e) {
      std::cout << e.what() << '\n';
      return 1;
    }

    prevV = value;
  }
  while (value && std::cin);

  if (!std::cin) {
    std::cout << "Error...\n";
  }
  std::cout << "Number of local minimums: " << countMin << "\n";
  std::cout << "Number of sign changes: " << countSignChanges << "\n";
}
