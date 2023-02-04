#ifndef COMPOSITESHAPE
#define COMPOSITESHAPE

#include "shape.h"

class CompositeShape
{
public:
	CompositeShape();
	CompositeShape(CompositeShape&& otherShape);
	CompositeShape(const CompositeShape& otherShape);

	~CompositeShape();

	CompositeShape& operator=(const CompositeShape&& otherShape);

	double getArea();
	rectangle_t getFrameRect();
	void move(double x, double y);
	void move(point_t pos);
	void scale(double k);

private:
	Shape** arr;
	unsigned size;
	unsigned capacity;

	void clear();
};

#endif
