#include <iostream>
#include <fstream>
#include "moveElements.h"
#include "calculateArithmeticMean.h"
int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    std::cout << "Check file name";
    return 1;
  }
  if (argc > 2)
  {
    std::cout << "Check parameters";
    return 1;
  }
  int array_1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  moveElements(array_1, 10, 1, 5);
  for (size_t i = 0; i < 10; i++)
  {
    std::cout << array_1[i] << " ";
  }
  std::cout << "\n";
  std::cout << calculateArithmeticMean(array_1, 10) << "\n";
  size_t n = 0;
  std::cin >> n;
  int *array_2 = new int[n];
  std::srand(time(nullptr));
  for (size_t i = 0; i < n; i++)
  {
    array_2[i] = std::rand();
  }
  moveElements(array_2, n, 0, 1);
  for (size_t i = 0; i < n; i++)
  {
    std::cout << array_2[i] << " ";
  }
  std::cout << "\n";
  try
  {
    std::cout << calculateArithmeticMean(array_2, n) << "\n";
  }
  catch (const std::runtime_error &e)
  {
    std::cout << e.what() << "\n";
  }
  delete[] array_2;
  std::ifstream input(argv[1]);
  size_t size = 0;
  input >> size;
  if (!input)
  {
    std::cout << "Another one error";
    return 1;
  }
  int *array_3 = new int[size];
  for (size_t i = 0; i < size; i++)
  {
    input >> array_3[i];
    if (!input)
    {
      std::cout << "Another one error";
      delete[] array_3;
      return 1;
    }
  }
  moveElements(array_3, size, 0, 1);
  for (size_t i = 0; i < size; i++)
  {
    std::cout << array_3[i] << " ";
  }
  std::cout << "\n";
  try
  {
    std::cout << calculateArithmeticMean(array_3, size) << "\n";
  }
  catch (const std::runtime_error &e)
  {
    std::cout << e.what() << "\n";
  }
  delete[] array_3;
  return 0;
}
