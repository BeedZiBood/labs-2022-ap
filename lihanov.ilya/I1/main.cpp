#include "LOCALMAX.h"
#include <iostream>

int main() {

  LocalMax LocalMax{ 0, 0, 0 };

  unsigned int currentValue = 0;
  do {
      std::cin >> currentValue;

      if (!std::cin) {
          std::cout << "Error occurred." << std::endl;
          return 1;
      }

      try {
          LocalMax(currentValue);
      }
      catch (const std::overflow_error& e) {
          std::cout << e.what() << std::endl;
          return 2;
      }

  } while (currentValue && std::cin);

  std::cout << "Number of local maximum: " << LocalMax.count << std::endl;
  std::cout << "Number of numbers of neighbors: " << LocalMax.countV << std::endl;

  return 0;
}
