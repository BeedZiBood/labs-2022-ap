#include <iostream>
#include <cstddef>
#include <readthestring.hpp>
int main()
{
  size_t size = 0;
  char* cstring = nullptr;
  size_t increaseCapacity = 10;
  try
  {
    cstring = readTheString(std::cin, size, increaseCapacity);
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }
  char* destination = nullptr;
  char cstringInside[] = "ab";
  delete[] cstring;
  delete[] destination;
  return 0; 
}
