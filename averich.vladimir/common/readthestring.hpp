#ifndef READTHESTRING_HPP
#define READTHESTRING_HPP
#include <fstream>
#include <cstddef>
char* readTheString(std::istream& inputString, size_t& inputSize, const size_t increaseCapacity);
#endif
