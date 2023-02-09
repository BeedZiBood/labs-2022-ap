#ifndef WORK_WITH_IO_H
#define WORK_WITH_IO_H

#include <iostream>
#include <fstream>

void inputMatrix(size_t& count_rows,
                 size_t& count_cols,
                 std::int64_t*& matrix,
                 const char* file_name);

void printCountOfSaddlePoints(size_t сount_of_saddle_points,
                              const char* file_name);

#endif
