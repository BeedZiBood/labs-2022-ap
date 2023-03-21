#include <iostream>
#include <fstream>
#include "ArrayOperations.h"

int output(int* arr, size_t size, size_t n, size_t m) {
  if (size > 1) {
    std::cout << "Max number on even position: " << *maxEven(arr, size) << '\n';
    try {
      shitByIndexes(arr, size, n, m);
    }
    catch (const std::runtime_error &err) {
      std::cerr << "Error: " << err.what();
      return 1;
    }
  }
  std::cout << "Processed array: { ";
  printArray(std::cout, arr, size);
  std::cout << " }\n";
  return 0;
}

int main(int argc, char* argv[])
{
  std::srand(time(nullptr));
  //Task 3
  if (argc != 2) {
    std::cerr << "Incorrect amount of arguments";
    return 1;
  }

  std::ifstream fin(argv[1]);
  if (!fin.is_open()) {
    std::cerr << "File could not be opened";
    return 2;
  }
  size_t size = 0;
  fin >> size;
  if (!fin) {
    std::cerr << "Empty file";
    return 3;
  }
  if (!size) {
    return 0;
  }
  int *arr3 = new int[size]{0};
  for (size_t i = 0; i < size; i++) {
    fin >> arr3[i];
  }
  unsigned int n = size / 3;
  unsigned int m = n * 2;

  if (output(arr3, size, n, m)) {
    delete[] arr3;
    return 4;
  }
  delete[] arr3;

  size = 7; //Task 1 & 2
  //Task 1
  int arr1[] = { -5, 3, -8, 5, 5, -8, 9 };
  //int arr1[] = {0, 1, 2, 3, 4, 5, 6};
  if (output(arr1, size, n, m)) {
    return 4;
  }

  //Task 2
  std::cin >> size;
  if (!size) {
    return 0;
  }
  int* arr2 = new int[size]{0};
  randomizeArray(arr2, size);

  if (output(arr2, size, n, m)) {
    delete[] arr2;
    return 4;
  }
  delete[] arr2;
}
