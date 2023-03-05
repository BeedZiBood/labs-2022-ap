#include <cstddef>
int main()
{
  size_t size = 0;
  char* cstring = nullptr;
  size_t increaseCapacity = 10;
  char* destination = nullptr;
  char cstringInside[] = "ab";
  delete[] cstring;
  delete[] destination;
  return 0; 
}
