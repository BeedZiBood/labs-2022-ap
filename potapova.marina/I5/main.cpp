#include "workWithStrs.h"
#include "checkRealNumber.h"
#include "workWithIO.h"

int main()
{
    const char* const input_str = stdinGetLine();

    if (input_str == nullptr)
    {
        std::cerr << "Empty input\n";

        return 1;
    }
    std::cout << std::boolalpha << checkRealNumber(input_str) << "\n";
    delete[] input_str;

    return 0;
}
