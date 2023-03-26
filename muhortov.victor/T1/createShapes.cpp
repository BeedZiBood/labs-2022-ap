#include "createShapes.hpp"
#include <stdexcept>
#include "rectangle.hpp"
#include "ring.hpp"
#include "concave.hpp"
#include "diamond.hpp"

void checkingInput(std::istream &input)
{
  if (!input)
  {
    throw std::invalid_argument("Invalid argument");
  }
}

double *inputInArr(std::istream &input, double *positions, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    input >> positions[i];
    checkingInput(input);
  }
  return positions;
}

Shape *createRectangle(std::istream &input)
{
  double positions[4] {0.0, 0.0, 0.0, 0.0};
  inputInArr(input, positions, 4);
  return new Rectangle({positions[0], positions[1]},{positions[2], positions[3]});
}

Shape *createRing(std::istream &input)
{
  double positions[4] {0.0, 0.0, 0.0, 0.0};
  inputInArr(input, positions, 4);
  return new Ring({positions[0], positions[1]},positions[2], positions[3]);
}

Shape *createConcave(std::istream &input)
{
  double positions[8] {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  inputInArr(input, positions, 8);
  return new Concave({positions[0], positions[1]}, {positions[2], positions[3]}, {positions[4], positions[5]}, {positions[6], positions[7]});
}

Shape *createDiamond(std::istream &input)
{
  double positions[6] {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  inputInArr(input, positions, 6);
  return new Diamond({positions[0], positions[1]}, {positions[2], positions[3]}, {positions[4], positions[5]});
}

scale_t getScale(std::istream &input)
{
  double positions[3] {0.0, 0.0, 0.0};
  inputInArr(input, positions, 3);
  if (positions[2] < 0.0)
  {
    throw std::invalid_argument("invalid scale size");
  }
  return {{positions[0], positions[1]}, positions[2]};
}
