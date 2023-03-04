#include "checkRealNumber.h"

bool checkSign(const char* str)
{
    return *str == '+' || *str == '-';
}

bool checkDigit(const char* str)
{
    return std::isdigit(*str);
}

bool checkE(const char* str)
{
    return *str == 'E';
}

bool checkUnsignedInt(const char* str)
{
    return checkDigit(str) || checkDigit(str) && checkUnsignedInt(str++);
}

bool checkPoint(const char* str)
{
    return *str == '.';
}

bool checkOrder(const char* str)
{
    return checkE(str) && checkUnsignedInt(str) || checkE(str) && checkSign(str) && checkUnsignedInt(str);
}

bool checkMantissa(const char* str)
{
    return checkUnsignedInt(str) && checkPoint(str) && checkUnsignedInt(str);
}

bool checkRealNumber(const char* str)
{
    return checkMantissa(str) && checkOrder(str) || checkSign(str) && checkMantissa(str) && checkOrder(str);
}
