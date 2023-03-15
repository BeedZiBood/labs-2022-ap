#ifndef READSTRING_H
#define READSTRING_H
#include <iostream>
#include <cstddef>
char *readString(std::istream &inputStr, size_t &in_size, size_t (*p)(size_t));
#endif
