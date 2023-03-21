#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "countDecreasingValues.h"
#include "partitionByEven.h"
#include "shiftArray.h"
#include "outputForArray.h"
#include "countDivValues.h"
int main(int argc, char *argv[])
{
  int ready_array[5] = {4, 5, 3, 2, 1};
  try
  {
    std::cout << "Length of Decrease1: " << countDecreasingValues(ready_array, 5) << "\n";
    std::cout << "divider " << *partitionByEven(ready_array, 5) << "\n";
    std::cout << "Amout of Div " << countDivValues(ready_array, 5, 2) << "\n";
    shiftArray(ready_array, 5, 2);
    std::cout << "Shifted ";
    outputForArray(std::cout, ready_array, 5);
  }
  catch (const std::length_error &e)
  {
    std::cout << e.what() << "\n";
    return 0;
  }

  size_t line = 0;
  std::cin >> line;
  if (!std::cin)
  {
    std::cout << "Input error" << "\n";
    return 2;
  }

  std::srand(std::time(nullptr));
  int *dyn_array = new int[line];
  if (line > 0)
  {
    for (size_t i = 0; i < line; i++)
    {
      dyn_array[i] = std::rand() % 100;
    }
    std::cout << "Length of Decrease2: " << countDecreasingValues(dyn_array, line) << "\n";
    std::cout << "divider " << *partitionByEven(dyn_array, line) << "\n";
    std::cout << "Amout of Div " << countDivValues(dyn_array, line, 4) << "\n";
    shiftArray(dyn_array, line, 4);
    std::cout << "Shifted ";
    outputForArray(std::cout, dyn_array, line);
  }
  else
  {
    std::cout << "Error " << "\n";
  }
  delete [] dyn_array;

  if (argc != 2)
  {
    std::cerr << "Not correct amount of CML argc" << "\n";
    return 2;
  }

  size_t fsize = 0;
  int *file_array = new int[fsize];
  std::string fname = argv[1];
  std::ifstream input(fname);
  input >> fsize;
  if (!input)
  {
    std::cerr << "File error" << "\n";
    input.close();
    delete [] file_array;
    return 2;
  }
  for (size_t i = 0; i < fsize; ++i)
  {
    input >> file_array[i];
    if (!input)
    {
      std::cout << "File error" << "\n";
      input.close();
      delete [] file_array;
      return 2;
    }
  }
  try
  {
    std::cout << "Length of Decrease3: " << countDecreasingValues(file_array, fsize) << "\n";
    std::cout << "divider " << *partitionByEven(file_array, fsize) << "\n";
    std::cout << "Amout of Div " << countDivValues(file_array, fsize, 3) << "\n";
    shiftArray(file_array, fsize, 2);
    std::cout << "Shifted ";
    outputForArray(std::cout, file_array, fsize);
  }
  catch (const std::length_error &e)
  {
    std::cout << e.what() << "\n";
    input.close();
    delete [] file_array;
    return 0;
  }
  delete [] file_array;
  input.close();
}
