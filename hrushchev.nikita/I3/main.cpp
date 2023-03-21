#include <iostream>
#include <inputcstring.hpp>
#include "unitestring.hpp"
#include "existconsecutiveequalelement.hpp"
#include "generatealphabeticchar.hpp"

int main()
{
  char* c_string = nullptr;
  try
  {
    c_string = inputCString(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  size_t size = 0;
  while (c_string[size] != '\0')
  {
    size++;
  }
  std::cout << c_string << "\n";

  std::srand(time(0));
  const size_t rand_size = 10 + std::rand() % 30;
  char* rand_string = nullptr;

  try
  {
    rand_string = new char[rand_size];
    for (size_t i = 0; i < rand_size; i++)
    {
      rand_string[i] = generateAlphabeticChar();
    }
    rand_string[rand_size - 1] = '\0';
    std::cout << rand_string << "\n";
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << "\n";\
    delete[] c_string;
    delete[] rand_string;
    return 1;
  }

  char* united_string = nullptr;
  try
  {
    united_string = new char[size + rand_size];
    united_string = uniteString(united_string, c_string, rand_string);
    std::cout << united_string << '\n';
    std::cout << existConsecutiveEqualElement(united_string) << "\n";
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << "\n";
    delete[] c_string;
    delete[] rand_string;
    delete[] united_string;
  }

  delete[] c_string;
  delete[] rand_string;
  delete[] united_string;
}

