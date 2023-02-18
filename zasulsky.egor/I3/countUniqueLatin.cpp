#include "countUniqueLatin.hpp"
#include <cctype>
#include <cstddef>

bool isFirstOccurence(const char* cstr, const char* symPtr)
{
  for (const char* c = cstr; (c != symPtr) && (*c != '\0'); c++) {
    if (*c == *symPtr) {
      return false;
    }
  }
  return true;
}

unsigned short zasulsky::countUniqueLatin(const char* cstr)
{
  unsigned short count = 0;
  for (const char* c = cstr; *c != '\0'; c++) {
    if (std::isalpha(*c) && isFirstOccurence(cstr, c)) {
      count++;
    }
  }
  return count;
}
