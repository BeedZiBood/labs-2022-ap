#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>
#include <ctime>
#include "maxCountOfEqualElements.h"
#include "samePositiveElements.h"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cout << "Erorr!";
    return 1;
  }
  const size_t constSize = 7;
  int constArr[constSize]{ 1, 2, 2, 2, 12, 5, 8 };
  std::string ansTrue = "Array has the same positive elements";
  std::string ansFalse = "Array hasn't the same positive elements";
  bool ans1 = isThereTheSamePositiveElements(constArr, constSize);
  std::cout << countMaxQuantityOfEqualElements(constArr, constSize) << "\n";
  std::cout << (ans1 ? ansTrue : ansFalse) << "\n";

  size_t dinamicSize = 0;
  std::cin >> dinamicSize;
  int* dinamicArr = new int[dinamicSize];
  std::srand(time(nullptr));
  for (size_t i = 0; i < dinamicSize; ++i)
  {
    dinamicArr[i] = std::rand();
  }
  bool ans2 = isThereTheSamePositiveElements(dinamicArr, dinamicSize);
  std::cout << countMaxQuantityOfEqualElements(dinamicArr, dinamicSize) << "\n";
  std::cout << (ans2 ? ansTrue : ansFalse) << "\n";
  delete[] dinamicArr;

  std::ifstream file;
  file.open(argv[1]);
  if (!file.is_open())
  {
    std::cout << "Error when you open file\n";
    return 1;
  }
  size_t fileSize = 0;
  file >> fileSize;
  if (!file)
  {
    std::cout << "Error\n";
    return 1;
  }
  int* fileArr = new int[fileSize];
  for (size_t i = 0; i < fileSize; i++)
  {
    file >> fileArr[i];
  }
  file.close();
  bool ans3 = isThereTheSamePositiveElements(fileArr, fileSize);
  std::cout << countMaxQuantityOfEqualElements(fileArr, fileSize) << "\n";
  std::cout << (ans3 ? ansTrue : ansFalse) << "\n";
  delete[] fileArr;

  return 0;
}
