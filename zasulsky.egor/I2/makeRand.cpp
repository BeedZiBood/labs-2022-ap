#include "makeRand.hpp"
#include <limits>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

void zasulsky::genRandSeed() {
  std::srand(std::time(nullptr));
}

int zasulsky::makeRand(int a, int b) {
  if (a > b) {
    throw std::invalid_argument("Bounds set incorrectly");
  }
  if (a < 0 && b > 0 && a < b - std::numeric_limits< int >::max()) {
    throw std::overflow_error("Bounds too wide to generate value");
  }
  return std::rand() % (b - a) + a;
}
