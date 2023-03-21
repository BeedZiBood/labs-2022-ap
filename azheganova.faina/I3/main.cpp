#include <iostream>
#include <cstddef>
#include <inputstring.h>
#include "countdifferentletters.h"
#include "findrepeatedsymbols.h"

int main()
{
  char * cstring = nullptr;
  try
  {
    cstring = inputString(std::cin);
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << cstring << "\n";
  std::cout << countDifferentLetters(cstring) << '\n';
  std::cout << findRepeatedSymbols(cstring) << '\n';
  delete [] cstring;
}
