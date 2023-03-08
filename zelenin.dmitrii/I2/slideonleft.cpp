#include "slideonleft.h"

int* slideOnLeft(int* array, size_t count_elements, int count_elements_for_slide_array)
{
  int changer = 0;
  while (count_elements_for_slide_array > 0)
  {
    changer = array[0];
    for (int i = 0; i < count_elements - 1; i++)
    {
      array[i] = array[i + 1];
    }
    array[count_elements - 1] = changer;
    count_elements_for_slide_array--;
  }
  return array;
}
