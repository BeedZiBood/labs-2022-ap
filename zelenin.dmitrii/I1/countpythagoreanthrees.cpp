#include "countpythagoreanthrees.h"
#include "ispyth.h"

void countPythagoreanThrees(int& value, int& program_launch_number, int& count_of_pythagorean_threes, int& x, int& y, int& z)
{
  if (program_launch_number == 3)
  {
    program_launch_number = 0;
  }
  if (program_launch_number == 0)
  {
    x = value;
  }
  if (program_launch_number == 1)
  {
    y = value;
  }
  if (program_launch_number == 2)
  {
    z = value;
  }
  if (x && y && z)
  {
    if (isPyth(x, y, z) || isPyth(x, z, y) || isPyth(z, y, x))
    {
      count_of_pythagorean_threes++;
    }
  }
}
