#include <iostream>
#include <stdexcept>
#include <limits>
#include "max_seq_cnt.h"
#include "cnt_prev_devisor.h"

int main()
{
  MaxSeqRow max_sr{1};
  CntDevPrev cnt_dev{0};
  int value = 0;

  do
  {
    std::cin >> value;
    try
    {
      max_sr(value);
      cnt_dev(value);
    }
    catch (const std::overflow_error& e)
    {
      std::cout << e.what() << "\n";
      return 1;
    }
  }
  while (value && std::cin);
  {
    if (!std::cin)
    {
      std::cout << "You've entered something wrong.....";
      return 2;
    }
    std::cout << "Maximum equal elements in the row: " << max_sr.max_seq_row << "\n";
    std::cout << "Number of elements which have good devisor: " << cnt_dev.cnt_dev << "\n";
    return 0;
  }
}
