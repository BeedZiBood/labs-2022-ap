#include <iostream>
#include <fstream>
#include <stdexcept>
#include "MaxElements.h"
#include "FindRepeatingPositiveNumber.h"

int main(int argc, char* array[])
{
  if (argc != 2)
  {
    std::cerr << "Incorrect number of arguments";
    return 1;
  }

  //1
  const size_t size1 = 10;
  int array1[10] = {1, 1, 1, 1, 9, 9, 2, 4, 3, 2};
  std::cout << "Number of max elements: " << countMaxElements(array1, size1) << "\n";
  std::cout << "Positive repeating numbers: " << findRepeatingPositiveNumber(array1, size1) << "\n\n";

  //2
  size_t size2 = 0;
  std::cin >> size2;
  if (size2 > 0)
  {
    int* array2 = new int[size2];
    std::srand(time(nullptr));
    for (size_t i = 0; i < size2; i++)
    {
      array2[i] = std::rand() % 10;
    }
    std::cout << "Number of max elements: " << countMaxElements(array2, size2) << "\n";
    std::cout << "Positive repeating numbers: " << findRepeatingPositiveNumber(array2, size2) << "\n\n";
    delete[] array2;
  }

  //3
  std::ifstream file;
  std::string name = array[1];
  file.open(name);
  if (file.is_open())
  {
    size_t size3 = 0;
    file >> size3;
    if (file)
    {
      if (size3 > 0)
      {
        int* array3 = new int[size3];
        for (size_t i = 0; i < size3; i++)
        {
          file >> array3[i];
          if (!file)
          {
            std::cout << "File reading error" << "\n";
            delete[] array3;
            return 1;
          }
        }
        std::cout << "Number of max elements: " << countMaxElements(array3, size3) << "\n";
        std::cout << "Positive repeating numbers: " << findRepeatingPositiveNumber(array3, size3) << "\n\n";
        delete[] array3;
      }
    }
    else
    {
      std::cout << "File reading error" << "\n";
      return 1;
    }
  }
  else
  {
    std::cout << "File opening error" << "\n";
    return 1;
  }
  return 0;
}
