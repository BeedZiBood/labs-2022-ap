#include "Ring.hpp"
#include <stdexcept>
#include "Ellipse.hpp"

Ring::Ring(point_t center, double r1, double r2):
  EllipseOne_(new Ellipse({center.x, center.y}, r1, r1)),
  EllipseTwo_(nullptr)
{
  try
  {
    EllipseTwo_ = new Ellipse({center.x, center.y}, r2, r2);
  }
  catch (...)
  {
    delete EllipseOne_;
    throw;
  }

  if (EllipseOne_->getArea() < EllipseTwo_->getArea())
  {
    delete EllipseOne_;
    delete EllipseTwo_;
    throw std::invalid_argument("Bad input, invalid ellipses radius's, => invalid ring");
  }
}

double Ring::getArea() const
{
  return (EllipseOne_->getArea() - EllipseTwo_->getArea());
}

rectangle_t Ring::getFrameRect() const
{
  return EllipseOne_->getFrameRect();
}

void Ring::move(point_t position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}

void Ring::move(double delta_x, double delta_y)
{
  EllipseOne_->move(delta_x, delta_y);
  EllipseTwo_->move(delta_x, delta_y);
}

void Ring::makeScale(double k)
{
  EllipseOne_->makeScale(k);
  EllipseTwo_->makeScale(k);
}

Shape *Ring::clone() const
{
  point_t center = EllipseOne_->getFrameRect().pos;
  double r1 = EllipseOne_->getFrameRect().width;
  double r2 = EllipseTwo_->getFrameRect().width;
  return new Ring(center, r1, r2);
}

Ring::~Ring()
{
  delete EllipseOne_;
  delete EllipseTwo_;
}
