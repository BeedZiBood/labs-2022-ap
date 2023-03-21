#include <iostream>
#include "printrow.h"

int main()
{
  double borderleft = 0.0;
  double borderright = 0.0;
  unsigned maxnumber = 0;
  const double step = 0.01;
  const double absError = 0.00001;
  std::cin >> borderleft;
  std::cin >> borderright;
  std::cin >> maxnumber;
  if (!std::cin)
  {
    std::cout << "error";
    return 1;
  }
  if (borderleft >= borderright)
  {
    std::cout << "error";
    return 1;
  }
  printTable(std::cout, borderleft, borderright, step, maxnumber, absError);
}
