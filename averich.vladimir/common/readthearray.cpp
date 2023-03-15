#include "readthearray.hpp"
<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <cstddef>
#include <cctype>
=======
>>>>>>> master
std::istream& readTheArray(std::istream& in, size_t sizeOfFileArray, int* fileArray)
{
  for (size_t i = 0; i < sizeOfFileArray; i++)
  {
    in >> fileArray[i];
    if (!in)
    {
      return in;
    }
  }
  return in;
}
