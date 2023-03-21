#include <iostream>
#include <cstdlib>
#include <fstream>
#include "elements.h"
#include "workWithIO.h"

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cerr << "Not correct amount of CML args\n";
    return 2;
  }
  int array[10] = {-1, 5, -5, 5, 3, 2, 5, -27, 4, 1};
  size_t array_size = 10;
  size_t neg_after_max = potapova::findNegativeAfterMax(array, array_size);
  size_t repeat_pos_numb = potapova::findRepeatingPositiveNumbers(array, array_size);
  std::cout << neg_after_max << " " << repeat_pos_numb << "\n";
  size_t dyn_array_size = 0;
  std::cin >> dyn_array_size;
  if (!std::cin)
  {
    std::cout << "Error while reading\n";
    return 1;
  }
  if (dyn_array_size > 0)
  {
    int* dyn_array = new int[dyn_array_size];
    const unsigned int srand_elem = 3;
    std::srand(srand_elem);
    for (size_t i = 0; i < dyn_array_size; i++)
    {
      dyn_array[i] = std::rand();
    }
    size_t dyn_neg_after_max = potapova::findNegativeAfterMax(dyn_array, dyn_array_size);
    size_t dyn_repeat_pos_numb = potapova::findRepeatingPositiveNumbers(dyn_array, dyn_array_size);
    delete [] dyn_array;
    std::cout << dyn_neg_after_max << " " << dyn_repeat_pos_numb << "\n";
  }
  else
  {
    std::cout << "0 0\n";
  }
  std::ifstream input(argv[1]);
  if (!input)
  {
    std::cerr << "Error while reading\n";
    return 2;
  }
  size_t arr_size = 0;
  input >> arr_size;
  if (!input)
  {
    std::cerr << "Error while reading\n";
    return 2;
  }
  if (!arr_size)
  {
    std::cout << "0 0\n";
  }
  else
  {
    long long int* arr = new int[arr_size];
    if (!inputMatrix(arr, arr_size, input))
    {
      std::cerr << "Input error\n";
      delete [] arr;
      return 1;
    }
    size_t neg_after_max = potapova::findNegativeAfterMax(arr, arr_size);
    size_t repeat_pos_numb = potapova::findRepeatingPositiveNumbers(arr, arr_size);
    delete [] arr;
    std::cout << neg_after_max << " " << repeat_pos_numb << "\n";
  }
  return 0;
}
