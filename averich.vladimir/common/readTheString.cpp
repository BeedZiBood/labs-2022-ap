#include "readTheString.h"

#include <string>
char* readTheString(std::istream& stream)
{
  std::string string;
  std::getline(std::cin, string);
  char* buf = new char[string.size() + 1];
  if (buf) {
    char const* p = string.c_str();
    for (size_t i = 0; i < string.size() + 1; ++i) {
      buf[i] = p[i];
    }
  }
  return buf;
}

