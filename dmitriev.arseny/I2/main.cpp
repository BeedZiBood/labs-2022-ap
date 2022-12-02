#include <iostream>
#include <fstream>
#include "shiftArray.h"
#include "countOrderedTriples.h"


int main(int argc, char* arr[])
{
  if (argc > 2)
  {
    std::cout << "Too much parameters";
    return 1;
  }
  else if (argc == 1)
  {
    std::cout << "Filename not found";
    return 1;
  }

  const int size1 = 5;
  int arr1[5] = { 4, 5, 1, 2, 6 };
  int shift1 = 2;
  int count1 = 0;
  try
  {
    shiftArray(arr1, size1, shift1);
    int count1 = countOrderedTriples(arr1, size1);
  }
  catch (const std::invalid_argument& e)
  {
    std::cout << "Error: ";
    std::cout << e.what();
    return 1;
  }

  int* arr2 = nullptr;
  int size2 = 0;
  int shift2 = 0;
  int count2 = 0;
  std::cin >> size2 >> shift2;
  if (size2 >= 0 && shift2 >= 0)
  {
    arr2 = new int[size2];
    std::srand(time(nullptr));
    for (int i = 0; i < size2; i++)
    {
      arr2[i] = rand();
    }
    try
    {
      shiftArray(arr2, size2, shift2);
      int count2 = countOrderedTriples(arr2, size2);
    }
    catch (const std::invalid_argument& e)
    {
      std::cout << "Error: ";
      std::cout << e.what();
      delete[] arr2;
      return 1;
    }
    delete[] arr2;
  }
  else
  {
    std::cout << "No arr is possible" << "\n";
  }

  std::ifstream file;
  file.open(arr[1]);
  if (file.is_open())
  {
    int* arr3;
    int size3 = 0;
    int shift3 = 0;
    int count3 = 0;
    file >> size3;
    if (file)
    {
      file >> shift3;
      if (file)
      {
        arr3 = new int[size3];
        for (int i = 0; i < size3; i++)
        {
          file >> arr3[i];
          if (!file)
          {
            std::cout << "Error while reading file" << "\n";
            delete[] arr3;
            return 1;
          }
        }
        try
        {
          shiftArray(arr3, size3, shift3);
          int count3 = countOrderedTriples(arr3, size3);
        }
        catch (const std::invalid_argument& e)
        {
          std::cout << "Error: ";
          std::cout << e.what();
          delete[] arr3;
          return 1;
        }
        delete[] arr3;
      }
      else
      {
        std::cout << "Error while reading file" << "\n";
        return 1;
      }
    }
    else
    {
      std::cout << "Error while reading file" << "\n";
      return 1;
    }
  }
  else
  {
    std::cout << "Error while opening file";
    return 1;
  }

  return 0;
}
