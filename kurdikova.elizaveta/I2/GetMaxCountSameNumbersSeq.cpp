#include "GetMaxCountSameNumbersSeq.h"

size_t getMaxCountSameNumbersSeq(const int* arr, size_t size)
{
  size_t maxCount = 1;
  size_t currentCount = 1;
  for (size_t i = 0; i < size - 1; ++i) {
    if (arr[i] == arr[i + 1]) {
      currentCount++;
    } else {
      currentCount = 1;
    }
    if (currentCount > maxCount) {
      maxCount = currentCount;
    }
  }
  return maxCount;
}
