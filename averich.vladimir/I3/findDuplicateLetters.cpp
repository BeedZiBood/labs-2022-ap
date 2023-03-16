#include "findDuplicateLetters.h"

void uniqueLettersFromLoweredString(bool dictionary[LettersInEnglishAlphabet], const char* c_str)
{
  for (size_t i = 0; i < LettersInEnglishAlphabet; ++i) {
    dictionary[i] = false;
  }
  size_t letters_found = 0;
  while (*c_str && letters_found < LettersInEnglishAlphabet) {
    char c = std::tolower(*c_str);
    if (std::isalpha(c)) {
      size_t idx = c - 'a';
      if (!dictionary[idx]) {
        dictionary[idx] = true;
        ++letters_found;
      }
    }
    ++c_str;
  }
}

void findDuplicateLetters(char* destination, const char* c_string_1, const char* c_string_2)
{
  bool firstStringDictionary[LettersInEnglishAlphabet];
  uniqueLettersFromLoweredString(firstStringDictionary, c_string_1);
  bool secondStringDictionary[LettersInEnglishAlphabet];
  uniqueLettersFromLoweredString(secondStringDictionary, c_string_2);
  bool* uniqueLetters = firstStringDictionary;
  for (size_t i = 0; i < LettersInEnglishAlphabet; ++i) {
    uniqueLetters[i] = firstStringDictionary[i] && secondStringDictionary[i];
  }
  for (size_t i = 0; i < LettersInEnglishAlphabet; ++i) {
    if (uniqueLetters[i]) {
      *destination++ = i + 'a';
    }
  }
  *destination = '\0';
}
