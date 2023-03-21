#include <iostream>
#include <limits>
#include <stdexcept>
#include "ElMoreThanPrev.h"
#include "CounterElAfterMax.h"

int main()
{
  int curr = 0;
  ElMoreThanPrev el_more_th_prev;
  CounterElAfterMax cnt_el_af_max;
  do
  {
    std::cin >> curr;
    if (std::cin)
    {
      try
      {
        el_more_th_prev(curr);
        cnt_el_af_max(curr);
      }
      catch (const std::overflow_error& e)
      {
        std::cout << e.what();
        return 2;
      }
    }
  }
  while (curr && std::cin);
  if (!std::cin)
  {
    std::cout << "Error.";
    return 1;
  }
  std::cout << el_more_th_prev.count - 1 << '\n';
  std::cout << cnt_el_af_max.count<< '\n';
}
