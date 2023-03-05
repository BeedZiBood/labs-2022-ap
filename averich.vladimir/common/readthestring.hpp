#ifndef READTHESTRING_HPP
#define READTHESTRING_HPP
#include <fstream>
#include <cstddef>
char* readTheString(std::istream& inputStr, size_t& in_size, const size_t increaseCapacity);
#endif
