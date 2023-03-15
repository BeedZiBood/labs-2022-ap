#include "createLatinLetteredStringFromStrings.h"
#include "tolower.h"
#include <cstdlib>

char* createLatinLetteredStringFromStrings(const char* c_string_1, const char* c_string_2)
{
  const size_t letters_in_alphabet = 32;
  bool unique_letters[letters_in_alphabet] = {false};
  
  while (*c_string_1)
  {
    char c = to_lower(*c_string_1);
    if (c >= 'a' && c <= 'z')
    {
      size_t idx = c - 'a';             // convert a letter to an index
      if (!unique_letters[idx])
      {
        const char* str = c_string_2; // every time from beggining of the string
        bool found = false;
        while (*str)
        {
          if (c == to_lower(*str))
          {
            found = true;
            break;
          }
          ++str;
        }
        if (found)
        {
          unique_letters[idx] = true;
        }
      }
    }
    ++c_string_1;
  }
  
  // count found letters
  size_t destination_string_length = 0;
  for (size_t i = 0; i < letters_in_alphabet; ++i)
  {
    if (unique_letters[i]) 
    {
      ++destination_string_length;
    }
  }
  
  // allocate enough memory for the result string
  char* destination = new char[destination_string_length + 1]; // +1 for '\0'
  
  char* p = destination;
  for (size_t i = 0; i < letters_in_alphabet; ++i)
  {
    if (unique_letters[i])
    {
      *p++ = i + 'a'; // convert an index to a letter
    }
  }
  *p = '\0';
  
  return destination;
}
