#include <cstddef>
#include <cstdint>
#include <utility>
#include "getMostCommonSyms.h"

char* getMostCommonSyms(char* dest, const char* str)
{
  std::pair< char, size_t > common_syms[3];
  for (const char* cur_search_sym_ptr = str; *cur_search_sym_ptr != '\0'; ++cur_search_sym_ptr)
  {
    size_t count_commons_sym = 1;
    for (const char* cur_sym_ptr = cur_search_sym_ptr + 1; *cur_sym_ptr != '\0'; ++cur_sym_ptr)
    {
      if (*cur_search_sym_ptr == *cur_sym_ptr)
      {
        ++count_commons_sym;
      }
    }
    for (auto& common_sym: common_syms)
    {
      if (*cur_search_sym_ptr == common_sym.first)
      {
        break;
      }
      if (count_commons_sym > common_sym.second)
      {
        common_sym.first = *cur_search_sym_ptr;
        common_sym.second = count_commons_sym;
        break;
      }
    }
  }
  unsigned int count_valid_syms = 0;
  auto common_sym_ptr = common_syms;
  for (char* dest_sym_ptr = dest; common_sym_ptr < common_syms + 3; ++common_sym_ptr, ++dest_sym_ptr)
  {
    if (common_sym_ptr->first != '\0')
    {
      *dest_sym_ptr = common_sym_ptr->first;
      ++count_valid_syms;
    }
  }
  dest[count_valid_syms] = '\0';
  return dest;
}
