#include "check-command-in-string.hpp"
#include <cstring>

bool chemodurov::checkCommand(const std::string & line, const char * command)
{
  return (!line.compare(0, std::strlen(command), command));
}
