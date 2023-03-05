#ifndef READSTRING_H
#define READSTRING_H
#include <iostream>
#include <cstddef>
char *readString(std::istream &inputStr, size_t &in_size, const size_t increaseCapacity);
#endif
