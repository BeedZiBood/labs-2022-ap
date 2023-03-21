#include <iostream>
int main()
{
  int n = 0;
  int after = 0;
  int actual = 0;
  int before = 0;
  int first = 1;
  bool sign = 0;
  int counter =0;
  int sum = 0;
  std::cout << "Enter the numbers you want, and to finish enter the sequence, enter a 0. \n"
            << "The program will count the sign changes and find sets of Pythagorean numbers in the sequence (z^2=x^2+y^2) \n";
  do
  {
    std::cin >> n;
    after = n;
    actual = after;
    before = actual;
    if (first == 1)
    {
      if (n > 0)
      {
        sign = true;
      }
      else
      {
        sign = false;
      }
      first = 0;
    }
    else
    {
      if ((n >= 0) != sign)
      {
        sign = !sign;
        counter++;
      }
    }
    if (before == 0 && actual == 0)
    {
      continue;
    }
    else
    {
      if (before * before == actual * actual + after * after)
      {
        sum++;
      }
    }
  }
  while (std::cin  && n);
  std::cout << "Pythagorean numbers found: " << sum;
  std::cout << "\nChange of signs: " << counter << "\n";
  return 0;
}

