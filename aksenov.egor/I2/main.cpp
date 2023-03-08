#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <readingFile.h>
#include "countAmountOfRightPairs.h"
#include "repeatingPositiveNumbers.h"
#include "fillArrayWithRandomNumbers.h"
int main(int argc, char *argv[])
{
  std::srand(std::time(nullptr));
  int filled_arr[6] = {-1, 3, 3, 4, 5, 6};
  std::cout << countAmountOfRightPairs(filled_arr, 6) << "\n";
  std::cout << isRepeatingPositiveNumbers(filled_arr, 6) << "\n";
  size_t line = 0;
  std::cin >> line;
  if (!std::cin)
  {
    std::cout << "error input" << "\n";
    return 2;
  }
  int *second_arr = new int[line];
  if (line > 0)
  {
    second_arr = fillArrayWithRandomNumbers(second_arr, line);
    std::cout << countAmountOfRightPairs(second_arr, line) << "\n";
    std::cout << isRepeatingPositiveNumbers(second_arr, line) << "\n";
    delete [] second_arr;
  }
  else
  {
    std::cout << "ERROR " << "\n";
    delete [] second_arr;
  }
  line = 0;
  second_arr = new int[line];
  if (argc != 2)
  {
    std::cerr << "Not correct amount of parameters" << "\n";
  }
  std::string fname = argv[1];
  std::ifstream input(fname);
  input >> line;
  if (!input)
  {
    std::cout << "Error while reading file" << "\n";
    delete[] second_arr;
    return 2;
  }
  try
  {
    second_arr = readFile(input, line, second_arr);
  }
  catch (const std::length_error & e)
  {
    std::cout << e.what() << "\n";
    delete [] second_arr;
    return 2;
  }
  std::cout << countAmountOfRightPairs(second_arr, line) << "\n";
  std::cout << isRepeatingPositiveNumbers(second_arr, line) << "\n";
  delete [] second_arr;
}
