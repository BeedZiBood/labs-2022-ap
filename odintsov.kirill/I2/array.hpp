#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

namespace odintsov {
  struct Array {
    int* data;
    size_t size;
    size_t cap;

    Array(size_t cap);

    ~Array();

    void append(int val);
  };

  const int* findMax(const int* arr, size_t size, int lowBound, int highBound);
  float getAvgEvenIndices(const int* arr, size_t size);
}

#endif
