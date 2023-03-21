#include <iostream>
#include <limits>
#include "checkPythagoreanTriples.h"

int main()
{
  size_t numbOfPythagoreanTriples = 0;
  long n = 1, x = 0, y = 0, z = 0;
  long max1 = std::numeric_limits< long >::min();
  long max2 = std::numeric_limits< long >::min();

  while (n != 0) {
    std::cin >> n;
    if (std::cin.fail()) {
      std::cout << "The element of the sequence is not a integer number\n";
      return 1;
    }
    if (n == 0) break;

    x = y;
    y = z;
    z = n;

    if (z >= max1) {
      max2 = max1;
      max1 = z;
    } else if (z >= max2) {
      max2 = z;
    }

    if (isPythagoreanTriples(x, y, z)) {
      numbOfPythagoreanTriples++;
    }

  }

  if (x == 0) {
    if (y == 0) {
      if (z == 0) {
        std::cout << "The sequence is empty\n";
        return 1;
      }
      else {
        std::cout << "The sequence contains less than 2 elements\n";
        return 1;
      }
    }
    else {
      std::cout << "The value of the second largest element is " << max2 << "\n";
      std::cout << "The sequence contains less than 3 elements\n";
      return 1;
    }
  }
  std::cout << "The value of the second largest element is " << max2 << "\n";
  std::cout << "The number of Pythagorean triples is " << numbOfPythagoreanTriples << "\n";
  return 0;
}
