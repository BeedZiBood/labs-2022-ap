#ifndef CSTR_HPP
#define CSTR_HPP

#include <cstddef>

namespace odintsov {
  struct CStringWrapper {
    size_t arrSize;
    size_t arrCap;
    char* str;

    explicit CStringWrapper(size_t arrCap);
    ~CStringWrapper();

    void extend(size_t newCap);
    void append(char c);
  };

  bool isLowerVowel(char c);
  bool isUpperVowel(char c);
  bool isVowel(char c);
  char* removeLatin(char* dest, const char* src);
  char* removeVowels(char* dest, const char* src);
}

#endif
