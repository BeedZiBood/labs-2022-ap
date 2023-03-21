#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "arrayFunctions.h"

const size_t N = 10;
const int randMin = -50;
const int randMax = 50;

int main(int argc, const char* argv[])
{
  using std::cout;
  using std::cin;

  if (argc != 2) {
    std::cerr << "Exactly one argument needed\n";
    return 1;
  }
  std::srand(time(nullptr));

  size_t k = 2;

  int staticArray[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  cout << "Static array: ";
  processArray(staticArray, N, k);

  cout << "Enter number of elements in dynamic array: ";
  size_t n;
  cin >> n;
  if (cin.fail()) {
    std::cerr << "Number is not a positive integer\n";
    return 1;
  }
  int* dynamicArray = new int[n];
  for (size_t i = 0; i < n; i++) {
    dynamicArray[i] = std::rand() % (randMax - randMin + 1) + randMin;
  }
  processArray(dynamicArray, n, k);
  delete[] dynamicArray;

  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    std::cerr << "Can't open the file\n";
    return 1;
  }
  inputArray(file, &dynamicArray, n);
  file.close();
  if (file.fail()) {
    std::cerr << "Can't open the file or read the array\n";
    return 1;
  }
  processArray(dynamicArray, n, k);
  delete[] dynamicArray;

  return 0;
}
