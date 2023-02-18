#include <iostream>
#include <cstring>
#include "DeleteVowelLetters.h"
#include "TakeSimilarLettersInOrder.h"

int main()
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;

  std::cin >> std::noskipws;
  do {
    if (size == capacity) {
      try {
        char *newstr = new char[capacity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; i++, j++) {
          *j = *i;
        }
        delete[] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (...) {
        delete[] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (size <= 1) {
    delete[] cstring;
    std::cerr << "Nothing was entered";
    return 1;
  }
  cstring[size - 1] = '\0';

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
