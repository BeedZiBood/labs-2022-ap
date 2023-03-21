#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "MatrixWrapper.hpp"
#include "threeRepeats.hpp"
#include "diagonalSum.hpp"
#include "fillMatrix.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cout << "Error: Invalid arguments\n";
    return 1;
  }
  std::ifstream inFile(argv[2]);
  if (!inFile.is_open()) {
    std::cout << "Error: Input file could not be opened\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  inFile >> rows >> cols;
  if (!inFile) {
    std::cout << "Error: File read error\n";
    return 1;
  }
  std::ofstream outFile(argv[3]);
  if (!outFile.is_open()) {
    std::cout << "Error: Output file could not be opened\n";
    return 1;
  }
  if (std::strcmp(argv[1], "1") == 0) {
    int arr[1000];
    if (rows * cols > 1000) {
      std::cout << "Error: Array too large\n";
      return 1;
    }
    for (unsigned i = 0; i < rows * cols; i++) {
      inFile >> arr[i];
      if (!inFile) {
        std::cout << "Error: File read error\n";
        return 1;
      }
    }
    outFile << odintsov::countRowsWithThreeRepeats(arr, rows, cols) << ' ';
    outFile << odintsov::countColsWithThreeRepeats(arr, rows, cols);
    if (!outFile) {
      std::cout << "Error: File write error\n";
      return 1;
    }
  } else if (std::strcmp(argv[1], "2") == 0) {
    try {
      odintsov::MatrixWrapper matrix(rows, cols);
      matrix.readMatrix(inFile);
      outFile << odintsov::getMinOffDiagonalSum(matrix.arr, rows, cols) << '\n';
      odintsov::rippleFromPointFill(matrix.arr, rows, cols, 0, 0);
      outFile << rows << ' ' << cols << '\n';
      matrix.outputMatrix(outFile);
    } catch (const std::exception& err) {
      std::cout << "Error: " << err.what() << '\n';
      return 1;
    }
  }
}
