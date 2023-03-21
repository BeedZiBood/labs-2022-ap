#include "removeExtraSpaces.h"

char* removeExtraSpaces(char* destination, const char* cstring)
{
  size_t numberOfSymbols1 = 0;
  size_t numberOfSymbols2 = 0;
  size_t numberOfSpaces = 0;
  size_t numberOfDeletedSpaces = 0;
  size_t numberOfOccurrencesInCstring = 0;
  size_t numberOfOccurrencesInDestination = 0;

  while (*cstring != '\0')
  {
    if (*cstring != ' ')
    {
      numberOfSymbols1++;
    }
    numberOfOccurrencesInCstring++;
    cstring++;
  }

  size_t numberOfOccurrencesInCstring1 = numberOfOccurrencesInCstring;
  while (numberOfOccurrencesInCstring1 != 0)
  {
    numberOfOccurrencesInCstring1--;
    cstring--;
  }
  numberOfOccurrencesInCstring = 0;
  while (*cstring != '\0')
  {
    numberOfOccurrencesInCstring++;
    if (*cstring != ' ')
    {
      numberOfSymbols2++;
    }
    if (numberOfSymbols2 == 0)
    {
      numberOfDeletedSpaces++;
      cstring++;
      continue;
    }

    if (numberOfSymbols2 == numberOfSymbols1 && *cstring == ' ')
    {
      numberOfSpaces++;
    }

    if (numberOfOccurrencesInCstring != 1 && *cstring == *(cstring - 1) && *cstring == ' ' && numberOfSymbols2 != numberOfSymbols1)
    {
      numberOfDeletedSpaces++;
      cstring++;
      continue;
    }

    if (numberOfSymbols2 == numberOfSymbols1 && numberOfSpaces != 0)
    {
      numberOfDeletedSpaces++;
      cstring++;
      continue;
    }
    *destination = *cstring;
    destination++;
    cstring++;
    numberOfOccurrencesInDestination++;
  }
  *destination = '\0';

  while (numberOfOccurrencesInDestination != 0)
  {
    numberOfOccurrencesInDestination--;
    destination--;
  }
  return destination;
}
