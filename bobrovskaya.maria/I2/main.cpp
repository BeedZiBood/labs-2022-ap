#include <iostream>
#include <fstream>
#include <cstddef>
#include <readMatrix.h>
#include "CountIndenticalElements.h"
#include "SortingArrFromNegativeToPositiveVal.h"

void outputArray(int* arr, size_t sizeArr)
{
  for (size_t i = 0; i < sizeArr; i++)
  {
    std::cout << arr[i];
  }
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cout << "Incorrect number of arguments" << "\n";
    return 1;
  }

  int arr1[10] = {8, 8, 4, 6, -4, -3, 2, 5, 3, 9};
  size_t arrSize1 = 10;
  size_t maxCountIndeticalEllementsArr1 = countIndenticalElements(arr1, arrSize1);
  std::cout << "The number of indentical elements in array1: " << maxCountIndeticalEllementsArr1 << "\n";
  partition(arr1, arrSize1);
  std::cout << "Modified array1: ";
  outputArray(arr1, arrSize1);
  std::cout << "\n";

  size_t arrSize2 = 0;
  int* arr2 = nullptr;
  std::cout << "Enter the size array2:";
  std::cin >> arrSize2;
  if (arrSize2 > 0)
  {
    arr2 = new int[arrSize2];
    std::srand(time(nullptr));
    for (size_t i = 0; i < arrSize2; i++)
    {
      arr2[i] = std::rand() % 10;
    }
    size_t maxCountIndeticalEllementsArr2 = countIndenticalElements(arr2, arrSize2);
    std::cout << "The number of indentical elements in array2: " << maxCountIndeticalEllementsArr2 << "\n";
    partition(arr1, arrSize1);
    std::cout << "Modified array2: ";
    outputArray(arr2, arrSize2);
    std::cout << "\n";
    delete[] arr2;
  }

  std::ifstream readFile(argv[1]);
  if (!readFile.is_open())
  {
    std::cerr << "Error while opening file\n";
    return 1;
  }
  size_t arrSize3 = 0;
  readFile >> arrSize3;
  if (!readFile)
  {
    std::cerr << "Error while reading file\n";
    return 1;
  }
  if (arrSize3 == 0)
  {
    return 0;
  }
  int* arr3 = new int[arrSize3];
  if (readMatrixFromFile(arr3, arrSize3, readFile) == nullptr)
  {
    if (!readFile)
    {
      std::cerr << "Invalid number of array elements\n";
      delete[] arr3;
      return 1;
    }
  }
  readFile.close();
  size_t maxCountIndeticalEllementsArr3 = countIndenticalElements(arr3, arrSize3);
  std::cout << "The number of indentical elements in array3: " << maxCountIndeticalEllementsArr3 << "\n";
  partition(arr3, arrSize3);
  std::cout << "Modified array3: ";
  outputArray(arr3, arrSize3);
  std::cout << "\n";
  delete[] arr3;
}
