#include "workWithIO.h"

char* stdinGetLine()
{
    char* result;

    try
    {
        result = new char[CAPACITY_BLOCK];
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Allocation failed: " << e.what() << '\n';
        std::exit(1);
    }

    size_t result_size = 0;
    size_t result_capasity = CAPACITY_BLOCK;

    char cur_char = '\0';
    std::cin >> std::noskipws;
    while (std::cin >> cur_char && cur_char != '\n')
    {
        pushBack(result, result_size, result_capasity, cur_char);
    }

    if (cur_char == '\0')
    {
        delete[] result;

        return nullptr;
    }

    return result;
}
