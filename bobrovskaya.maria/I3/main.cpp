#include <iostream>
#include <CreateCString.h>
#include "CountDifferentLetters.h"
#include "NewStringIndeticalCharacters.h"


int main()
{
  char *source1 = nullptr;
  try
  {
    source1 = createCString(std::cin);
    if (source1[0] == '\0')
    {
      delete[] source1;
      throw std::logic_error("Empty string");
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  size_t countDifLett = countDifLetters(source1);
  std::cout << countDifLett << "\n";
  size_t size2 = 27;
  char source2[] = "adfgvbh";
  char *destination = nullptr;
  try
  {
    destination = new char[size2];
  }
  catch(const std::bad_alloc &e)
  {
    delete[] source1;
    std::cerr << e.what() << '\n';
    return 1;
  }
  destination[size2 - 1] = '\0';
  for (size_t i = 0; i < size2 - 1; i++)
  {
    destination[i] = '.';
  }
  destination = newStringIndeticalCharacters(destination, source1, source2);
  std::cout << destination << "\n";

  delete[] destination;
  delete[] source1;
  return 0;
}
