#include "printShapes.hpp"
#include <iomanip>

void printRectangle(std::ostream &output, const Shape *shape)
{
  rectangle_t temp = shape->getFrameRect();
  output << temp.pos.x - (temp.width / 2.0) << " ";
  output << temp.pos.y - (temp.height / 2.0) << " ";
  output << temp.pos.x + (temp.width / 2.0) << " ";
  output << temp.pos.y + (temp.height / 2.0);
}

void printAreaSum(std::ostream &output, const CompositeShape &compositeShape)
{
  output << std::setprecision(1) << std::fixed << compositeShape.getArea();
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    output << " ";
    printRectangle(output, compositeShape.at(i));
  }
}
