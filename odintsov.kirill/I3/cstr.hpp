#ifndef CSTR_HPP
#define CSTR_HPP

#include <cstddef>

namespace odintsov {
  struct CString {
    size_t size;
    size_t cap;
    char* str;

    CString(size_t cap);
    ~CString();

    void extend(size_t newCap);
    void append(char c);
  };

  bool isVowel(char c);
  void removeLatin(const char* cstr, char* out);
  void removeVowels(const char* cstr, char* out);
}

#endif
