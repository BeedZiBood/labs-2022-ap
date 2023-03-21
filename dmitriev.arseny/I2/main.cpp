#include <iostream>
#include <fstream>
#include "shiftArray.h"
#include "countOrderedTriples.h"


int main(int argc, char* arr[])
{
  if (argc != 2)
  {
    std::cout << "Problems with input";
    return 1;
  }

  int arr1[5] = { 4, 5, 1, 2, 6 };
  const size_t size1 = 5;
  size_t shift1 = 2;
  shiftArray(arr1, size1, shift1);
  countOrderedTriples(arr1, size1);

  size_t size2 = 0;
  size_t shift2 = 0;
  std::cin >> size2;
  int* arr2 = new int[size2];
  std::srand(time(nullptr));
  for (size_t i = 0; i < size2; i++)
  {
    arr2[i] = std::rand();
  }
  shiftArray(arr2, size2, shift2);
  countOrderedTriples(arr2, size2);
  delete[] arr2;

  std::ifstream file(arr[1]);
  if (!file.is_open())
  {
    std::cout << "Error while opening file" << "\n";
    return 1;
  }
  size_t size3 = 0;
  size_t shift3 = 1;
  file >> size3;
  if (!file)
  {
    std::cout << "Error while opening file" << "\n";
    return 1;
  }
  int* arr3 = new int[size3];
  for (size_t i = 0; i < size3; i++)
  {
    file >> arr3[i];
    if (!file)
    {
      std::cout << "Error while reading file" << "\n";
      delete[] arr3;
      return 1;
    }
  }
  shiftArray(arr3, size3, shift3);
  countOrderedTriples(arr3, size3);
  delete[] arr3;

  return 0;
}
