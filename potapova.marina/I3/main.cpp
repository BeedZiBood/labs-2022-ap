#include "workWithIOAnother.h"
#include "getMostCommonSyms.h"
#include "addAllLatinLetters.h"

int main()
{
  const char* input_str;
  size_t str1_size;
  try
  {
    input_str = getLineFromFile(&str1_size);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    return 1;
  }
  if (input_str == nullptr)
  {
    std::cerr << "Empty input\n";
    return 1;
  }
  char most_common_syms[4];
  std::cout << getMostCommonSyms(most_common_syms, input_str) << '\n';
  const char str2[] = "all";
  char* all_latin_lets;
  try
  {
    all_latin_lets = new char[str1_size + sizeof(str2)];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    delete[] input_str;
    return 1;
  }
  std::cout << addAllLatinLets(all_latin_lets, input_str, str2) << '\n';
  delete[] input_str;
  delete[] all_latin_lets;
  return 0;
}
