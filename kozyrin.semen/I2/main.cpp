#include <iostream>
#include <fstream>
#include <limits>
#include "ArrayOperations.h"

int main(int argc, char* argv[])
{
  //Task 3
  if (argc > 2) {
    std::cerr << "Too many parameters";
    return 1;
  }
  if (argc == 1) {
    std::cerr << "Missing filename";
    return 1;
  }

  unsigned int n = 0;
  unsigned int m = 0;
  size_t size = 0;

  std::ifstream fin(argv[1]);
  if (!fin.is_open()) {
    std::cerr << "File could not be opened";
    return 1;
  }
  fin >> size;
  if (!fin) {
    std::cerr << "Empty file";
    return 1;
  }

  while (!fin.eof()) {
    if (!size) {
      return 0;
    }
    int *arr3 = new int[size]{0};

    for (size_t i = 0; i < size; i++) {
      fin >> arr3[i];
      if (arr3[i] < std::numeric_limits< int >::min() || arr3[i] > std::numeric_limits< int >::max()) {
        std::cerr << "arr[" << i << "] is too big/small for integer \n";
        delete[] arr3;
        return 1;
      }
    }
    if (size > 1) {
      std::cout << "Max number on even position: " << maxEven(arr3, size) << '\n';
      //std::cin >> n >> m;
      try {
        shiftByIndexes(arr3, size, n, m);
      }
      catch (const std::runtime_error &err) {
        std::cerr << "Error: " << err.what();
        return 2;
      }
    }

    printArray(arr3, size);
    delete[] arr3;
    fin >> size;
  }

  size = 7; //Task 1 & 2
  //Task 1
  int arr1[] = { -5, 3, -8, 5, 5, -8, 9 };
  //std::cout << "Max number on even position: " << maxEven(arr1, size) << '\n';
  shiftByIndexes(arr1, size, n, m);
  //printArray(arr1, size);

  //Task 2
  //std::cin >> size;
  if (!size) {
    return 0;
  }
  int* arr2 = new int[size]{0};
  randomizeArray(arr2, size);

  if (size > 1) {
    //std::cout << "Max number on even position: " << maxEven(arr2, size) << '\n';
    //std::cin >> n >> m;
    try {
      shiftByIndexes(arr2, size, n, m);
    }
    catch (const std::runtime_error &err) {
      std::cerr << "Error: " << err.what();
      return 2;
    }
  }

  //printArray(arr2, size);
  delete[] arr2;
}
