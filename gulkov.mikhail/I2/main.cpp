#include <iostream>
#include <fstream>
#include "SortIncreasing.hpp"
#include "CheckRepeat.hpp"
#include "PrintArray.hpp"

int main(int argc, char* argv[])
{
  std::srand(time(nullptr));

  if (argc > 2)
  {
    std::cout << "Too much parameters";
    return 1;
  }
  else if (argc == 1)
  {
    std::cout << "Filename not found";
    return 1;
  }

  // 1
  int array1[7] = { -5, 3, -8, 5, 5, -8, 9 };
  unsigned int array1_index_m = 0;
  unsigned int array1_index_n = 3;
  try
  {
    sort_increasing(array1, 7);
    print_array(array1, 7, std::cout);
    std::cout << "\n";
    std::cout << "Has duplicate elements at least: ";
    std::cout << has_repeating_numbers(array1, 7, array1_index_m, array1_index_n);
    std::cout << " time" << std::endl;
  }
  catch (const std::invalid_argument& e)
  {
    std::cout << "Error: ";
    std::cout << e.what();
    return 1;
  }

  // 2
  size_t input = 0;
  unsigned int array2_index_m = 0;
  unsigned int array2_index_n = 3;

  std::cin >> input;
  if (input == 0)
  {
    std::cout << "No array will be created" << std::endl;
  }
  else
  {
    int* array2 = new int[input];
    for (size_t i = 0; i < input; i++)
    {
      array2[i] = std::rand();
    }
    try
    {
      sort_increasing(array2, input);
      print_array(array2, input, std::cout);
      std::cout << "\n";
      std::cout << "Has duplicate elements at least: ";
      std::cout << has_repeating_numbers(array2, input, array2_index_m, array2_index_n);
      std::cout << " time" << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
      std::cout << "Error: ";
      std::cout << e.what();
      delete[] array2;
      return 1;
    }
    delete[] array2;
  }

  // 3
  unsigned int array3_index_m = 0;
  unsigned int array3_index_n = 3;
  std::ifstream in(argv[1]);

  if (!in.is_open())
  {
    std::cout << "Error while opening file";
    return 1;
  }
  size_t array3_size = 0;
  in >> array3_size;
  if (!in)
  {
    std::cout << "Error while reading file\n";
    return 1;
  }
  if (array3_size)
  {
    while (!in.eof())
    {
      int* array3 = new int[array3_size];
      for (size_t i = 0; i < array3_size; ++i)
      {
        in >> array3[i];
        if (!in)
        {
          std::cout << "Error while reading file\n";
          delete[] array3;
          return 1;
        }
      }
      try
      {
        sort_increasing(array3, array3_size);
        print_array(array3, array3_size, std::cout);
        std::cout << "\n";
        std::cout << "Has duplicate elements at least: ";
        std::cout << has_repeating_numbers(array3, array3_size, array3_index_m, array3_index_n);
        std::cout << " time" << std::endl;
      }
      catch (const std::invalid_argument& e)
      {
        std::cout << "Error: ";
        std::cout << e.what();
        delete[] array3;
        return 1;
      }
      delete[] array3;
    }
  }
}
