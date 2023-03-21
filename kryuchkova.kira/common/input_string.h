#ifndef INPUT_STRING_HPP
#define INPUT_STRING_HPP
#include <cstddef>
#include <utility>
#include <istream>

std::pair< size_t, char * > inputString(std::istream &in);

#endif
