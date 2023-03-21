#ifndef GITLAB_LABS_MAKECSTRING_HPP
#define GITLAB_LABS_MAKECSTRING_HPP

#include <istream>
#include <cstddef>

char *makeCString(size_t &size, size_t &capacity, std::istream &input);

#endif
