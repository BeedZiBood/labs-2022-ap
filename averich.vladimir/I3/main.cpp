#include <iostream>
#include <cstddef>
#include <readTheString.h>
#include "hasDoubledChars.h"
#include "findDuplicateLetters.h"

int main()
{
  size_t size = 0;
  char* inputString = new char[size];
  try
  {
    inputString = readTheString(std::cin, size);
  }
  catch (const std::runtime_error& e)
  {
    std::cout << e.what() << "\n";
    delete[] inputString;
    return EXIT_FAILURE;
  }
  if (!inputString) {
    std::cerr << "Input string is empty" << '\n';
    delete[] inputString;
    return EXIT_FAILURE;
  }
  char* resultOfDuplicateTestString = new char[LettersInEnglishAlphabet + 1];
  if (!resultOfDuplicateTestString) {
    delete[] inputString;
    return EXIT_FAILURE;
  }
  for (size_t i = 0; i < LettersInEnglishAlphabet + 1; ++i) {
    *(resultOfDuplicateTestString + i) = '\0';
  }
  const char predifinedString[] = "abZ";
  findDuplicateLetters(resultOfDuplicateTestString, inputString, predifinedString);
  std::cout << "All chars of cstring: " << resultOfDuplicateTestString << '\n';
  std::cout << "Repeating chars: " << std::boolalpha << hasDoubledChars(inputString) << '\n';
  delete[] inputString;
  delete[] resultOfDuplicateTestString;
  return EXIT_SUCCESS;
}
