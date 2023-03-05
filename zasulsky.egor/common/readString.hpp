#ifndef READSTRING_HPP
#define READSTRING_HPP

#include <iostream>
#include <tuple>

namespace zasulsky {
  std::tuple< char*, size_t, size_t > readString(std::istream& in);
}

#endif
