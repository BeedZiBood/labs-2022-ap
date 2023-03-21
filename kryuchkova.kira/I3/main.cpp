#include <iostream>
#include <exception>
#include <input_string.h>
#include "remove_extra_spaces.h"
#include "delete_identical_chars.h"

int main()
{
  try
  {
    std::pair< size_t, char * > cstring_pair = inputString(std::cin);
    char *cstring_1 = cstring_pair.second;
    size_t capacity = cstring_pair.first;
    if (cstring_1[0] == '\0')
    {
      std::cout << "empty string";
      delete[] cstring_1;
      return 1;
    }
    cstring_1[capacity - 1] = '\0';
    char *destination = new char[capacity];
    destination[0] = '\0';
    destination = removeExtraSpaces(destination, cstring_1);
    std::cout << destination << "\n";
    delete[] destination;

    std::pair< size_t, char * > cstring_pair2 = inputString(std::cin);
    char *cstring_2 = cstring_pair2.second;
    size_t capacity_2 = cstring_pair2.first;
    if (capacity_2 == 0)
    {
      cstring_2[capacity_2] = '\0';
    }
    else
    {
      cstring_2[capacity_2 - 1] = '\0';
    }
    char *destination_2 = new char[capacity];
    destination_2[0] = '\0';
    destination_2 = deleteIdenticalChars(destination_2, cstring_1, cstring_2);
    std::cout << destination_2 << "\n";
    delete[] destination_2;
    delete[] cstring_1;
    delete[] cstring_2;
  }
  catch (const std::exception &e)
  {
    std::cout << e.what();
    return 1;
  }

  return 0;
}
