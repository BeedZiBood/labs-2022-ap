#ifndef MATRIXWRAPPER_HPP
#define MATRIXWRAPPER_HPP

#include <cstddef>

namespace zasulsky {
  struct MatrixWrapper {
    size_t rows, cols;
    int* matrix;

    MatrixWrapper(size_t rows, size_t cols);
    ~MatrixWrapper();
  };
}

#endif
