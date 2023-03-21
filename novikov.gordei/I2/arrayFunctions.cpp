#include "arrayFunctions.h"
#include <iostream>
#include <fstream>
#include <string>

void shiftArray(int* array, size_t N, size_t k)
{
  for (size_t j = 0; j < k; j++) {
    int tmp = array[N - 1];
    for (size_t i = N - 1; i > 0; i--) {
      array[i] = array[i - 1];
    }
    array[0] = tmp;
  }
}

int getPositiveAvg(const int* array, size_t N)
{
  int cnt = 0;
  int sum = 0;
  for (size_t i = 0; i < N; i++) {
    if (array[i] > 0) {
      cnt++;
      sum += array[i];
    }
  }
  return cnt ? sum / cnt : 0;
}

std::ostream& printArray(std::ostream& out, const int* array, size_t N)
{
  for (size_t i = 0; i < N; i++) {
    out << array[i];
    if (i != N - 1) {
      out << " ";
    }
  }
  return out;
}

std::istream& inputArray(std::istream& in, int** array, size_t& N)
{
  in >> N;
  if (!in.fail()) {
    *array = new int[N];
    for (size_t i = 0; i < N; i++) {
      in >> (*array)[i];
    }
    if (in.fail()) {
      delete[] array;
    }
  }
  return in;
}

void processArray(int* array, size_t N, size_t k)
{
  if (N == 0) {
    std::cout << "Empty array\n";
    return;
  }
  printArray(std::cout, array, N);
  std::cout << "\nAfter shift: ";
  shiftArray(array, N, k);
  printArray(std::cout, array, N);
  std::cout << "\nPositive elements average: " << getPositiveAvg(array, N) << "\n";
}
