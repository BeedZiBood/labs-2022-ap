#include <iostream>
#include <cstddef>
#include <fstream>
#include "transformarray.hpp"
#include "searchmaxinterval.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Incorrect data entered\n";
    return 2;
  }
  int arr1[] = {4, 6, 7, -2, 0, 5, -1};
  int* ptr1 = nullptr;
  ptr1 = partitionNegative(arr1, 7);
  std::cout << *ptr1 << "\n";
  int start_interval = 1;
  int end_interval = 9;
  try {
    int max_interval = searchMaxInterval(arr1, 7, start_interval, end_interval);
    if (max_interval != start_interval - 1) {
      std::cout << max_interval << std::endl;
    } else {
      std::cout << "There is no suitable maximum\n";
    }
  } catch (const std::invalid_argument &e) {
    std::cout << "Error:\n ";
    std::cout << e.what();
    return 1;
  }
  size_t size_arr2 = 0;
  std::cin >> size_arr2;
  if (!std::cin){
   std::cerr << "Incorrect data entered\n";
   return 1;
  }
  int* arr2 = new int[size_arr2];
  std::srand(time(nullptr));
  for (size_t i = 0; i < size_arr2; i++) {
    arr2[i] = std::rand();
  }
  if (size_arr2){
    int* ptr2 = nullptr;
    ptr2 = partitionNegative(arr2, size_arr2);
    std::cout << *ptr2 << "\n";
  }
  try {
    int max_interval = searchMaxInterval(arr2, size_arr2, start_interval, end_interval);
    if (max_interval != start_interval - 1) {
      std::cout << max_interval << std::endl;
    } else {
      std::cout << "There is no suitable maximum\n";
    }
  } catch (const std::invalid_argument &e) {
    std::cout << "Error:\n ";
    std::cout << e.what();
    delete[] arr2;
    return 1;
  }
  delete[] arr2;
  std::ifstream input(argv[1]);
  if (!input.is_open()) {
    std::cout << "Error while opening file\n";
    return 1;
  }
  size_t size_arr3 = 0;
  input >> size_arr3;
  if (!input) {
    std::cout << "Error while reading file\n";
    return 1;
  }
  if (size_arr3){
    while (!input.eof()) {
      int* arr3 = new int[size_arr3];
      for (size_t i = 0; i < size_arr3; ++i) {
        input >> arr3[i];
        if (!input) {
          std::cout << "Error while reading file\n";
          delete[] arr3;
          return 1;
        }
      }
      int* ptr3 = nullptr;
      ptr3 = partitionNegative(arr3, size_arr3);
      std::cout << *ptr3 << "\n";
      try {
        int max_interval = searchMaxInterval(arr3, size_arr3, start_interval, end_interval);
        if (max_interval != start_interval - 1) {
          std::cout << max_interval << std::endl;
        } else {
          std::cout << "There is no suitable maximum\n";
        }
      } catch (const std::invalid_argument &e) {
        std::cout << "Error:\n ";
        std::cout << e.what();
        delete[] arr3;
        return 1;
      }
      delete[] arr3;
      input >> std::ws;
    }
  }
}
