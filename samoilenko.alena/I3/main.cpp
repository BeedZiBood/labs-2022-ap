#include <iostream>
#include <string_from_input.h>
#include "latin_letters.h"
#include "most_common_characters.h"

int main()
{
  char* cstring = nullptr;
  const size_t newsize = 27;
  const size_t newnewsize = 4;
  try
  {
    cstring = makeStringFromInput(std::cin);
  }
  catch (const std::exception &ex)
  {
    std::cout << ex.what() << "\n";
    return 1;
  }
  std::cout << cstring << "\n";
  char* newstring = nullptr;
  try
  {
    newstring = new char[newsize];
  }
  catch (const std::bad_alloc& ex)
  {
    delete[] cstring;
    std::cerr << "Error..." << '\n';
    return 1;
  }
  std::cout << createStringNewLatinLetters(newstring, cstring);
  std::cout << '\n';
  delete[] newstring;
  try
  {
    newstring = new char[newnewsize];
  }
  catch (const std::bad_alloc& ex)
  {
    delete[] cstring;
    std::cerr << ex.what() << '\n';
    return 1;
  }
  std::cout << printMostCommonCharacters(newstring, cstring);
  std::cout << '\n';
  delete[] newstring;
  delete[] cstring;
  return 0;
}
