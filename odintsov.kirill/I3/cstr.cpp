#include "cstr.hpp"
#include <cstddef>
#include <stdexcept>
#include <cctype>

odintsov::CStringWrapper::CStringWrapper(size_t arrCap):
  arrSize(0),
  arrCap(arrCap),
  str(new char[arrCap])
{
  if (arrCap > 0) {
    str[0] = '\0';
    arrSize = 1;
  }
}

odintsov::CStringWrapper::~CStringWrapper()
{
  delete [] str;
}

void odintsov::CStringWrapper::extend(size_t newCap)
{
  if (newCap <= arrCap) {
    throw std::invalid_argument("Bad capacity");
  }
  char* newStr = new char[newCap];
  for (size_t i = 0; i < arrSize; i++) {
    newStr[i] = str[i];
  }
  delete [] str;
  str = newStr;
  arrCap = newCap;
}

void odintsov::CStringWrapper::append(char c)
{
  if (arrSize == arrCap) {
    extend(arrCap + 20);
  }
  str[arrSize - 1] = c;
  str[arrSize++] = '\0';
}

bool odintsov::isLowerVowel(char c)
{
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool odintsov::isUpperVowel(char c)
{
  return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

bool odintsov::isVowel(char c)
{
  return (isLowerVowel(c) || isUpperVowel(c));
}

char* odintsov::removeLatin(char* dest, const char* src)
{
  char* dptr = dest;
  for (const char* cptr = src; *cptr != '\0'; cptr++) {
    if (!std::isalpha(*cptr)) {
      *(dptr++) = *cptr;
    }
  }
  *dptr = '\0';
  return dest;
}

char* odintsov::removeVowels(char* dest, const char* src)
{
  char* dptr = dest;
  for (const char* cptr = src; *cptr != '\0'; cptr++) {
    if (!isVowel(*cptr)) {
      *(dptr++) = *cptr;
    }
  }
  *dptr = '\0';
  return dest;
}
