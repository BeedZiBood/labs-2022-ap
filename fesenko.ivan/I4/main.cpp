#include <iostream>
#include <fstream>
#include <cstring>
#include "countRowsWithZeros.h"
#include "changeMatrixByPeriphery.h"

int main(int argc, char *argv[])
{
  if (argc != 4) {
    std::cerr << "Invalid number of arguments\n";
    return 2;
  }
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream in(argv[2]);
  in >> cols >> rows;
  if (!in) {
    std::cerr << "Error while reading\n";
    return 2;
  }
  if (!std::strcmp(argv[1], "1")) {
    int array[1000];
    if (rows * cols > 1000) {
      std::cerr << "Too big matrix\n";
      return 2;
    }
    for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < cols; j++) {
        in >> array[i * cols + j];
        if (!in) {
          std::cerr << "Error while reading\n";
          return 2;
        }
      }
    }
    std::ofstream out(argv[3]);
    out << countRowsWithZeros(array, rows, cols) << "\n";
    if (!out) {
      std::cerr << "Error while writing\n";
      return 2;
    }
  }
  else if (!std::strcmp(argv[1], "2")) {
    int *dynArray = nullptr;
    try {
      dynArray = new int[rows * cols];
    }
    catch (const std::bad_alloc &e) {
      std::cerr << e.what() << "\n";
      return 2;
    }
    for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < cols; j++) {
        in >> dynArray[i * cols + j];
        if (!in) {
          std::cerr << "Error while reading\n";
          delete [] dynArray;
          return 2;
        }
      }
    }
    changeMatrixByPeriphery(dynArray, rows, cols);
    std::ofstream out(argv[3]);
    for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < cols; j++) {
        out << dynArray[i * cols + j];
        if (j != cols - 1) {
          out << " ";
        } else {
          out << "\n";
        }
        if (!out) {
          std::cerr << "Error while writing\n";
          delete [] dynArray;
          return 2;
        }
      }
    }
    delete [] dynArray;
  }
  else {
    std::cerr << "Invalid argument\n";
    return 2;
  }
}
