#include <iostream>
#include <readString.h>
#include "isRepeatingElements.h"
#include "deleteSpaces.h"
#include "increaseCapacityAdd20.h"
int main()
{
  char *cstring = nullptr;
  size_t size = 0;
  try
  {
    cstring = readString(std::cin, size, increaseCapacityAdd20);
  }
  catch (const std::runtime_error &e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  if (cstring[0] == '\0')
  {
    std::cout << "Empty string" << "\n";
    delete[] cstring;
    return 1;
  }
  try
  {
    std::cout << std::boolalpha << isRepeatingElements(cstring) << "\n";
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << e.what() << "\n";
    delete[] cstring;
    return 1;
  }
  try
  {
    char *strwithoutspaces = new char[size];
    deleteSpaces(strwithoutspaces, cstring);
    std::cout << strwithoutspaces << "\n";
    delete[] strwithoutspaces;
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what();
    delete[] cstring;
    return 2;
  }
  delete[] cstring;
}
