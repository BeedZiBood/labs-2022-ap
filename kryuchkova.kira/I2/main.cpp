#include <iostream>
#include <fstream>
#include <cstddef>
#include "subarray.h"
#include "descending_triple.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Invalid number of arguments." << '\n';
    return 1;
  }

  //static array

  int first_array[] = {1, 2, 2, 2, 3, 2, 1, 3, 2, 1};

  std::cout << countSequenceSimilar(first_array, 10) << ' ';
  std::cout << countDescendingTriple(first_array, 10) << '\n';

  //dynamic array with random values

  size_t n = 0;
  std::cin >> n;

  if (!std::cin)
  {
    std::cerr << "Invalid input." << '\n';
    return 1;
  }

  int* second_array = new int[n];

  if (n > 0)
  {
    for (size_t i = 0; i < n; i++)
    {
      second_array[i] = std::rand();
    }

    std::cout << countSequenceSimilar(second_array, n) << ' ';
    std::cout << countDescendingTriple(second_array, n) << '\n';
  }
  else
  {
    std::cout << "0 0" << '\n';
  }

  delete [] second_array;

  //array from file

  std::ifstream filestream(argv[1]);

  if (!filestream.is_open())
  {
    std::cerr << "Error with opening file." << '\n';
    return 2;
  }

  size_t size = 0;
  filestream >> size;

  if (!filestream)
  {
    std::cerr << "Invalid input." << '\n';
    return 1;
  }
  else if (size > 0)
  {
    int* third_array = new int[size];

    for (size_t i = 0; i < size; i++)
    {
      filestream >> third_array[i];

      if (!filestream)
      {
        std::cerr << "Incorrect value in file." << '\n';
        return 1;
      }
    }

    std::cout << countSequenceSimilar(third_array, size) << ' ';
    std::cout << countDescendingTriple(third_array, size) << '\n';
    delete [] third_array;
  }
  else if (size == 0)
  {
    std::cout << "0 0" << '\n';
  }

  return 0;
}
