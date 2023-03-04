#include "workWithStrs.h"
#include "checkRealNumber.h"
#include "workWithIO.h"

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
  std::cout << std::boolalpha << checkRealNumber(input_str) << "\n";
  delete[] input_str;
  return 0;
}
