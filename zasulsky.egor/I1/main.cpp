#include <iostream>
#include <stdexcept>
#include "counter.hpp"

int main()
{
  int val = 0;
  zasulsky::SecondLargestFinder findSecondLargest;
  zasulsky::FibonacciCounter countFibonacci;
  do {
    std::cin >> val;
    if (!std::cin) {
      std::cout << "Input error\n";
      return 1;
    }
    try {
      countFibonacci(val);
      findSecondLargest(val);
    } catch (const std::exception& e) {
      std::cout << e.what() << '\n';
      return 1;
    }
  } while (std::cin && val != 0);
  std::cout << "Second largest value " << findSecondLargest.secondLargestVal << '\n';
  std::cout << "Fibonacci number count " << countFibonacci.count << '\n';
}
