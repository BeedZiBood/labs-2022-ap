#include "readthestring.h"

char* readTheString(std::istream& stream, size_t maxStringSize)
{
  char* buf = new char[maxStringSize];
  stream.get(buf, maxStringSize);
  delete[] buf;
  return buf;
}
