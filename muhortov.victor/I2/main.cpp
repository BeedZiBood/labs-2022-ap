#include <iostream>
#include <fstream>
#include "Partition.hpp"
#include "FindChainOfNumbers.hpp"
#include "PrintArray.hpp"

int main(int argc, char* argv[])
{
  std::srand(time(nullptr));

  if (argc == 1 || argc > 2)
  {
    std::cerr << "Too much parametres" << '\n';
    return 1;
  }

  //first task

  int first_array[] = { -1, 1, 0, 7, 5, -3, 2, 2, -4, 8 };

  std::cout << "Count of chain numbers: " << findChain(first_array, 10) << '\n';
  partition(first_array, 10);
  printArray(std::cout, first_array, 10);
  std::cout << '\n';

  //Second task

  size_t value = 0;

  std::cin >> value;
  if (std::cin.fail() || value == 0)
  {
    std::cout << "Error with input" << '\n';
  }
  else
  {
    int* second_array = new int[value];
    for (size_t i = 0; i < value; i++)
    {
      second_array[i] = std::rand();
    }
    std::cout << "Count of chain numbers: " << findChain(second_array, value) << '\n';
    partition(second_array, value);
    printArray(std::cout, second_array, value);
    std::cout << '\n';
    delete[] second_array;
  }

  //third task

  std::ifstream file(argv[1]);

  if (file.eof())
  {
    std::cerr << "Empty file" << '\n';
    return 1;
  }
  if (!file.is_open())
  {
    std::cerr << "Error with opening file" << '\n';
    return 1;
  }

  size_t third_array_size = 0;
  file >> third_array_size;

  if (!file)
  {
    std::cerr << "Empty file" << '\n';
    return 1;
  }
  if (third_array_size == 0)
  {
    std::cout << "Empty array" << '\n';
    return 0;
  }

  if (third_array_size)
  {
    int* third_array = new int[third_array_size];
    while (!file.eof())
    {
      for (size_t i = 0; i < third_array_size; i++)
      {
        file >> third_array[i];
        if (!file)
        {
          std::cerr << "Error with reading file" << '\n';
          delete[] third_array;
          return 1;
        }
      }
      std::cout << "Count of chain numbers: " << findChain(third_array, third_array_size) << '\n';
      partition(third_array, third_array_size);
      printArray(std::cout, third_array, third_array_size);
      std::cout << '\n';
      delete[] third_array;
    }
  }
}
