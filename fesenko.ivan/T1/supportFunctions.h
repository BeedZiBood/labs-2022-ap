#ifndef SUPPORTFUNCTIONS_H
#define SUPPORTFUNCTIONS_H
#include "shape.h"
void movePoint(point_t &p, double dx, double dy);
void movePointBecauseOfScale(point_t &p, const point_t &zoomCenter, double k);
void fullScale(Shape *shape, const point_t &zoomCenter, double k);
bool isIntersectionOfSegments(const point_t &point1, const point_t &point2, const point_t &point3, const point_t &point4);
point_t getIntersectionPoint(const point_t &point1, const point_t &point2, const point_t &point3, const point_t &point4);
#endif
