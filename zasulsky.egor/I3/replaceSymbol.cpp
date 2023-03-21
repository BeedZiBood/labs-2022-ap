#include "replaceSymbol.hpp"

char* zasulsky::replaceSymbol(char* dest, const char* src, char sym, char replSym)
{
  char* newc = dest;
  for (const char* c = src; *c != '\0'; c++) {
    if (*c == sym) {
      *newc = replSym;
    } else {
      *newc = *c;
    }
    newc++;
  }
  *newc = '\0';
  return dest;
}
