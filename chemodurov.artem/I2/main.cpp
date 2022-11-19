#include "numbers.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

namespace client
{
  const int divider = 7;
}

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    std::cerr << "Not correct amolunt of CML args\n";
    return 2;
  }

  std::ifstream input(argv[1]);
  if (!input)
  {
    std::cerr << argv[1] << " Error while reading\n";
    return 2;
  }
  size_t arr_size = 0;
  input >> arr_size;
  if (!input)
  {
    std::cerr << argv[1] << " Error while reading\n";
    return 2;
  }
  if (!arr_size)
  {
    std::cout << "0 0\n";
  }
  else
  {
    int * arr = new int[arr_size];
    while (!input.eof())
    {
      for (size_t i = 0; i < arr_size; ++i)
      {
        int x = 0;
        input >> x;
        if (!input)
        {
          std::cerr << argv[1] << " Error while reading\n";
          delete [] arr;
          return 2;
        }
        arr[i] = x;
      }
      input >> std::ws;
    }
    delete [] arr;
    unsigned int arr_cnt_dec = chemodurov::countMaxDecreasing(arr, arr_size);
    unsigned int arr_cnt_div = chemodurov::countDivisible(arr, arr_size, client::divider);
    std::cout << arr_cnt_dec << " " << arr_cnt_div << "\n";
  }
  size_t n = 0;
  std::cin >> n;
  if (!std::cin)
  {
    std::cerr << "Error...\n";
    return 1;
  }
  if (n > 0)
  {
    int * dyn_arr = new int[n];
    for (size_t i = 0; i < n; ++i)
    {
      std::srand(std::time(0));
      dyn_arr[i] = std::rand();
    }
    unsigned int dyn_a_cnt_dec = chemodurov::countMaxDecreasing(dyn_arr, n);
    unsigned int dyn_a_cnt_div = chemodurov::countDivisible(dyn_arr, n, client::divider);
    delete [] dyn_arr;
    std::cout << dyn_a_cnt_dec << " " << dyn_a_cnt_div << "\n";
  }
  else
  {
    std::cout << "0 0\n";
  }

  int a[10] = {3, 2, 1, 7, 5, 4, 2, 9, 8, 4};
  size_t a_size = 10;
  unsigned int a_cnt_dec = chemodurov::countMaxDecreasing(a, a_size);
  unsigned int a_cnt_div = chemodurov::countDivisible(a, a_size, client::divider);
  std::cout << a_cnt_dec << " " << a_cnt_div << "\n";
  return 0;
}
