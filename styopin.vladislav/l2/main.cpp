#include <iostream>
#include <fstream>
#include "equalElements.h"
#include "shiftArray.h"

void outputOfArray(std::ostream &out, int* pointer, size_t size)
{
  out << pointer[0];
  for (size_t i = 1; i < size; ++i)
  {
    std::cout << "\t" << pointer[i];
  }
  std::cout << "\n";
}

int main(int argc, char* arr[])
{
  if (argc != 2)
  {
    std::cout << "Problems with input";
    return 1;
  }

  size_t size2 = 0;
  std::cout << "Enter the length of the second array: ";
  std::cin >> size2;

  const size_t size1 = 5;
  int arr1[size1] = { 4, 5, 1, 2, 6 };
  size_t shift1 = 2;
  std::string ansTrue = "Array has the same positive elements";
  std::string ansFalse = "Array hasn't the same positive elements";
  int* pointer1 = shiftArray(arr1, size1, shift1);
  outputOfArray(std::cout, pointer1, size1);
  shiftArray(arr1, size1, shift1);
  bool ans1 = isThereEqualElements(arr1, size1);
  std::cout << (ans1 ? ansTrue : ansFalse) << "\n";

  std::srand(time(nullptr))
  size_t shift2 = 0;
  int* arr2 = new int[size2];
  for (size_t i = 0; i < size2; i++)
  {
    arr2[i] = std::rand();
  }
  int* pointer2 = shiftArray(arr2, size2, shift2);
  outputOfArray(std::cout, pointer2, size2);
  bool ans2 = isThereEqualElements(arr2, size2);
  std::cout << (ans2 ? ansTrue : ansFalse) << "\n";
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
  int* pointer3 = shiftArray(arr3, size3, shift3);
  outputOfArray(std::cout, pointer3, size3);
  bool ans3 = isThereEqualElements(arr3, size3);
  std::cout << (ans3 ? ansTrue : ansFalse) << "\n";
  delete[] arr3;

  return 0;
}
