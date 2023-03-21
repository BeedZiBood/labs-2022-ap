#include <iostream>
#include <extendCString.h>
#include <getCString.h>
#include "charstr.h"

int main()
{
  char * c_string = nullptr;
  try
  {
    c_string = chemodurov::getCString(std::cin);
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  size_t size = 0;
  for (auto i = c_string; *i != '\0'; ++i)
  {
    size++;
  }
  size++;
  char * other_string = nullptr;
  const size_t other_size = 5;
  try
  {
    other_string = new char[other_size];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    delete [] c_string;
    return 1;
  }
  for (size_t i = 0; i < other_size - 1; ++i)
  {
    other_string[i] = '2';
  }
  other_string[other_size - 1] = '\0';

  char * another_string = nullptr;
  try
  {
    another_string = new char[size + other_size];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    delete [] c_string;
    delete [] other_string;
    return 1;
  }
  another_string = chemodurov::addNumbersToFirst(another_string, c_string, other_string);
  std::cout << another_string << "\n";
  delete [] other_string;
  delete [] another_string;

  bool is_rep_num = chemodurov::isRepeatingNumbers(c_string);
  if (is_rep_num)
  {
    std::cout << "String contains repeating numbers\n";
  }
  else
  {
    std::cout << "String does not contain repeating numbers\n";
  }

  char * yet_another_string = nullptr;
  try
  {
    yet_another_string = new char[size];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    delete [] c_string;
    return 1;
  }
  yet_another_string = chemodurov::deleteVowels(yet_another_string, c_string);
  std::cout << yet_another_string << "\n";
  delete [] c_string;
  delete [] yet_another_string;
}
