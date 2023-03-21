#ifndef SPBSPU_LABS_2022_AAP_904_A_BASE_TYPES_H
#define SPBSPU_LABS_2022_AAP_904_A_BASE_TYPES_H
namespace dimkashelk
{
  struct point_t
  {
    double x;
    double y;
  };
  struct rectangle_t
  {
    point_t pos;
    double width;
    double height;
  };
}
#endif
