#include "Vowel.hpp"

char *findVowel(char *destination, const char *cstring)
{
  char latin_vowel_symbols[] = "AaEeIiOoUuYy";
  size_t vowel_counter = 0;
  for (const char *i = cstring; *i != '\0'; i++)
  {
    for (char *j = latin_vowel_symbols; *j != '\0'; j++)
    {
      if (*i == *j && *i != ' ')
      {
        destination[vowel_counter] = *i;
        vowel_counter++;
        *j = ' ';
        break;
      }
    }
  }

  destination[vowel_counter] = '\0';

  return destination;
}
