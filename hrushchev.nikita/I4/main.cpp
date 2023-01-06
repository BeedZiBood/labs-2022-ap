#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "countcolumnsequalsumelement.hpp"
#include "islowertrianglematrix.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Incorrect arg\n";
    return 1;
  }

  std::ifstream input_file(argv[2]); 
  std::ofstream output_file(argv[3]); 


  if (!input_file.is_open())
  {
    std::cerr << "Error input file\n";
    return 1;
  }
  if (!output_file.is_open())
  {
    std::cerr << "Error output file\n";
    return 1;
  }

  size_t rows = 0;
  input_file >> rows;
  if (!input_file)
  {
    std::cerr << "Error while reading rows\n";
    return 1;
  }
  size_t columns = 0;
  input_file >> columns;
  if (!input_file)
  {
    std::cerr << "Error while reading columns\n";
    return 1;
  }
  if ((rows == 0) || (columns == 0) || (rows * columns > 1000))
  {
    std::cerr << "Incorrect input\n";
    return 1;
  }

  if (!std::strcmp(argv[1], "1"))
  {
    int array[1000];
    size_t arr_size = rows * columns;
    for (size_t i = 0; i < arr_size; i++)
    {
      input_file >> array[i];
      if (!input_file)
      {
        std::cerr << "Error while reading";
        return 1;
      }
    }
    try
    {
      std::cout << countColumnsEqualSumElement(array, rows, columns) << "\n";
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Error func\n";
      return 1;
    }
  }
}