#include <iostream>
#include <stdexcept>
#include "findRealNumber.h"
#include "readString.h"

int main()
{
    char* string = new char[10];
    size_t size = 10;
    size_t discard = 0;

    readString(string, size, discard);
if (discard == 0) {
    std::cout << "Error: Empty string" << '\n';
    delete[] string;
    return 1;
}

    try
    {
        std::cout << std::boolalpha << isRealNumber(string) << '\n';
    }
    catch (const std::exception& err)
    {
        std::cerr << "Error: " << err.what() << '\n';
        delete[] string;
        return 1;
    }
    delete[] string;
    return 0;
}
