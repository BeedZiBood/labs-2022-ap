#include <iostream>
#include <iomanip>
#include "processInput.hpp"
#include "compositeshape.hpp"

int main()
{
  odintsov::CompositeShape composite;
  try {
    processInput(std::cin, std::cout << std::fixed << std::setprecision(1), composite);
  } catch (const std::exception& err) {
    std::cerr << "Error: " << err.what() << '\n';
    return 1;
  }
}
