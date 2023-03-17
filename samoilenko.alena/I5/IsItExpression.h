#ifndef ISITEXPRESSION_H
#define ISITEXPRESSION_H
#include <cstddef>

bool isLetter(char);
bool isDigit(char);
bool isIdentificator(char);
bool isAster(char);
bool isSign (char);
bool isBracket(char);
bool isUnsignedInteger(const char*, size_t, size_t);
bool isMult(const char*, size_t, size_t);
bool isTerm(const char*, size_t, size_t);
bool examExpress(const char*, size_t, size_t);
bool outResult(const char*);
#endif
