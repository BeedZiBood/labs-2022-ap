#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
	explicit Rectangle(point_t left, point_t right);

	double getArea() const override;
	rectangle_t getFrameRect() const override;
	void move(double dx, double dy) override;
	void move(point_t newPosition) override;
	void scale(double k) override;
	Shape* clone() const override;

private:
	point_t left;
	point_t right;

};

#endif
