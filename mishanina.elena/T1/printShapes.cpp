#include "printShapes.h"

void printShapes(std::ostream& out, const CompositeShape& compositeShape)
{
  out << std::setprecision(1) << std::fixed << compositeShape.getArea();
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    out << " ";
    rectangle_t figure = compositeShape.at(i)->getFrameRect();
    out << figure.pos.x - (figure.width / 2.0) << " ";
    out << figure.pos.y - (figure.height / 2.0) << " ";
    out << figure.pos.x + (figure.width / 2.0) << " ";
    out << figure.pos.y + (figure.height / 2.0);
  }
}
