#include "DeleteVowelLetters.h"
#include <cstddef>

bool isLetterVowel(char letter)
{
  char vowelLetters[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
  for (size_t j = 0; j < 6 ; j++) {
    if (letter == vowelLetters[j]) {
      return true;
    }
  }
  return false;
}

char *deleteVowels(char *result1, const char *source)
{
  size_t num = 0;
  for (size_t i = 0; source[i] != '\0'; i++) {
    bool isVowel = isLetterVowel(source[i]);
    if (!isVowel) {
      result1[num++] = source[i];
    }
  }
  return result1;
}
