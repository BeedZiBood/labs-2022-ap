#include "readString.h"
#include <iostream>
#include <cstddef>

void customCopy(char *dest, const char *src, size_t count) {
    for (size_t i = 0; i < count; ++i)
    {
        dest[i] = src[i];
    }
}
void readString(char *cstring, size_t initialCapacity, size_t capacityIncrement) {
    size_t capacity = initialCapacity;
    size_t size = 0;
    std::cin >> std::noskipws;
    char inputCharacter;
    while (std::cin >> inputCharacter)
    {
        if (size == capacity - 1)
        {
            char *newString = nullptr;
            try
            {
                newString = new char[capacity + capacityIncrement];
                customCopy(newString, cstring, capacity);
                delete[] cstring;
                cstring = newString;
                capacity += capacityIncrement;
            }
            catch (const std::bad_alloc& e)
            {
                std::cerr << e.what() << '\n';
                delete[] cstring;
                return;
            }
        }
        cstring[size++] = inputCharacter;
        if (inputCharacter == '\n')
        {
            break;
        }
    }
    if (size == 0)
    {
        std::cerr << "Empty string\n";
        delete[] cstring;
        return;
    }
    cstring[size - 1] = '\0';
}
