#include "MakeShapes.hpp"
#include <stdexcept>
#include "Rectangle.hpp"
#include "Ellipse.hpp"
#include "Concave.hpp"
#include "Ring.hpp"

Shape *makeRectangle(std::istream &input)
{
  double dots[4]{0};
  for (double &dot: dots)
  {
    input >> dot;
  }
  checkInput(input);
  return new Rectangle({dots[0], dots[1]}, {dots[2], dots[3]});
}

Shape *makeEllipse(std::istream &input)
{
  double dots[4]{0};
  for (double &dot: dots)
  {
    input >> dot;
  }
  checkInput(input);
  return new Ellipse({dots[0], dots[1]}, dots[2], dots[3]);
}

Shape *makeConcave(std::istream &input)
{
  double dots[8]{0};
  for (double &dot: dots)
  {
    input >> dot;
  }
  checkInput(input);
  return new Concave({dots[0], dots[1]}, {dots[2], dots[3]}, {dots[4], dots[5]}, {dots[6], dots[7]});
}

Shape *makeRing(std::istream &input)
{
  double dots[4]{0};
  for (double &dot: dots)
  {
    input >> dot;
  }
  checkInput(input);

  return new Ring({dots[0], dots[1]}, dots[2], dots[3]);
}

scale_t getScale(std::istream &input)
{
  double dots[3]{0};
  for (double &dot: dots)
  {
    input >> dot;
  }
  checkInput(input);
  if (dots[2] < 0.0)
  {
    throw std::invalid_argument("invalid scale size");
  }
  return {{dots[0], dots[1]}, dots[2]};
}

void checkInput(std::istream &input)
{
  if (input.fail())
  {
    throw std::invalid_argument("invalid input, double as coordinates expected");
  }
}
