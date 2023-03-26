#include <iostream>
#include <cstddef>
#include "readTheString.h"
#include "hasDoubledChars.h"
#include "findDuplicateLetters.h"

int main()
{
  try
  {
    char* inputString = new char[];
    inputString = readTheString(std::cin);
    char* resultOfDuplicateTestString = new char[LettersInEnglishAlphabet + 1];
    for (size_t i = 0; i < LettersInEnglishAlphabet + 1; ++i) {
      *(resultOfDuplicateTestString + i) = '\0';
    }
    const char predifinedString[] = "abZ";
    findDuplicateLetters(resultOfDuplicateTestString, inputString, predifinedString);
    std::cout << "All chars of cstring: " << resultOfDuplicateTestString << '\n';
    std::cout << "Repeating chars: " << std::boolalpha << hasDoubledChars(inputString) << '\n';
    delete[] resultOfDuplicateTestString;
    delete[] inputString;
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what() << '\n';
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
