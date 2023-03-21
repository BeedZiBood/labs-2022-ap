#include <iostream>
#include <fstream>
#include <cstddef>
#include <ctime>
#include "counter_of_elements_divisible_without_remainder.h"
#include "positive_element_counter.h"

int main(int argc, char* argv[])
{
  std::srand(std::time(nullptr));
  if (argc != 2)
  {
    std::cerr << "ERROR: the number of arguments does not match the required\n";
    return 1;
  }
  //static array
  int n = 0;
  std::cout << "Enter number bu which elements will be divisible\n";
  std::cin >> n;
  if (!std::cin)
  {
    std::cerr << "ERROR: invalid number entry\n";
    return 1;
  }
  int static_array[] = { 1, 0, -2, 6, -24, 9, 7 };
  std::cout << "CountPositiveElementsBeforeMinElement ";
  std::cout << countPositiveElementsBeforeMinElement(static_array, 7) << '\n';
  try
  {
    std::cout << "CountElementsDivisibleWithoutRemainder ";
    std::cout << countElementsDivisibleWithoutRemainder(static_array, 7, n) << '\n';
  }
  catch (const std::runtime_error& e)
  {
    std::cout << e.what() << '\n';
  }
  //dynamic array
  size_t dyn_array_size = 0;
  std::cout << "Enter dynamic array size\n";
  std::cin >> dyn_array_size;
  int* dynamic_array = new int[dyn_array_size];
  if (dyn_array_size > 0)
  {
    for (size_t i = 0; i < dyn_array_size; i++)
    {
      dynamic_array[i] = std::rand() % 100;
    }
    std::cout << "CountPositiveElementsBeforeMinElement ";
    std::cout << countPositiveElementsBeforeMinElement(dynamic_array, dyn_array_size) << '\n';
    try
    {
      std::cout << "CountElementsDivisibleWithoutRemainder ";
      std::cout << countElementsDivisibleWithoutRemainder(dynamic_array, dyn_array_size, n) << '\n';
    }
    catch (const std::runtime_error& e)
    {
      std::cout << e.what() << '\n';
    }
  }
  else
  {
    std::cout << "dynamic array size = 0\n";
  }
  delete [] dynamic_array;
  //array from file
  std::ifstream input(argv[1]);
  if (!input.is_open())
  {
    std::cerr << "ERROR: file is not opening\n";
    return 2;
  }
  size_t array_size_from_file = 0;
  input >> array_size_from_file;
  if (!input)
  {
    std::cerr << "ERROR: reading file\n";
    return 1;
  }
  if (array_size_from_file > 0)
  {
    int* array_from_file = new int[array_size_from_file];
    for (size_t i = 0;i < array_size_from_file;i++)
    {
      input >> array_from_file[i];
      if (!input)
      {
        std::cerr << "ERROR: reading file\n";
        return 1;
      }
    }
    std::cout << "CountPositiveElementsBeforeMinElement ";
    std::cout << countPositiveElementsBeforeMinElement(array_from_file, array_size_from_file) << '\n';
    try
    {
      std::cout << "CountElementsDivisibleWithoutRemainder ";
      std::cout << countElementsDivisibleWithoutRemainder(array_from_file, array_size_from_file, n) << '\n';
    }
    catch (const std::runtime_error& e)
    {
      std::cout << e.what() << '\n';
    }
    delete [] array_from_file;
  }
  else if (array_size_from_file==0)
  {
    std::cout << "array size from file = 0\n";
  }
  return 0;
}
