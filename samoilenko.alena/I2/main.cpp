#include <iostream>
#include <cstddef>
#include <fstream>
#include "negative_elements.h"
#include "shifted_array.h"
#include "array_output.h"
int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cout << "File or parameters are incorrect";
    return 1;
  }
  const size_t array_shift = 3;
  int array[10] = {6, 9, -11, 4, 1, 26, 73, -38, -45, -21};
  std::cout << countNegativeElementsAfterMax(array, 10) << '\n';
  size_t size_arr = 10;
  moveTheArray(array, 10, array_shift);
  outputAnArray(array, size_arr, std::cout);
  size_t num_of_elem = 0;
  std::cin >> num_of_elem;
  if (!std::cin)
  {
    std::cout << "Error...";
    return 1;
  }
  if (num_of_elem == 0)
  {
    std::cout << "0 0" << '\n';
  }
  else
  {
    int* dynamic_array = new int[num_of_elem];
    const size_t r = 5;
    std::srand(r);
    for (size_t i = 0; i < num_of_elem; i++)
    {
      dynamic_array[i] = std::rand();
    }
    std::cout << countNegativeElementsAfterMax(dynamic_array, num_of_elem) << '\n';
    outputAnArray(dynamic_array, num_of_elem, std::cout);
    std::cout << '\n';
    moveTheArray(dynamic_array, num_of_elem, array_shift);
    outputAnArray(dynamic_array, num_of_elem, std::cout);
    delete [] dynamic_array;
    std::cout << '\n';
  }
  std::ifstream input(argv[1]);
  if (!input)
  {
    std::cout << "Error during opening the file input.txt";
    return 1;
  }
  size_t size_of_mas = 0;
  input >> size_of_mas;
  if (!input)
  {
    std::cout << "Error during reading the file input.txt";
    return 1;
  }
  if (size_of_mas == 0)
  {
    std::cout << "0 0" << '\n';
    return 0;
  }
  else
  {
    int* arr_from_file = new int[size_of_mas];
    for (size_t i = 0; i < size_of_mas; i++)
    {
      input >> arr_from_file[i];
      if (!input)
      {
        std::cout << "Error during reading the file input.txt";
        return 1;
      }
    }
    std::cout << countNegativeElementsAfterMax(arr_from_file, size_of_mas);
    outputAnArray(arr_from_file, size_of_mas, std::cout);
    std::cout << '\n';
    moveTheArray(arr_from_file, size_of_mas, array_shift);
    outputAnArray(arr_from_file, size_of_mas, std::cout);
    delete [] arr_from_file;
  }
  return 0;
}
