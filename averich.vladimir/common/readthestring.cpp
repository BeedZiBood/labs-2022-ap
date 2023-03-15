#include "readthestring.h"
#include <iostream>
char* readTheString()
{
  char* string = nullptr;
  size_t const buf_size = 256;
  char buf[buf_size];
  
  while (true)
  {
    char* result = std::fgets(buf, buf_size, stdin);
    if (result)
    {
      string = result;
      // len
      // allocate string
      // copy data written
      break;
    }
    // if eof?
    // copy data written
    // read again
    // else free allocated memory
    // return nullptr
  }
  return string;
}