#include <iostream>
#include <MakeCString.hpp>
#include "SumStrings.hpp"
#include "GetUniqueSymbols.hpp"

int main()
{
  size_t size_one = 0;
  size_t size_two = 0;
  size_t capacity_one = 10;
  size_t capacity_two = 10;


  char *cstring_one = new char[capacity_one];
  char *cstring_two = nullptr;

  try
  {
    cstring_two = new char[capacity_two];
  }
  catch (const std::bad_alloc &e)
  {
    delete[] cstring_one;
    std::cout << "Error:\n";
    std::cout << e.what();
    return 3;
  }

  cstring_one[0] = '\n';

  cstring_two[size_one] = '\0';

  try
  {
    cstring_one = makeCString(cstring_one, size_one, capacity_one, std::cin);
    if (cstring_one[0] == '\n')
    {
      std::cout << "Error, empty string";
      delete[] cstring_one;
      delete[] cstring_two;
      return 4;
    }
    cstring_one[size_one - 1] = '\0';
  }
  catch (const std::bad_alloc &e)
  {
    delete[] cstring_one;
    delete[] cstring_two;
    std::cout << "Error:\n";
    std::cout << e.what();
    return 3;
  }

  //12

  size_t capacity_sum = size_one + size_two + 100;

  char *arr_sum = nullptr;

  try
  {
    arr_sum = new char[capacity_sum];
  }
  catch (const std::bad_alloc &e)
  {
    delete[] cstring_one;
    delete[] cstring_two;
    std::cout << "Error:\n";
    std::cout << e.what();
    return 3;
  }

  try
  {
    arr_sum = sum_strings(arr_sum, cstring_one, cstring_two);

  }
  catch (const std::overflow_error &e)
  {
    delete[] cstring_one;
    delete[] cstring_two;
    delete[] arr_sum;
    std::cout << "Error:\n";
    std::cout << e.what();
    return 1;
  }
  catch (const std::bad_alloc &e)
  {
    delete[] cstring_one;
    delete[] cstring_two;
    delete[] arr_sum;
    std::cout << "Error:\n";
    std::cout << e.what();
    return 3;
  }

  std::cout << "Chess sum string: " << arr_sum << "\n";

  //5

  size_t capacity_unique = size_one + size_two + 100;
  char *arr_unique = nullptr;

  try
  {
    arr_unique = new char[capacity_unique];
  }
  catch (const std::bad_alloc &e)
  {
    delete[] cstring_one;
    delete[] cstring_two;
    delete[] arr_sum;
    delete[] arr_unique;
    std::cout << "Error:\n";
    std::cout << e.what();
    return 3;
  }

  try
  {
    arr_unique = get_unique_symbols(arr_unique, cstring_one, cstring_two);
  }
  catch (const std::overflow_error &e)
  {
    delete[] cstring_one;
    delete[] cstring_two;
    delete[] arr_sum;
    delete[] arr_unique;
    std::cout << "Error:\n";
    std::cout << e.what();
    return 1;
  }
  catch (const std::bad_alloc &e)
  {
    delete[] cstring_one;
    delete[] cstring_two;
    delete[] arr_sum;
    delete[] arr_unique;
    std::cout << "Error:\n";
    std::cout << e.what();
    return 3;
  }

  std::cout << "Unique symbols sum string: " << arr_unique << "\n";

  delete[] cstring_one;
  delete[] cstring_two;
  delete[] arr_sum;
  delete[] arr_unique;
}
