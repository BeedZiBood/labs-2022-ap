#include "findRealNumber.h"
#include <cctype>
const char *skipSign(const char *string)
{
    if (string != nullptr && (*string == '+' || *string == '-'))
    {
        return string + 1;
    }
    return string;
}
const char *skipUnsigned(const char *string)
{
    if (string == nullptr || !isdigit(*string))
    {
        return nullptr;
    }
    return isdigit(*(string + 1)) ? skipUnsigned(string + 1) : string + 1;
}

const char *skipExponent(const char *string)
{
    if (string == nullptr || *(string++) != 'E')
    {
        return nullptr;
    }
    return skipUnsigned(skipSign(string));
}
const char *skipMantissa(const char *string)
{
    string = skipUnsigned(string);
    if (string == nullptr || *string != '.')
    {
        return nullptr;
    }
    return skipUnsigned(string + 1);
}
const char *skipRealNumber(const char *string)
{
    if (string == nullptr)
    {
        return nullptr;
    }
    return skipExponent(skipMantissa(skipSign(string)));
}
bool isRealNumber(const char *string)
{
    string = skipRealNumber(string);
    if (string == nullptr)
    {
        return false;
    }
    return *string == '\0';
}
