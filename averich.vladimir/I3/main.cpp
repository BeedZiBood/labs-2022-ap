#include <iostream>
#include <cstddef>
#include "readTheString.h"
#include "hasDoubledChars.h"
#include "findDuplicateLetters.h"

int main()
{
  char* inputString = nullptr;
  try
  {
    inputString = readTheString(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
    delete inputString;
    return EXIT_FAILURE;
  }
  try
  {
    char* resultOfDuplicateTestString = new char[LettersInEnglishAlphabet + 1];
    for (size_t i = 0; i < LettersInEnglishAlphabet + 1; ++i) {
      *(resultOfDuplicateTestString + i) = '\0';
    }
    const char predifinedString[] = "abZ";
    findDuplicateLetters(resultOfDuplicateTestString, inputString, predifinedString);
    std::cout << "All chars of cstring: " << resultOfDuplicateTestString << '\n';
    delete[] resultOfDuplicateTestString;
  }
  catch (const std::bad_alloc &e)
  {
    delete[] inputString;
    return EXIT_FAILURE;
  }
  std::cout << "Repeating chars: " << std::boolalpha << hasDoubledChars(inputString) << '\n';
  delete[] inputString;
  return EXIT_SUCCESS;
}
