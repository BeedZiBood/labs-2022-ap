#include "CStringWrapper.hpp"
#include <stdexcept>
#include <cstddef>

odintsov::CStringWrapper::CStringWrapper(size_t arrCap):
  arrSize(0),
  arrCap(arrCap),
  str(new char[arrCap])
{
  if (arrCap > 0) {
    str[0] = '\0';
    arrSize = 1;
  }
}

odintsov::CStringWrapper::~CStringWrapper()
{
  delete [] str;
}

void odintsov::CStringWrapper::extend(size_t newCap)
{
  if (newCap <= arrCap) {
    throw std::invalid_argument("Bad capacity");
  }
  char* newStr = new char[newCap];
  for (size_t i = 0; i < arrSize; i++) {
    newStr[i] = str[i];
  }
  delete [] str;
  str = newStr;
  arrCap = newCap;
}

void odintsov::CStringWrapper::append(char c)
{
  if (arrSize == arrCap) {
    extend(arrCap + 20);
  }
  str[arrSize - 1] = c;
  str[arrSize++] = '\0';
}
