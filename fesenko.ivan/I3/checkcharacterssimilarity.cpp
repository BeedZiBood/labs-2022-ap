#include "checkcharacterssimilarity.h"

bool checkCharactersSimilarity(const char *source)
{
  if (*source != '\0') {
    for (auto i = source + 1; *i != '\0'; i++) {
      if (*i == *(i - 1)) {
        return true;
      }
    }
  }
  return false;
}
