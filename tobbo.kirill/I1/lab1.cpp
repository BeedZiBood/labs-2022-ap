#include <iostream>
#include <limits>

int main()
{
  unsigned int countMax = 0;
  unsigned int countLocalMax = 0;
  int maxx = std::numeric_limits< int >::min();
  constexpr unsigned int max_uint = std::numeric_limits< unsigned int >::max();
  int third = 0;
  int first = 0;
  int second = 0;
  std::cout << "Enter numbers:\n";
  do
  {
    std::cin >> third;
    if (!std::cin)
    {
      std::cerr << "Input should be numbers";
      return 1;
    }
    try
    {
      if (third != 0)
      {
        if (third > maxx)
        {
          countMax = 0;
          maxx = third;
        }
        if (third == maxx)
        {
          if (countMax == max_uint)
          {
            throw std::overflow_error("Overflow!");
          }
          countMax++;
        }
        if (first < second && second > third)
        {
          if (countLocalMax == max_uint)
          {
            throw std::overflow_error("Overflow!");
          }
          countLocalMax++;
        }
        first = second;
        second = third;
      }
    }
    catch (const std::overflow_error& e)
    {
      std::cerr << e.what();
      return 1;
    }
  }
  while (third != 0);

  if (countMax == 0)
  {
    std::cout << "The sequence is empty.\n";
  }
  else
  {
    std::cout << "Count of maximum values: " << countMax << " Max value: " << maxx << "\n";
    std::cout << "Count of local maximums: " << countLocalMax << "\n";
  }
  return 0;
}

