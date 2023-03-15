#include <cctype>
#include "checkRealNumber.h"

bool checkSign(char sym)
{
    return sym == '+' || sym == '-';
}

bool checkDigit(char sym)
{
    return std::isdigit(sym);
}

char* checkUnsignedInt(char* str)
{
    char* next_check_res;
    if (!checkDigit(*str))
    {
        return nullptr;
    }
    else if ((next_check_res = checkUnsignedInt(++str)) != nullptr)
    {
        return next_check_res;
    }
    return str;
}

bool checkE(char sym)
{
    return sym == 'E';
}

bool checkPoint(char sym)
{
    return sym == '.';
}

char* checkOrder(char* str)
{
    if (checkE(*str))
    {
        if (checkSign(*++str))
        {
            ++str;
        }
        return checkUnsignedInt(str);
    }
    return nullptr;
}

char* checkMantissa(char* str)
{
    if ((str = checkUnsignedInt(str)) != nullptr && checkPoint(*str) && (str = checkUnsignedInt(++str)) != nullptr)
    {
        return str;
    }
    return nullptr;
}

bool checkRealNumber(char* str)
{
    if (checkSign(*str))
    {
        ++str;
    }
    return (str = checkMantissa(str)) != nullptr && checkOrder(str) != nullptr;
}
