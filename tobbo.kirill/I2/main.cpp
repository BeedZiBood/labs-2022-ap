#include <cmath>
#include <fstream>
#include <iostream>
#include "countOfMaxes.h"
#include "shiftPartToEnd.h"

void printArray(std::ostream& out, std::string prefix, int* arr, size_t size);
void processArray(std::ostream& out, std::string prefix, int* arr, size_t size);

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Wrong number of parameters. Should be 1";
    return 1;
  }
  try
  {
    int arr_st[] = { 1, 2, 3, 4, 5, 6, 7, 8, 10, 10 };
    processArray(std::cout, "Static array", arr_st, 10);

    size_t size = 0;
    std::cout << "Enter array size: ";
    std::cin >> size;
    if (!std::cin)
    {
      throw std::invalid_argument("Array size must be unsigned integer");
    }
    std::srand(5);
    int* arr_dyn = new int[size];
    for (size_t i = 0; i < size; i++)
    {
      arr_dyn[i] = std::rand() % 200 - 100;
    }
    processArray(std::cout, "Dynamic array", arr_dyn, size);
    delete[] arr_dyn;

    std::ifstream input(argv[1]);
    if (!input.is_open())
    {
      throw std::runtime_error("File is not found");
    }
    input >> size;
    if (!input)
    {
      throw std::runtime_error("Error while reading size of array");
    }
    int* arr = new int[size];
    for (size_t i = 0; i < size; i++)
    {
      input >> arr[i];
      if (!input)
      {
        delete[] arr;
        throw std::runtime_error("Error while reading array elements");
      }
    }
    processArray(std::cout, "File array", arr, size);
    delete[] arr;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}

void printArray(std::ostream& out, std::string prefix, int* arr, size_t size)
{
  out << prefix;
  for (size_t j = 0; j < size; j++)
  {
    out << arr[j];
    if ((j + 1) < size)
    {
      out << " ";
    }
  }
}

void processArray(std::ostream& out, std::string prefix, int* arr, size_t size)
{
  out << prefix << " with size " << size << "\n";
  if (size == 0)
  {
    out << "Array is empty... skipped\n";
    return;
  }

  size_t count_maximum = countOfMaxes(arr, size);
  out << "Count of max: " << count_maximum << "\n";

  printArray(out, "before: ", arr, size);
  std::cout << "\n";
  shiftPartToEnd(arr, size, 0, static_cast< size_t >(std::ceil(size / 2)));
  printArray(out, "after:  ", arr, size);
  std::cout << "\n";
}
