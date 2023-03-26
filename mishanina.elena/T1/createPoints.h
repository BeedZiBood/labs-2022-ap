#ifndef CREATEPOINTS_H
#define CREATEPOINTS_H
#include <cstddef>
#include <stdexcept>
#include <istream>
#include "base-types.h"

double* createCoordinates(std::istream& in, std::size_t size);
point_t* fillPoints(double *coordinates, std::size_t size);

#endif
