#include <iostream>
#include <fstream>
#include <cstddef>
#include "getcountmaxelement.hpp"
#include "partitionbyeven.hpp"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Incorrect argument \n";
    return 1;
  }

  constexpr size_t size1 = 10;
  int arr1[size1] = {1, 3, 24, 3, 0, 4, 3, 10 , 24, 12};
  std::cout << getCountMaxElement(arr1, size1) << "\n";
  int* border1 = partitionByEven(arr1, size1);
  std::cout << *border1 << "\n";

  size_t size2 = 0;
  std::cin >> size2;
  if (!std::cin)
  {
    std::cerr << "Input error \n";
    return 1;
  }
  if (size2 > 0)
  {
    std::srand(time(0));
    int* arr2 = new int[size2];
    for (size_t i = 0; i < size2; i++)
    {
      arr2[i] = std::rand() % 10;
    }
    std::cout << getCountMaxElement(arr2, size2) << "\n";
    int* border2 = partitionByEven(arr2, size2);
    std::cout << *border2 << "\n";
    delete[] arr2;
  }
  else
  {
    std::cout << "Size < 0 \n";
  }

  size_t size3 = 0;
  std::ifstream input_file(argv[1]);
  if (!input_file.is_open())
  {
    std::cerr << "File not open \n";
    return 1;
  }
  input_file >> size3;
  if (!input_file)
  {
    std::cerr << "Error while reading \n";
    return 1;
  }
  int* arr3 = new int[size3];
  for (size_t i = 0; i < size3; i++)
  {
    input_file >> arr3[i];
    if (!input_file)
    {
      std::cerr << "Error while reading \n";
      delete[] arr3;
      return 1;
    }
  }
  if (size3 == 0)
  {
    std::cout << "Empty array \n";
  }
  else
  {
    std::cout << getCountMaxElement(arr3, size3) << "\n";
    int* border3 = partitionByEven(arr3, size3);
    std::cout << *border3 << "\n";
  }
  delete[] arr3;
}
