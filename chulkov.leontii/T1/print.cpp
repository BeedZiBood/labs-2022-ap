#include "print.h"
#include <iostream>
#include "compositeShape.h"

void printTable(const CompositeShape& cShp)
{
  for (size_t i = 0; i < cShp.size(); ++i) {
    double minX = cShp[i]->getFrameRect().pos_.x;
    minX -= cShp[i]->getFrameRect().width_ / 2;
    double minY = cShp[i]->getFrameRect().pos_.y;
    minY -= cShp[i]->getFrameRect().height_ / 2;
    double maxX = cShp[i]->getFrameRect().pos_.x;
    maxX += cShp[i]->getFrameRect().width_ / 2;
    double maxY = cShp[i]->getFrameRect().pos_.y;
    maxY += cShp[i]->getFrameRect().height_ / 2;
    std::cout << " " << minX;
    std::cout << " " << minY;
    std::cout << " " << maxX;
    std::cout << " " << maxY;
  }
}