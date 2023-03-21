#include "TakeSimilarLettersInOrder.h"
#include <algorithm>
#include <cctype>

bool isExistsInBoth(char letter1, char letter2)
{
  if (std::isalpha(letter1) && std::isalpha(letter2)) {
    if (std::tolower(letter1) == std::tolower(letter2)) {
      return true;
    }
  }
  return false;
}

char *lettersInOrder(char *result2, const char *source1, const char *source2)
{
  std::size_t num = 0;
  for (std::size_t i = 0; source1[i] != '\0'; i++) {
    bool existsInBothStr = false;
    for (std::size_t j = 0; source2[j] != '\0'; j++) {
      if (isExistsInBoth(source1[i], source2[j])) {
        existsInBothStr = true;
      }
    }
    if (existsInBothStr) {
      bool alreadyExists = false;
      for (std::size_t k = 0; result2[k] != '\0'; k++) {
        if (result2[k] == source1[i]) {
          alreadyExists = true;
          break;
        }
      }
      if (!alreadyExists) {
        result2[num++] = source1[i];
      }
    }
  }

  for (std::size_t i = 0; i < num - 1; i++) {
    for (std::size_t j = 0; j < num - i - 1; j++) {
      if (result2[j] > result2[j + 1]) {
        std::swap(result2[j], result2[j + 1]);
      }
    }
  }
  return result2;
}
