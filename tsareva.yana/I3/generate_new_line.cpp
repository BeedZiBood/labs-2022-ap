#include "generate_new_line.h"
#include "check_similarity_letters.h"

void generateNewLine(char * res, const char * str1, const char  * str2)
{
  char * res2 = checkSmilarityLetters(res, str1, str2);
  checkSmilarityLetters(res2, str2, str1);
  *res = '\0';
}
