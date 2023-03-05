#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>
#include "printtable.h"
#include "arctan.h"

int main()
{
  const double abs_Error = 0.0001;
  const double m_step = 0.1;
  double m_1 = 0.0;
  double m_2 = 0.0;
  size_t max_Number = 0;

  std::cin >> m_1 >> m_2 >> max_Number;
  if (!std::cin || m_1 < -1.0 || m_2 > 1.0 || m_1 > m_2)
  {
    std::cerr << "Incorrect input\n";
    return 1;
  }
  try
  {
    for (double x = m_1; x <= m_2; x += m_step)
    {
      printTable(std::cout, abs_Error, m_step, x, x + m_step, max_Number);
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}
