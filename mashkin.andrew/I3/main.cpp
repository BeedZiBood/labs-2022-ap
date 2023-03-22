#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <createCString.h>
#include "createNewStringFromThreeOfenLetters.h"
#include "createNewStringFromTwoOther.h"


int main()
{
  char* string1 = nullptr;
  size_t capacity = 10;
  size_t size = 0;
  size_t endIndex = 0;
  try
  {
    string1 = createCString(std::cin, size, capacity);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << "\n";
    delete[] string1;
    return 1;
  }
  char string2[] = "0123456789abcdef";
  char* newStringFromTwoOther = nullptr;
  try
  {
    newStringFromTwoOther = new char[capacity + 1];
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << "\n";
    delete[] string1;
    return 1;
  }
  char* fromThreeLetters = nullptr;
  try
  {
    fromThreeLetters = new char[4];
    for (char* i = string1, *j = fromThreeLetters; endIndex != 3; ++i, ++j, endIndex++)
    {
      *j = *i;
    }
    fromThreeLetters[endIndex] = '\0';
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << "\n";
    delete[] string1;
    delete[] newStringFromTwoOther;
    return 1;
  }
  newStringFromTwoOther = createNewStringFromTwoOther(newStringFromTwoOther, string1, string2, size);
  std::cout << newStringFromTwoOther << "\n";
  fromThreeLetters = createNewStringFromThreeOftenLetters(fromThreeLetters, string1, endIndex);
  std::cout << fromThreeLetters << "\n";
  delete[] string1;
  delete[] newStringFromTwoOther;
  delete[] fromThreeLetters;
  return 0;
}
