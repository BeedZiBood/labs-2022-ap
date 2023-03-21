#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include "Positive_Repeating_Array.h"
#include "Ordered_Array_functions.h"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Error: Incorrect number of arguments provided.\n";
    return 1;
  }

// Static array
  const size_t arrSize = 8;
  int arr[arrSize] = { 1, 4, 6, 8, 2, 4, 6, 8 };
  std::cout << "Positive repeating: " << isPositiveRepeatingElement(arr, arrSize) << "\n";
  std::cout << "Number of ordered triples: " << orderedTriplesCount(arr, arrSize) << "\n";

// Dynamic array
  size_t dAsize = 0;
  std::cin >> dAsize;
  if (dAsize > 0)
  {
    std::srand(time(0));
    int* dA = new int[dAsize];
    for (size_t i = 0; i < dAsize; i++)
    {
      dA[i] = std::rand() % 10;
    }
    std::cout << "Positive repeating: " << isPositiveRepeatingElement(dA, dAsize) << "\n";
    std::cout << "Number of ordered triples: " << orderedTriplesCount(dA, dAsize) << "\n";
    delete[] dA;
  }

// Array read from file
  std::ifstream file(argv[1]);
  if (!file.is_open())
  {
    std::cerr << "Error opening file " << "\n";
    return 1;
  }
  size_t aFs = 0;
  file >> aFs;
  if (!file)
  {
    std::cerr << "File reading error" << "\n";
    return 1;
  }
  if (aFs > 0)
  {
    int* aFF = new int[aFs];
    for (size_t i = 0; i < aFs; i++)
    {
      file >> aFF[i];
      if (!file)
      {
        std::cerr << "Error reading from file " << "\n";
        delete[] aFF;
        return 1;
      }
    }
    std::cout << "Positive repeating:" << isPositiveRepeatingElement(aFF, aFs) << "\n";
    std::cout << "OrderTrip:" << orderedTriplesCount(aFF, aFs) << "\n";
    delete[] aFF;
  }
  return 0;
}
