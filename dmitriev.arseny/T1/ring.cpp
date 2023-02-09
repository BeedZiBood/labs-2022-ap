#include "ring.h"
#include <exception>

Ring::Ring(point_t center, double externalRadius, double internalRadius) :
	center(center),
	externalRadius(externalRadius),
	internalRadius(internalRadius)
{
	if (externalRadius < internalRadius)
	{
		throw std::exception("invalid argumet");
	}
}

double Ring::getArea() const
{
	double pi = 3.141592653589793;
	return pi * externalRadius * externalRadius - pi * internalRadius * internalRadius;
}

rectangle_t Ring::getFrameRect() const
{
	point_t leftBott{ center.x - externalRadius / 2, center.y - externalRadius / 2 };
	point_t rightTop{ center.x + externalRadius / 2, center.y + externalRadius / 2 };
	return makeNewRect(leftBott, rightTop);
}

void Ring::move(double dx, double dy)
{
	center.x = center.x + dx;
	center.y = center.y + dy;
}

void Ring::move(point_t newPos)
{
	move(newPos.x - center.x, newPos.y - center.y);
}

void Ring::scale(double k)
{
	if (k < 0)
	{
		throw std::exception("invalid argument");
	}
	externalRadius = externalRadius * k;
	internalRadius = internalRadius * k;
}

Shape* Ring::clone()
{
	return new Ring{ center, externalRadius, internalRadius };
}
