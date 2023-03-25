#include "isExpression.hpp"
#include <cctype>

char* skipIdentifier(char* cptr)
{
  if (*cptr >= 'a' && *cptr <= 'e') {
    return cptr + 1;
  }
  return nullptr;
}

char* skipDigit(char* cptr)
{
  if (std::isdigit(*cptr)) {
    return cptr + 1;
  }
  return nullptr;
}

char* skipUnsigned(char* cptr)
{
  cptr = skipDigit(cptr);
  if (cptr == nullptr) {
    return nullptr;
  }
  char* testptr = skipUnsigned(cptr);
  if (testptr == nullptr) {
    return cptr;
  }
  return testptr;
}

char* skipModifier(char* cptr)
{
  char* testptr = skipUnsigned(cptr);
  if (testptr == nullptr) {
    testptr = skipIdentifier(cptr);
  }
  return testptr;
}

char* skipTerm(char* cptr)
{
  cptr = skipModifier(cptr);
  if (cptr != nullptr && *cptr == '*') {
    return skipTerm(cptr + 1);
  }
  return cptr;
}

char* skipExpression(char* cptr)
{
  cptr = skipTerm(cptr);
  if (cptr != nullptr && (*cptr == '+' || *cptr == '-')) {
    return skipExpression(cptr + 1);
  }
  return cptr;
}

bool zasulsky::isExpression(char* cstring)
{
  cstring = skipExpression(cstring);
  return (cstring != nullptr && *cstring == '\0');
}
