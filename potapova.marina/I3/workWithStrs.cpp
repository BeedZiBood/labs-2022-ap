#include "workWithStrs.h"

char* reallocMem(char* str, const size_t& new_capasity)
{
  char* new_mem_block;
  new_mem_block = new char[new_capasity];
  char* new_char_ptr = new_mem_block;
  for (char* old_char_ptr = str; *old_char_ptr != '\0'; ++old_char_ptr, ++new_char_ptr)
  {
    *new_char_ptr = *old_char_ptr;
  }
  *new_char_ptr = '\0';
  delete[] str;
  return new_mem_block;
}

char* pushBack(char* str, size_t& str_size, size_t& str_capasity, const char new_char)
{
  char* result = str;
  if (str_size == str_capasity - 1)
  {
    str_capasity += CAPACITY_BLOCK;
    result = reallocMem(str, str_capasity);
  }
  result[str_size++] = new_char;
  result[str_size] = '\0';
  return result;
}
