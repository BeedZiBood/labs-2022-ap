#include <iostream>
#include <cstring>
#include <ReadString.h>
#include "DeleteVowelLetters.h"
#include "TakeSimilarLettersInOrder.h"

int main()
{
  char* cstring = nullptr;
  try {
    cstring = readString(std::cin);
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
  size_t size = 0;
  for (size_t i = 0; cstring[i] != '\0'; i++) {
    size += 1;
  }

  size_t size2 = 13;
  char *cstring2 = nullptr;
  try {
    cstring2 = new char[size2];
  } catch (const std::bad_alloc& e) {
    delete[] cstring;
    std::cerr << "Unable to allocate memory";
    return 1;
  }
  std::strcpy(cstring2, "Goodmorning!");

  char *cstringWithoutVowels = nullptr;
  try {
    cstringWithoutVowels = new char[size];
  } catch (const std::bad_alloc& e) {
    delete[] cstring;
    delete[] cstring2;
    std::cerr << "Unable to allocate memory";
    return 1;
  }
  cstringWithoutVowels[size - 1] = '\0';
  for (size_t i = 0; i < size - 1; i ++) {
    cstringWithoutVowels[i] = '-';
  }
  deleteVowels(cstringWithoutVowels, cstring);

  size_t sizeArraySimLet = 27;
  char *arraySimilarLetters = nullptr;
  try {
    arraySimilarLetters = new char[sizeArraySimLet];
  } catch (const std::bad_alloc& e) {
    delete[] cstring;
    delete[] cstring2;
    delete[] cstringWithoutVowels;
    std::cerr << "Unable to allocate memory";
    return 1;
  }
  arraySimilarLetters[sizeArraySimLet - 1] = '\0';
  for (size_t i = 0; i < sizeArraySimLet - 1; i ++) {
    arraySimilarLetters[i] = '-';
  }
  lettersInOrder(arraySimilarLetters, cstring, cstring2);

  std::cout << "Array without vowel letters: ";
  for (size_t i = 0; i < size; i++) {
    std::cout << cstringWithoutVowels[i] << " ";
  }
  std::cout << "\n" << "Similar letters in two arrays: ";
  for (size_t i = 0; i < sizeArraySimLet; i++) {
    std::cout << arraySimilarLetters[i] << " ";
  }

  delete[] cstring;
  delete[] cstring2;
  delete[] cstringWithoutVowels;
  delete[] arraySimilarLetters;
  return 0;
}
