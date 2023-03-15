#include <iostream>
#include <cstddef>
#include <readTheString.h>
#include "hasDoubledChars.h"
#include "findDuplicateLetters.h"

int main()
{
  char* inputString = readTheString();
  if (!inputString) {
    return EXIT_FAILURE;
  }
  
  char* resultOfDuplicateTestString = new char[LettersInEnglishAlphabet + 1];
  if (!resultOfDuplicateTestString) {
    delete [] inputString;
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
