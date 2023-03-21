#ifndef MATRIXWRAPPER_HPP
#define MATRIXWRAPPER_HPP

#include <cstddef>
#include <iosfwd>

namespace odintsov {
  struct MatrixWrapper {
    size_t rows;
    size_t cols;
    int** arr;

    MatrixWrapper(size_t rows, size_t cols);
    ~MatrixWrapper();

    std::istream& readRow(std::istream& in, size_t row);
    std::istream& readMatrix(std::istream& in);
    std::ostream& outputRow(std::ostream& in, size_t row);
    std::ostream& outputMatrix(std::ostream& in);
  };
}

#endif
