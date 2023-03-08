#include "readingFile.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
int *readFile(std::istream &input, size_t line, int *f_arr)
{
  for (size_t i = 0; i < line; ++i)
  {
    input >> f_arr[i];
    if (!input)
    {
      throw std::length_error("File error");
    }
  }
  return f_arr;
}
