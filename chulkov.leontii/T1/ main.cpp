#include <iostream>
#include <iomanip>
#include "shape.h"
#include "basetype.h"
#include "square.h"
#include "circle.h"
#include "rectangle.h"
#include "compositeShape.h"
#include "print.h"

int main()
{
  std::cout << std::setprecision(1) << std::fixed;
  CompositeShape compositeShape;
  while (std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (!std::cin)
    {
      std::cerr << "Error input\n";
      return 1;
    }
  }
  return 0;
}
