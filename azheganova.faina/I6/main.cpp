#include <iostream>

int main()
{
  double borderleft = 0.0;
  double borderright = 0.0;
  int maxnumber = 0;
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

}