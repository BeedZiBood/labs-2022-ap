#ifndef WORKWITHSTRS_H
#define WORKWITHSTRS_H

#include <cstddef>

const size_t CAPACITY_BLOCK = 100;

char* pushBack(char* str, size_t& str_size, size_t& str_capasity, const char new_char);

#endif
