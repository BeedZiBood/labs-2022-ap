#include <iostream>
#include <cstddef>
#include <cStrFromInput.h>
#include "defCountDiffLett.h"
#include "createMassAllLettStrs.h"

int main()
{
  char* cStr1 = nullptr;
  try
  {
    cStr1 = createCStrFromInput(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }

  char* cStrAllLett = nullptr;
  try
  {
    cStrAllLett = new char[27];
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    delete[] cStr1;
    return 1;
  }

  char cStr2[] = "az";
  cStrAllLett = createMassAllLettStrs(cStrAllLett, cStr1, cStr2);
  std::cout << cStrAllLett << '\n';

  std::cout << defCountDiffLett(cStr1) << '\n';
  delete[] cStr1;
  delete[] cStrAllLett;

  return 0;
}
