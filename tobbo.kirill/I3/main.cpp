#include <iostream>
#include <limits>
#include <stdexcept>
#include "cstrfnc_lab3.h"
#include "cstrfnc.h"

void removeLatinVowelHelper(std::pair< char*, size_t > src)
{
  char* destination = nullptr;
  try
  {
    destination = new char[src.second + 1];
    char* res = removeLatinVowelSymbols(destination, src.first);
    std::cout << src.first << " => " << res << "\n";
  }
  catch (const std::exception& e)
  {
    delete[] destination;
    throw e;
  }
  delete[] destination;
}

int main()
{
  int rc = 0;
  std::pair< char*, size_t > strPair1 = std::make_pair(nullptr, 0);
  std::pair< char*, size_t > strPair2 = std::make_pair(nullptr, 0);
  try
  {
    std::cout << "Enter string#1: ";
    strPair1 = getCString(std::cin);
    std::cout << "Enter string#2: ";
    strPair2 = getCString(std::cin);
    if (strPair1.second == 1 && strPair2.second == 1)
    {
      throw std::invalid_argument("Two empty strings are forbidden by test#1");
    }

    bool res = isIntersectedStrings(strPair1.first, strPair2.first);
    std::cout << "There is " << (res ? "" : "NO") << " intersect symbols\n";

    removeLatinVowelHelper(strPair1);
    removeLatinVowelHelper(strPair2);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    rc = 1;
  }
  if (strPair1.first)
  {
    delete[] strPair1.first;
  }
  if (strPair2.first)
  {
    delete[] strPair2.first;
  }
  return rc;
}
