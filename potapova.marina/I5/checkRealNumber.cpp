#include <cctype>
#include <iostream>
#include "checkRealNumber.h"

bool checkSign(char str)
{
    return str == '+' || str == '-';
}

bool checkDigit(char str)
{
    return std::isdigit(str);
}

bool checkE(char* str)
{
    return *str == 'E';
}

bool checkUnsignedInt(char* str)
{
    return checkDigit(*str) || checkDigit(*str) && checkUnsignedInt(str++);
}

bool checkPoint(char str)
{
    return str == '.';
}

bool checkOrder(char* str)
{
    return checkE(str) && checkUnsignedInt(str) || checkE(str) && checkSign(*str) && checkUnsignedInt(str);
}

bool checkMantissa(char* str)
{
    return checkUnsignedInt(str) && checkPoint(*str) && checkUnsignedInt(str);
}

bool checkRealNumber(char* str)
{
    return checkMantissa(str) && checkOrder(str) || checkSign(*str) && checkMantissa(str) && checkOrder(str);
}
