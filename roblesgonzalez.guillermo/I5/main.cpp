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
    try
    {
        if (string == nullptr)
        {
            throw std::runtime_error("Failed to read string");
        }
        std::cout << std::boolalpha << isRealNumber(string) << '\n';
        delete[] string;
    }
    catch (const std::exception& err)
    {
        std::cout << "Error: " << err.what() << '\n';
        return 1;
    }
    return 0;
}
