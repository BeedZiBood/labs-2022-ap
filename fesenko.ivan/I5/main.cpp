#include <iostream>
#include <expandCString.h>
#include "isFloat.h"

int main()
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;
  cstring[0] = '\0';
  std::cin >> std::noskipws;
  do {
    if (size == capacity) {
      try {
        char *newString = expandCString(cstring, size, capacity);
        delete [] cstring;
        cstring = newString;
      }
      catch (const std::exception &e) {
        delete [] cstring;
        std::cerr << e.what() << "\n";
        return 2;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (cstring[0] == '\0' || cstring[0] == '\n') {
    std::cerr << "Error while reading\n";
    delete [] cstring;
    return 2;
  }
  cstring[size - 1] = '\0';
  std::cout << std::boolalpha << isFloat(cstring) << "\n";
  delete [] cstring;
}
