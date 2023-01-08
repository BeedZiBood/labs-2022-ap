#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"
bool isTriangle(const point_t &p1, const point_t &p2, const point_t &p3);
double getTriangleArea(const point_t &p1, const point_t &p2, const point_t &p3);
bool isPointInsidetriangle(const point_t &p1, const point_t &p2, const point_t &p3, const point_t point &p0);
#endif
