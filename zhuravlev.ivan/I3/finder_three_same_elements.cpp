#include "finder_three_same_elements.h"
#include <utility>
#include <cctype>

char* finderThreeSameElements(char* destination, const char* str)
{
  auto result_string = destination;
  size_t cnt = 0;
  size_t max_cnt = 0;
  size_t prev_max = 0;
  size_t prev_prev_max = 0;
  for (auto i = str; *i != '\0'; ++i)
  {
    for (auto j = str; *j != '\0'; ++j)
    {
      if ((*i == *j) && (std::isalnum(*i)) && (std::isalnum(*j)))
      {
        cnt++;
      }
    }
    if (cnt > max_cnt)
    {
      size_t tmp = prev_max;
      prev_max = max_cnt;
      max_cnt = cnt;
      prev_prev_max = tmp;
      *result_string = *i;
      ++result_string;
    }
    if (cnt >= prev_max && cnt < max_cnt)
    {
      prev_prev_max = prev_max;
      prev_max = cnt;
    }
    if (cnt >= prev_prev_max && cnt < prev_max)
    {
      prev_prev_max = cnt;
    }
    cnt = 0;
  }
  *(result_string) = '\0';
  for (auto k = result_string; *k != '\0'; ++k)
  {
    if (*k < *(k + 1))
    {
      std::swap(*k, *(k + 1));
    }
  }
  return destination;
}
