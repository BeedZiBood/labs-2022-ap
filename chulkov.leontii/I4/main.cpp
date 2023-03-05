#include <iostream>
#include <cstring>
#include <fstream>
#include "positiveelements.h"
#include "fillingthematrixinspiral.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cout << "Error\n";
    return 1;
  }
  size_t c = 0;
  size_t r = 0;
  std::ifstream in(argv[2]);
  if (!in.is_open())
  {
    std::cout << "error in file could not be opened\n";
    return 1;
  }
  in >> c >> r;
  if (!in)
  {
    std::cout << "error while read file\n";
    return 1;
  }
  std::ofstream output(argv[3]);
  if (!output.is_open())
  {
    std::cout << "error output file could not be opened\n";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    int array[1000];
    if ((c * r) > 1000)
    {
      std::cout << "Error, array is large\n";
      return 1;
    }
    for (size_t i = 0; i < c * r; i++)
    {
      in >> array[i];
      if (!in)
      {
        std::cout << "Error while read file\n";
        return 1;
      }
    }
    size_t countPositiveRows = countPositiveOnlyRows(array, c, r);
    output << countPositiveRows << '\n';
    if (!output)
    {
      std::cout << "Error while read file\n";
      return 1;
    }
  }
  else if (std::strcmp(argv[1], "2") == 0)
  {
    if ((c * r) == 0)
    {
      output << "0\n";
      return 0;
    }
    int* newarr = new int[c * r];
    for (size_t i = 0; i < c; i++)
    {
      for (size_t j = 0; j < r; j++)
      {
        in >> newarr[c * i + j];
        if (!in)
        {
          std::cout << "Error while read file\n";
          delete[] newarr;
          return 1;
        }
      }
    }
    newarr = fillingTheMatrixInSpiral(newarr, c, r);
    for (size_t i = 0; i < c; i++)
    {
      for (size_t j = 0; j < r; j++)
      {
        output << newarr[c * i + j];
        i == (c * r - 1) ? output << "" : output << ' ';
        if (!output)
        {
           std::cout << "Error while writing file\n";
           delete[] newarr;
           return 1;
        }
      }
    }
    delete[] newarr;
  }
}
