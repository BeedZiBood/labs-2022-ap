#include <iostream>
#include "PifTrio.hpp"
#include "ChangeSignCounter.hpp"

int main()
{
  FindPifTrio pif_trio{0, 0, 0};
  CountSignChanges sign_changes{0, 0};
  int x = 0;
  do
  {
    std::cin >> x;
    if (std::cin.fail())
    {
      std::cout << "Illegal character";
      break;
    }
    try
    {
      pif_trio(x);
      sign_changes(x);
    }
    catch (const std::overflow_error& error)
    {
      std::cout << "Error: " << error.what() << "\n";
      return 1;
    }
  }
  while (x != 0);
  if (!std::cin.fail())
  {
    std::cout << "Count of Pythogorean triplets " << pif_trio.PifCounter << "\n";
    std::cout << "Count of number sign changes " << sign_changes.ChangeSignCounter << "\n";
  }
}
