#include <iostream>
#include <expandCString.h>
#include "deleteextraspaces.h"
#include "checkcharacterssimilarity.h"

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
        newString = nullptr;
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
  char *task1 = new char [size];
  task1[0] = '\0';
  deleteExtraSpaces(task1, cstring);
  std::cout << task1 << "\n";
  delete [] task1;
  std::cout << std::boolalpha << checkCharactersSimilarity(cstring) << '\n';
  delete [] cstring;
}
