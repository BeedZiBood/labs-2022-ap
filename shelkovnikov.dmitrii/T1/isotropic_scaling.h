#ifndef SPBSPU_LABS_2022_AAP_904_A_ISOTROPIC_SCALING_H
#define SPBSPU_LABS_2022_AAP_904_A_ISOTROPIC_SCALING_H
#include "shape.h"
namespace dimkashelk
{
  void isotropicScaling(Shape *shape, point_t point, double k);
  void unsafeIsotropicScaling(Shape *shape, point_t point, double k);
}
#endif
