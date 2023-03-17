#include <iostream>
#include <fstream>
#include <cstddef>
#include "slideonleft.h"
#include "fillthearraywithrandomnumbers.h"
#include "ismaxdecreasingfragment.h"
#include "isarrayoutput.h"
int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cout << "Erorr!";
    return 1;
  }
  size_t count_elements = 0;
  size_t count_elements_for_slide_array = 0;
  size_t max_decreasing_fragment = 0;
  int array_static[7] = { 7,-5,3,8,9,1,-6 };
  isArrayOutput(array_static, 7);
  std::cout << "\n";
  max_decreasing_fragment = isMaxDecreasingFragment(array_static, 7);
  std::cout << "Maximum decreasing fragments: " << max_decreasing_fragment << "\n";
  std::cout << "Enter the number of elements by which to shift the array: ";
  std::cin >> count_elements_for_slide_array;
  int* first_variable_for_array_output = slideOnLeft(array_static, 7, count_elements_for_slide_array);
  isArrayOutput(first_variable_for_array_output, 7);
  std::cout << "\n";
  std::cout << "Enter the number of elements of the dynamic array: ";
  std::cin >> count_elements;
  if (std::cin && count_elements)
  {
    int* array_dynamic = new int[count_elements];
    array_dynamic = fillTheArrayWithRandomNumbers(array_dynamic, count_elements);
    isArrayOutput(array_dynamic, count_elements);
    max_decreasing_fragment = isMaxDecreasingFragment(array_dynamic, count_elements);
    std::cout << "\n";
    std::cout << "Maximum decreasing fragments: " << max_decreasing_fragment << "\n";
    std::cout << "Enter the number of elements by which to shift the array: ";
    std::cin >> count_elements_for_slide_array;
    int* second_variable_for_array_output = slideOnLeft(array_dynamic, count_elements, count_elements_for_slide_array);
    isArrayOutput(second_variable_for_array_output, count_elements);
    std::cout << "\n";
    delete[] array_dynamic;
  }
  else
  {
    std::cout << "Error..." << "\n";
  }
  std::cout << "Enter the number of elements by which to shift the array: ";
  std::cin >> count_elements_for_slide_array;
  std::ifstream file;
  file.open(argv[1]);
  if (!file.is_open())
  {
    std::cout << "Error when you open file\n";
    return 1;
  }
  size_t size_file = 0;
  file >> size_file;
  if (!file)
  {
    std::cout << "Error\n";
    return 1;
  }
  int* array_from_file = new int[size_file];
  for (size_t i = 0; i < size_file; i++)
  {
    file >> array_from_file[i];
    if (!file)
    {
      std::cout << "Error\n";
      return 1;
    }

  }
  file.close();
  std::cout << isMaxDecreasingFragment(array_from_file, size_file) << "\n";
  std::cout << slideOnLeft(array_from_file, size_file, count_elements_for_slide_array) << "\n";
  delete[] array_from_file;
  return 0;
}
