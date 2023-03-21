#ifndef MAKECSTRING_HPP
#define MAKECSTRING_HPP

#include <cstddef>
#include <istream>

char *makeCString(char *cstring, size_t &size, size_t &capacity, std::istream &input);

#endif
