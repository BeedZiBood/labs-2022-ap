#include <iostream>
#include <cstddef>
#include <makecstring.hpp>
#include "RepeatSymbols.hpp"
#include "Vowel.hpp"
int main()
{
  size_t size = 0;
  size_t capacity = 10;
  char *c_string = makeCString(size, capacity, std::cin);

  if (c_string[0] == '\n')
  {
    delete[] c_string;
    std::cerr << "Error: empty string \n";
    return 2;
  }

  // task 6

  char *repeat_symbols = nullptr;

  try
  {
    repeat_symbols = new char[capacity];
  }
  catch (const std::bad_alloc &e)
  {
    delete[] c_string;
    delete[] repeat_symbols;
    std::cout << "Error:\n";
    std::cout << e.what();
    return 1;
  }
  repeatSymbols(repeat_symbols, c_string);

  std::cout << "Repeat symbols string: " << repeat_symbols << '\n';

  // task 18

  char *vowel_symbols = nullptr;

  try
  {
    vowel_symbols = new char[12];
  }
  catch (const std::bad_alloc &e)
  {
    delete[] c_string;
    delete[] repeat_symbols;
    delete[] vowel_symbols;
    std::cerr << "Error: \n" << e.what();
    return 1;
  }
  findVowel(vowel_symbols, c_string);

  std::cout << "Latin vowel symbols string: " << vowel_symbols << '\n';

  delete[] c_string;
  delete[] repeat_symbols;
  delete[] vowel_symbols;
}
