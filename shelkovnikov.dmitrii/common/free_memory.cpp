#include "free_memory.h"
void free_memory(char** strings, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete[] strings[i];
  }
  delete[] strings;
}
