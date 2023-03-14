#include <iostream>
#include <CreateCString.h>
#include "isExpression.h"
int main()
{
 char* cstring = nullptr;
 try
 {
   cstring = createCString(std::cin);
   if (cstring [0] == '\0')
   {
     throw std::logic_error("Empty string");
   }
 }
 catch(const std::exception &e)
 {
   std::cerr << e.what() << "\n";
   delete[] cstring;
   return 1;
 }
 std::cout << std::boolalpha << isExpression(cstring) << '\n';
 delete[] cstring;
 return 0;
}

