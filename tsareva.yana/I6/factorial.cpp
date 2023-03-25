#include "factorial.h"

unsigned factorial(unsigned number)
{
  return (number == 0) ? 1 : factorial(number - 1) * number;
}
