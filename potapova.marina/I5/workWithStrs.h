#ifndef WORK_WITH_STRS_H
#define WORK_WITH_STRS_H

#include <utility>
#include <algorithm>

const size_t CAPACITY_BLOCK = 100;

void pushBack(char*& str, size_t& str_size, size_t& str_capasity, const char& new_char);
std::pair< char*, char* > strCopy(const char* str);

#endif
