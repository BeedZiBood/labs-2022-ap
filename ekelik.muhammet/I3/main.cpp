#include <iostream>
#include <cstddef>
#include <myString.h>
#include "commonSymbols.h"
#include "uncommonSymbols.h"

int main()
{
  size_t size = 0;
  size_t capacity = 10;

  char* source1 = makeMyString(size, capacity, std::cin);
  if (source1[0] == '\n')
  {
    delete[] source1;
    std::cerr << "Error: empty string \n";
    return 2;
  }

  // Task 5
  char source2[] = "0123456789abcdefglmn";
  char* mySymbols = nullptr;
  try
  {
    mySymbols = new char[size + 1];
    mySymbols[size] = '\0';
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: \n" << e.what();
    delete[] source1;
    return 1;
  }
  findUncommonSymbols(mySymbols, source1, source2);
  std::cout << "Uncommon symbols: " << mySymbols << '\n';

  // Task 19
  size_t symbols = 0;
  char* myCommonSymbols = nullptr;
  try
  {
    myCommonSymbols = new char[4];
    myCommonSymbols[symbols] = '\0';
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: \n" << e.what();
    delete[] source1;
    delete[] mySymbols;
    return 1;
  }
  findCommonSymbols(myCommonSymbols, source1);
  std::cout << "Common symbols: " << myCommonSymbols << '\n';

  delete[] source1;
  delete[] mySymbols;
  delete[] myCommonSymbols;
  return 0;
}
