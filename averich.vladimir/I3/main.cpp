#include <iostream>
#include <cstddef>
#include <readthestring.h>
#include "hasdoubledchars.h"
#include "findduplicateletters.h"

int main()
{
  constexpr size_t MaxStringSize = 256;
  char* inputString = readTheString(std::cin, MaxStringSize);
  if (!inputString || *inputString == '\0') {
    std::cerr << "Input string is empty" << '\n';
    if (inputString) {
      delete[] inputString;
    }
    return EXIT_FAILURE;
  }
  char* resultOfDuplicateTestString = new char[LettersInEnglishAlphabet + 1];
  for (size_t i = 0; i < LettersInEnglishAlphabet + 1; ++i) {
    *(resultOfDuplicateTestString + i) = '\0';
  }
  if (!resultOfDuplicateTestString) {
    delete[] inputString;
    return EXIT_FAILURE;
  }
  const char predifinedString[] = "abZ";
  findDuplicateLetters(resultOfDuplicateTestString, inputString, predifinedString);
  std::cout << "All chars of cstring: " << resultOfDuplicateTestString << '\n';
  std::cout << "Repeating chars: " << std::boolalpha << hasDoubledChars(inputString) << '\n';
  delete[] inputString;
  delete[] resultOfDuplicateTestString;
  return EXIT_SUCCESS;
}
