#include "CountRow.h"
#include <cstddef>

bool hasSimilarElement(const int* array, size_t len, size_t idx)
{
    int currentEl = array[idx];
    for (size_t i = idx + 1; i < len; i++)
    {
        if (currentEl == array[i])
        {
            return true;
        }
    }
    return false;
}

size_t countVariousElementsInRow(const int* array, size_t len, size_t rowIdx)
{
    size_t count = 0;
    for (size_t i = rowIdx * len; i < (rowIdx + 1) * len; i++)
    {
        if (!hasSimilarElement(array, len, i))
        {
            count++;
        }
    }
    return count;
}

int countRowsWithEqualSum(const int* array, size_t rows, size_t columns)
{
    size_t count = 0;
    for (size_t i = 0; i < rows; ++i)
    {
        int row_sum = 0;

        for (size_t j = 0; j < columns; ++j)
        {
            row_sum += *(array + i * columns + j);
        }
        bool found = false;
        for (size_t k = i + 1; k < rows; ++k)
        {
            int other_sum = 0;

            for (size_t j = 0; j < columns; ++j)
            {
                other_sum += *(array + k * columns + j);
            }

            if (row_sum == other_sum)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            count++;
        }
    }
    return count;
}

size_t countVariousElements(const int* array, size_t rows, size_t columns)
{
    size_t count = 0;
    for (size_t i = 0; i < rows; i++)
    {
        count += countVariousElementsInRow(array, columns, i);
    }
    return count;
}

bool hasSuccessionEqual(const int* row, size_t len)
{
    for (size_t i = 0; i < len - 1; i++)
    {
        if (row[i] == row[i + 1])
        {
            return true;
        }
    }
    return false;
}

size_t countRowsWithEqualElements(const int* matrix, size_t matrixDim)
{
    size_t count = 0;
    for (size_t i = 0; i < matrixDim; i++)
    {
        if (hasSuccessionEqual(&matrix[i * matrixDim], matrixDim))
        {
            count++;
        }
    }
    return count;
}

size_t countEqualElementsSequences(const int* matrix, size_t matrixDim)
{
    size_t count = 0;
    for (size_t i = 0; i < matrixDim; i++)
    {
        bool foundSuccessionEqual = false;
        for (size_t j = 0; j < matrixDim - 1; j++)
        {
            if (matrix[i * matrixDim + j] == matrix[i * matrixDim + j + 1])
            {
                foundSuccessionEqual = true;
                break;
            }
            if (!foundSuccessionEqual)
            {
                count++;
            }
        }
    }
    return count;
}
