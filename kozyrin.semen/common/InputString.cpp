#include "InputString.h"

char* inputString(std::istream& stream, size_t& size)
{
  stream >> std::noskipws;
  size_t capacity = 20;
  size = 0;
  char* str = new char[capacity]{0};

  do {
    if (size + 1 == capacity) {
      capacity += 20;
      char* temp = new char[capacity]{0};
      for (size_t i = 0; i <= size; ++i) {
        temp[i] = str[i];
      }
      delete[] str;
      str = temp;
    }
    stream >> str[size];
  } while(str[size++] != '\n' && stream);

  str[size - 1] = '\0';
  return str;
}
