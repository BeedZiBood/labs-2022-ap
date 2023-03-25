#include <cctype>
#include <utility>
#include "addAllLatinLetters.h"

bool isInStr(const char* str, const char c)
{
  for (; *str != '\0'; ++str)
  {
    if (*str == c)
    {
      return true;
    }
  }
  return false;
}

void strSort(char* str)
{
  for (char* cur_sym_ptr = str + 1; *cur_sym_ptr != '\0'; ++cur_sym_ptr)
  {
    char* before_sym_ptr = cur_sym_ptr - 1;
    while (before_sym_ptr >= str && *before_sym_ptr > *(before_sym_ptr + 1))
    {
      std::swap(*before_sym_ptr, *(before_sym_ptr + 1));
      --before_sym_ptr;
    }
  }
}

char* addLatinLetsFromStr(const char* const all_latin_lets, char* all_latin_lets_end_ptr, const char* str)
{
  for (; *str != '\0'; ++str)
  {
    char in_lower_case = static_cast< char >(std::tolower(static_cast< int >(*str)));
    if (std::isalpha(*str) && !isInStr(all_latin_lets, in_lower_case))
    {
      *all_latin_lets_end_ptr++ = in_lower_case;
      *all_latin_lets_end_ptr = '\0';
    }
  }
  return all_latin_lets_end_ptr;
}

char* addAllLatinLets(char* dest, const char* str1, const char* str2)
{
  char* destEndPtr = dest;
  *destEndPtr = '\0';
  destEndPtr = addLatinLetsFromStr(dest, destEndPtr, str1);
  destEndPtr = addLatinLetsFromStr(dest, destEndPtr, str2);
  *destEndPtr = '\0';
  strSort(dest);
  return dest;
}
