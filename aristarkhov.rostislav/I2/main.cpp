#include <iostream>
#include <fstream>
#include "countNegativeAfterMax.h"
#include "maxValueInterval.h"

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "Error\n";
    return 1;
  }

  int arr1[10] = { -2, 10, 9, -2, -3, -2, 6 , 8, 3, -4 };
  std::cout << countNegativeAfterMax(arr1, 10) << "\n";
  int start_interval = 1;
  int end_interval = 12;

  int max_interval_arr1 = maxValueInterval(arr1, 10, start_interval, end_interval);
  if (max_interval_arr1 != start_interval - 1)
  {
    std::cout << max_interval_arr1 << "\n";
  }
  else
  {
    std::cout << "There is no suitable maximum\n";
  }

  size_t size_arr2 = 0;
  int* arr2 = nullptr;
  std::cin >> size_arr2;
  if (!std::cin)
  {
    std::cerr << "Incorrect data entered\n";
    return 1;
  }
  arr2 = new int[size_arr2];
  std::srand(time(nullptr));
  for (size_t i = 0; i < size_arr2; i++)
  {
    arr2[i] = std::rand() % 13;
  }
  if (size_arr2 == 0)
  {
    std::cout << "Array size must not be 0\n";
  }
  std::cout << countNegativeAfterMax(arr2, size_arr2) << "\n";
  int max_interval_arr2 = maxValueInterval(arr2, size_arr2, start_interval, end_interval);
  if (max_interval_arr2 != start_interval - 1)
  {
    std::cout << max_interval_arr2 << "\n";
  }
  else
  {
    std::cout << "There is no suitable maximum\n";
  }
  delete[] arr2;

  std::ifstream file(argv[1]);
  if (!file.is_open())
  {
    std::cout << "Error while opening file\n";
    return 1;
  }
  size_t size_arr3 = 0;
  file >> size_arr3;
  if (!file)
  {
    std::cout << "Error while reading file\n";
    return 1;
  }
  int* arr3 = new int[size_arr3];
  for (size_t i = 0; i < size_arr3; i++)
  {
    file >> arr3[i];
    if (!file)
    {
      std::cerr << "Error while reading\n";
      delete[] arr3;
      return 1;
    }
  }
  if (size_arr3 == 0)
  {
    std::cout << "Array size must not be 0\n";
  }
  std::cout << countNegativeAfterMax(arr3, size_arr3) << "\n";
  int max_interval_arr3 = maxValueInterval(arr3, size_arr3, start_interval, end_interval);
  if (max_interval_arr3 != start_interval - 1)
  {
    std::cout << max_interval_arr3 << "\n";
  }
  else
  {
    std::cout << "There is no suitable maximum\n";
  }
  delete[] arr3;
  return 0;
}
