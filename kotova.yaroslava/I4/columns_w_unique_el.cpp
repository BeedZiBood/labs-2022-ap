#include "columns_w_unique_el.h"
bool isUnique(const int* matrix, size_t line, size_t& number_column)
{
  bool flag = true;
  size_t line_curr = 1;
  size_t column_curr = 1;
  for (size_t i = line_curr; i < line - 1; i++)
  {
    number_column = matrix[column_curr * i];
    if (matrix[column_curr * line_curr + i] > 0)
    {
      flag = true;
      i++;
    }
    else
    {
      flag = false;
      break;
    }
  }
  return flag;
}
size_t countUniqueElOfCol(const int* matrix, size_t column, size_t line)
{
  size_t columns_curr = 0;
  size_t count = 0;
  for (size_t i = columns_curr; i < column - 1; i++)
  {
    if (isUnique(matrix, line, columns_curr))
    {
      count++;
    }
  }
  return count;
}
