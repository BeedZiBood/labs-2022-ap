#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "findAscendingColumns.h"
#include "getMinSumOfDiagonal.h"

void readArrayFromFile(std::ifstream& inFile, int* arr, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows * cols; i++)
    {
        if (!(inFile >> arr[i]))
        {
            throw std::runtime_error("Error: File read error");
        }
    }
}

int main(int argc, char * argv[])
{
    try
    {
        if (argc != 4)
        {
            throw std::invalid_argument("Error: Invalid number of arguments");
        }
        std::ifstream inFile(argv[2]);
        if (!inFile.is_open())
        {
            throw std::runtime_error("Error: Input file could not be opened");
        }
        std::ofstream outFile(argv[3]);
        if (!outFile.is_open())
        {
            throw std::runtime_error("Error: Output file could not be opened");
        }
        size_t rows = 0;
        size_t cols = 0;
        inFile >> rows >> cols;
        if (!inFile)
        {
            throw std::runtime_error("Error: File read error");
        }
        if (rows * cols > 1000)
        {
            throw std::invalid_argument("Error: Array too large");
        }
        int *arr = new int[rows * cols];
        if (std::strcmp(argv[1], "1") == 0)
        {
            readArrayFromFile(inFile, arr, rows, cols);
            outFile << countGrowingCols(arr, rows, cols) << "\n";
            delete[] arr;
        }
        else if (std::strcmp(argv[1], "2") == 0)
        {
            readArrayFromFile(inFile, arr, rows, cols);
            outFile << calcMinSummSecondaryDiagonal(arr, rows, cols) << "\n";
            delete[] arr;
        }
        else if (std::strcmp(argv[1], "3") == 0)
        {
            readArrayFromFile(inFile, arr, rows, cols);
            // process array
            delete[] arr;
        }
        else
        {
            throw std::invalid_argument("Error: Invalid argument");
        }
        if (!outFile)
        {
            throw std::runtime_error("Error: File write error");
        }
    }
    catch (const std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
