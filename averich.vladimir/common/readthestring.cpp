#include "readthestring.h"

char* readTheString()
{
  const size_t MaxStringSize = 256;
  char buf[MaxStringSize] = { 0 };
  char* result = std::fgets(buf, MaxStringSize, stdin);
  if (result) {
    size_t strLength = 0;
    while (*result != '\0' && *result != '\n') {
      ++strLength;
      ++result;
    }
    if (strLength > 0) {
      result = new char[strLength + 1];
      for (size_t i = 0; i < strLength; ++i) {
        result[i] = buf[i];
      }
      result[strLength] = '\0';
      return result;
    }
  }
  return nullptr;
}
