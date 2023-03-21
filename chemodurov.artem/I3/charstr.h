#ifndef CHARSTR_H
#define CHARSTR_H
#include <cstddef>

namespace chemodurov
{
  char * addNumbersToFirst(char * str_result, const char * str_first, const char * str_second);
  bool isRepeatingNumbers(const char * c_string);
  char * deleteVowels(char * str_result, const char * c_string);
}
#endif
