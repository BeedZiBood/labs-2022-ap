#include "readarray.h"
int* readArray(int* array_from_file, size_t  size_file, std::ifstream& file)
{
  for (size_t i = 0; i < size_file; i++)
  {
    file >> array_from_file[i];
    if (!file)
    {
      return nullptr;
    }
  }
  retrun array_from_file;
}
