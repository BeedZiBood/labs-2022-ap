#include <cstring>
#include <iostream>
#include <fstream>
#include <cstddef>
#include <stdexcept>
#include "matrixOperations.hpp"
#include "countRowsWithZeros.hpp"
#include "MatrixWrapper.hpp"
#include "getMaxOffDiagonalSum.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cout << "Incorrect arguments\n";
    return 1;
  }
  if (std::strcmp(argv[1], "1") == 0) {
    int matrix[1000];
    size_t rows = 0;
    size_t cols = 0;
    std::ifstream inFile(argv[2]);
    if (!inFile.is_open()) {
      std::cout << "Input file could not be opened\n";
      return 1;
    }
    inFile >> rows >> cols;
    if (!inFile) {
      std::cout << "Input error\n";
      return 1;
    }
    if (rows * cols > 1000) {
      std::cout << "Incorrect size\n";
      return 1;
    }
    try {
      zasulsky::fillMatrixFromStream(matrix, rows, cols, inFile);
    } catch (const std::runtime_error& err) {
      std::cout << err.what() << '\n';
      return 1;
    }
    if (rows * cols == 0) {
      return 0;
    }
    std::ofstream outFile(argv[3]);
    if (!outFile.is_open()) {
      std::cout << "Output file could not be opened\n";
      return 1;
    }
    outFile << zasulsky::countRowsWithZeros(matrix, rows, cols) << '\n';
    if (!outFile) {
      std::cout << "Output error\n";
      return 1;
    }
  } else if (std::strcmp(argv[1], "2") == 0) {
    size_t rows = 0;
    size_t cols = 0;
    std::ifstream inFile(argv[2]);
    if (!inFile.is_open()) {
      std::cout << "Input file could not be opened\n";
      return 1;
    }
    inFile >> rows >> cols;
    if (!inFile) {
      std::cout << "Input error\n";
      return 1;
    }
    zasulsky::MatrixWrapper matrixWrapper(rows, cols);
    try {
      zasulsky::fillMatrixFromStream(matrixWrapper.matrix, rows, cols, inFile);
    } catch (const std::runtime_error& err) {
      std::cout << err.what() << '\n';
      return 1;
    }
    if (rows * cols == 0) {
      return 0;
    }
    std::ofstream outFile(argv[3]);
    if (!outFile.is_open()) {
      std::cout << "Output file could not be opened\n";
      return 1;
    }
    outFile << zasulsky::getMaxOffDiagonalSum(matrixWrapper.matrix, rows, cols) << '\n';
    if (!outFile) {
      std::cout << "Output error\n";
      return 1;
    }
  } else {
    std::cout << "Unknown task number\n";
    return 1;
  }
}
