#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "array.hpp"

int main(int argc, char* argv[])
{
  if (argc != 2) {
    std::cout << "Error: Invalid arguments\n";
    return 3;
  }
  std::srand(std::time(NULL));
  constexpr size_t staticArrSize = 8;
  constexpr int staticArr[staticArrSize] = {1, -234, -253, 12323, 2353, -2341, 42342, -12312};
  constexpr int lowBound = -10000;
  constexpr int highBound = 10000;
  try {
    std::cout << *odintsov::findMax(staticArr, staticArrSize, lowBound, highBound) << '\n';
  } catch (const std::logic_error& err) {
    std::cout << err.what() << '\n';
  }
  std::cout << odintsov::getAvgEvenIndices(staticArr, staticArrSize) << '\n';
  {
    size_t dynArrSize = 0;
    std::cin >> dynArrSize;
    odintsov::Array dynArr(dynArrSize);
    try {
      for (size_t i = 0; i < dynArrSize; i++) {
        dynArr.append(std::rand() % highBound);
      }
    } catch (const std::length_error& err) {
      std::cout << err.what() << '\n';
      return 2;
    }
    try {
      std::cout << *odintsov::findMax(dynArr.data, dynArr.size, lowBound, highBound) << '\n';
    } catch (const std::logic_error& err) {
      std::cout << err.what() << '\n';
    }
    std::cout << odintsov::getAvgEvenIndices(dynArr.data, dynArr.size) << '\n';
  }
  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    std::cout << "Error: file could not be opened\n";
    return 3;
  }
  size_t fileArrSize = 0;
  file >> fileArrSize;
  if (!file) {
    std::cout << "Error: file could not be read\n";
    return 3;
  }
  while (!file.eof()) {
    odintsov::Array fileArr(fileArrSize);
    for (size_t i = 0; i < fileArrSize; i++) {
      int val = 0;
      file >> val;
      if (!file) {
        std::cout << "Error: file could not be read\n";
        return 3;
      }
      fileArr.append(val);
    }
    try {
      std::cout << *odintsov::findMax(fileArr.data, fileArr.size, lowBound, highBound) << '\n';
    } catch (const std::logic_error& err) {
      std::cout << err.what() << '\n';
    }
    std::cout << odintsov::getAvgEvenIndices(fileArr.data, fileArr.size) << '\n';
  }
}
