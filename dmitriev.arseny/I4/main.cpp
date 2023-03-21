#include <iostream>
#include <cstddef>
#include <fstream>
#include <cstring>
#include "countColumnNoZero.h"
#include "countMonoIncreaceLines.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cout << "not enough arguments" << '\n';
    return 1;
  }

  std::ifstream fileInp(argv[2]);
  if (!fileInp.is_open())
  {
    std::cout << "problems while opening file" << '\n';
    fileInp.close();
    return 1;
  }
  std::ofstream fileOut(argv[3]);
  if (!fileOut.is_open())
  {
    std::cout << "problems while opening file" << '\n';
    fileInp.close();
    fileOut.close();
    return 1;
  }

  size_t line = 0, column = 0;

  if (!std::strcmp(argv[1], "1"))
  {
    int matrix1[1000];

    fileInp >> line >> column;
    if (!fileInp)
    {
      std::cout << "problems while reading file" << '\n';
      fileInp.close();
      fileOut.close();
      return 1;
    }
    if (line * column > 1000)
    {
      std::cout << "too many val" << '\n';
      fileInp.close();
      fileOut.close();
      return 1;
    }

    for (size_t i = 0; i < line; i++)
    {
      for (size_t j = 0; j < column; j++)
      {
        fileInp >> matrix1[column * i + j];
        if (!fileInp)
        {
          std::cout << "problems while reading file" << '\n';
          fileInp.close();
          fileOut.close();
          return 1;
        }
      }
    }
    fileOut << countColumnNoZero(matrix1, line, column) << '\n';
    fileOut << countMonoIncreaceLines(matrix1, line, column) << '\n';
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    fileInp >> line >> column;
    if (!fileInp)
    {
      std::cout << "problems while reading file" << '\n';
      fileInp.close();
      fileOut.close();
      return 1;
    }

    int* matrix2 = nullptr;
    try
    {
      matrix2 = new int[line * column];
    }
    catch (const std::bad_alloc& e)
    {
      std::cout << e.what() << '\n';
      fileInp.close();
      fileOut.close();
      return 1;
    }

    for (size_t i = 0; i < line; i++)
    {
      for (size_t j = 0; j < column; j++)
      {
        fileInp >> matrix2[column * i + j];
        if (!fileInp)
        {
          std::cout << "problems while reading file" << '\n';
          delete[] matrix2;
          fileInp.close();
          fileOut.close();
          return 1;
        }
      }
    }
    fileOut << countColumnNoZero(matrix2, line, column) << '\n';
    fileOut << countMonoIncreaceLines(matrix2, line, column) << '\n';
    delete[] matrix2;
  }
  else
  {
    std::cout << "incorrect number" << '\n';
    fileInp.close();
    fileOut.close();
    return 1;
  }

  fileInp.close();
  fileOut.close();

  return 0;
}
