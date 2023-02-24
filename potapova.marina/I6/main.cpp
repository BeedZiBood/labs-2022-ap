#include "calculateAtanSum.h"
#include "printTable.h"

int main(int argc, const char* argv[])
{
    double start, end;
    double abs_error;
    size_t num_max;
    double step;
    std::cout << "Input interval: ";
    std::cin >> start >> end;
    std::cout << "Input step: ";
    std::cin >> step;
    std::cout << "Input abs error: ";
    std::cin >> abs_error;
    std::cout << "Input maximum terms number: ";
    std::cin >> num_max;

    return 0;
}
