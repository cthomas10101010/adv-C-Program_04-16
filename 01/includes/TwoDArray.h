#ifndef TWODARRAY_H
#define TWODARRAY_H

#include <stdexcept> // Allowed in Chapter 7 (exceptions)
#include <iostream>

template <typename T>
class TwoDArray
{
private:
    T** dataPtr;
    int maxRows;
    int* maxCols;

public:
    // Constructor
    TwoDArray(int rows)
    {
        maxRows = rows;
        dataPtr = new T*[maxRows];
        maxCols = new int[maxRows];
        // Initialize each row to nullptr, col count to 0
        for (int i = 0; i < maxRows; ++i)
        {
            dataPtr[i] = nullptr;
            maxCols[i] = 0;
        }
    }

    // Destructor
    ~TwoDArray()
    {
        for (int i = 0; i < maxRows; ++i)
        {
            delete[] dataPtr[i];
        }
        delete[] dataPtr;
        delete[] maxCols;
    }

    // Allocate a row's columns
    void allocateRow(int rowIndex, int cols)
    {
        if (rowIndex < 0 || rowIndex >= maxRows)
            throw std::out_of_range("Row index out of range.");

        // Deallocate if already allocated
        delete[] dataPtr[rowIndex];

        dataPtr[rowIndex] = new T[cols];
        maxCols[rowIndex] = cols;

        // Initialize each entry
        for (int i = 0; i < cols; ++i)
        {
            dataPtr[rowIndex][i] = T();
        }
    }

    // Store an element
    void setElement(int row, int col, const T& value)
    {
        if (row < 0 || row >= maxRows)
            throw std::out_of_range("Row index out of range.");
        if (col < 0 || col >= maxCols[row])
            throw std::out_of_range("Column index out of range.");

        dataPtr[row][col] = value;
    }

    // Retrieve an element
    T getElement(int row, int col) const
    {
        if (row < 0 || row >= maxRows)
            throw std::out_of_range("Row index out of range.");
        if (col < 0 || col >= maxCols[row])
            throw std::out_of_range("Column index out of range.");

        return dataPtr[row][col];
    }

    // Return number of rows
    int getMaxRows() const
    {
        return maxRows;
    }

    // Return number of columns for a given row
    int getColsForRow(int row) const
    {
        if (row < 0 || row >= maxRows)
            throw std::out_of_range("Row index out of range.");
        return maxCols[row];
    }
};

#endif // TWODARRAY_H