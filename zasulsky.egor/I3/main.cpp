#include <iostream>
#include <cstddef>
#include <tuple>
#include "countUniqueLatin.hpp"
#include "replaceSymbol.hpp"
#include "readString.hpp"

int main()
{
  std::tuple< char*, size_t, size_t > stringData = zasulsky::readString(std::cin);
  char* cstring = std::get< 0 >(stringData);
  size_t size = std::get< 1 >(stringData);
  if (size == 1) {
    std::cout << "Empty string\n";
    delete [] cstring;
    return 1;
  }

  char* newstr = nullptr;
  try {
    newstr = new char[size + 1];
  } catch (...) {
    delete [] cstring;
    delete [] newstr;
    return 1;
  }
  std::cout << zasulsky::replaceSymbol(newstr, cstring, 'e', 'a') << '\n';
  delete [] newstr;

  std::cout << zasulsky::countUniqueLatin(cstring) << '\n';

  delete [] cstring;
}
