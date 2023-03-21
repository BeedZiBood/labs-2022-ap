#include <exception>
#include <iostream>
#include <cstddef>
#include <fstream>
#include "arithmetic_mean_of_array.h"
#include "shifted_array.h"

int main(int argc, char* argv[])
{
  int static_array[] = {5, 4, 3, 4, -6, 2, -1};
  std::cout << countArithmeticMean(static_array, 7) << " ";
  int* static_array_ptr = makeShiftedArray(static_array, 7);
  for (size_t i = 0; i < 7; i++)
  {
    std::cout << static_array_ptr[i] << " ";
  }
  std::cout << "\n";

  size_t dynamic_array_size = 0;
  std::cin >> dynamic_array_size;
  if (!std::cin)
  {
    std::cout << "Something went wrong \n";
    return 1;
  }
  if (dynamic_array_size > 0)
  {
    int* dynamic_array = new int[dynamic_array_size];
    for (size_t i = 0; i < dynamic_array_size; i++)
    {
      dynamic_array[i] = std::rand();
    }
    std::cout << countArithmeticMean(dynamic_array, dynamic_array_size) << " ";
    int* dynamic_array_ptr = makeShiftedArray(dynamic_array, dynamic_array_size);
    for (size_t i = 0; i < dynamic_array_size; i++)
    {
      std::cout << dynamic_array_ptr[i] << " ";
    }
    delete[] dynamic_array;
    std::cout << "\n";
  }
  else
  {
    std::cout << "The number of element couldn't be zero \n";
  }

  if (argc == 1)
  {
    std::cout << "File is not correct";
    return 1;
  }
  if (argc > 2)
  {
    std::cout << "Parameters are not correct";
    return 1;
  }

  std::ifstream input(argv[1]);
  if (!input.is_open())
  {
    std::cout << "Error while opening file";
    return 1;
  }
  while (!input.eof())
  {
    size_t reading_array_size = 0;
    input >> reading_array_size;
    if (!input)
    {
      std::cout << "Error";
      return 1;
    }
    int* reading_array = new int[reading_array_size];
    for (size_t i = 0; i < reading_array_size; i++)
    {
      input >> reading_array[i];
      if (!input)
      {
        std::cout << "Error";
        delete[] reading_array;
        return 1;
      }
    }
    try
    {
      std::cout << countArithmeticMean(reading_array, reading_array_size) << " ";
      int* reading_array_ptr = makeShiftedArray(reading_array, reading_array_size);
      for (size_t i = 0; i < reading_array_size; i++)
      {
        std::cout << reading_array_ptr[i] << " ";
      }
    }
    catch (const std::overflow_error& e)
    {
      std::cout << e.what();
      delete[] reading_array;
      return 2;
    }
    delete[] reading_array;
  }
  return 0;
}
