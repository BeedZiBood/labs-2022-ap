#ifndef SPBSPU_LABS_2022_AAP_904_A_INPUTSTRING_H
#define SPBSPU_LABS_2022_AAP_904_A_INPUTSTRING_H
#include <iostream>
#include <cstddef>
#include <cstring>
char *expandString(const char *oldString, size_t oldSize, size_t delta);
char *scanStr(size_t &length, std::istream &in);
#endif
