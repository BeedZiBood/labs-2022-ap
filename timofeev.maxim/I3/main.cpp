#include <iostream>
#include <inputStr.h>
#include "removeAlphabet.h"
#include "addNumbersFromSecondToFirst.h"
int main()
{
  char *str = nullptr;
  size_t size = 0;
  try
  {
    str = inputStr(std::cin, size);
  }
  catch (const std::runtime_error &e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  const size_t siz = 5;
  const char str2[siz] = "1111";
  char *outstring1 = nullptr;
  try
  {
    outstring1 = new char[size];
  }
  catch (const std::bad_alloc &e)
  {
    delete [] str;
    std::cout << "Memory error1" << "\n";
    return 1;
  }
  try
  {
    removeAlphabet(outstring1, str);
  }
  catch (...)
  {
    std::cerr << "Error" << "\n";
    delete [] outstring1;
    delete [] str;
    return 1;
  }
  if (outstring1[0] != '\0')
  {
    std::cout << outstring1 << "\n";
    delete [] outstring1;
  }
  else
  {
    std::cerr << "only alpha were in string" << "\n";
    delete [] outstring1;
  }
  char *outstring2 = nullptr;
  try
  {
    outstring2 = new char[size + siz];
  }
  catch (const std::bad_alloc &e)
  {
    delete [] str;
    std::cout << "Memory error2" << "\n";
    return 1;
  }
  try
  {
    addNumbers(outstring2, str, str2);
  }
  catch (...)
  {
    std::cerr << "Error" << "\n";
    delete [] outstring2;
    delete [] str;
    return 1;
  }
  if (outstring2[0] != '\0')
  {
    std::cout << outstring2 << "\n";
    delete [] outstring2;
  }
  else
  {
    delete [] outstring2;
    std::cerr << "Error" << "\n";
  }
  delete [] str;
}

