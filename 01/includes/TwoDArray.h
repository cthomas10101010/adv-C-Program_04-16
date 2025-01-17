#ifndef TWODARRAY_H
#define TWODARRAY_H

#include <iostream>
#include <stdexcept>  // For exception handling

/**
 * @brief A generic 2D array template class that can store items of type T.
 */
template <typename T>
class TwoDArray
{
private:
    T** arrayData;         // Pointer to a pointer – 2D dynamic array
    int maxRows;           // Maximum number of rows allocated
    int* maxColsPerRow;    // Tracks the number of columns allocated for each row

public:
    /**
     * @brief Constructor: allocates memory for a 2D array with a given maximum number of rows.
     * @param rows The maximum number of rows (e.g., characters) you plan to store.
     */
    TwoDArray(int rows)
    {
        maxRows = rows;
        arrayData = new T*[maxRows];
        maxColsPerRow = new int[maxRows];

        // Initialize each row pointer to nullptr and column count to 0.
        for (int i = 0; i < maxRows; ++i)
        {
            arrayData[i] = nullptr;
            maxColsPerRow[i] = 0;
        }
    }

    /**
     * @brief Destructor: releases allocated memory.
     */
    ~TwoDArray()
    {
        // Deallocate memory for each row.
        for (int i = 0; i < maxRows; ++i)
        {
            delete[] arrayData[i];
        }
        // Deallocate the array of pointers and the column count array.
        delete[] arrayData;
        delete[] maxColsPerRow;
    }

    /**
     * @brief Allocates the columns for a specific row.
     * @param row The row index to allocate.
     * @param cols The number of columns to allocate for that row.
     */
    void allocateRow(int row, int cols)
    {
        if (row < 0 || row >= maxRows)
            throw std::out_of_range("Row index out of range.");

        // If the row already has allocated memory, delete it before re-allocating.
        delete[] arrayData[row];

        arrayData[row] = new T[cols];

        // Initialize each element to the default value.
        for (int i = 0; i < cols; ++i)
        {
            arrayData[row][i] = T();  
        }

        maxColsPerRow[row] = cols;
    }

    /**
     * @brief Stores an element in the 2D array.
     * @param row The row index.
     * @param col The column index.
     * @param value The value to store.
     */
    void setElement(int row, int col, const T& value)
    {
        if (row < 0 || row >= maxRows)
            throw std::out_of_range("Row index out of range.");
        if (col < 0 || col >= maxColsPerRow[row])
            throw std::out_of_range("Column index out of range.");

        arrayData[row][col] = value;
    }

    /**
     * @brief Retrieves an element from the 2D array.
     * @param row The row index.
     * @param col The column index.
     * @return The requested element.
     */
    T getElement(int row, int col) const
    {
        if (row < 0 || row >= maxRows)
            throw std::out_of_range("Row index out of range.");
        if (col < 0 || col >= maxColsPerRow[row])
            throw std::out_of_range("Column index out of range.");

        return arrayData[row][col];
    }
    
    /**
     * @brief Gets the maximum number of rows allocated.
     * @return The maximum number of rows.
     */
    int getMaxRows() const
    {
        return maxRows;
    }
    
    /**
     * @brief Gets the number of columns allocated for a specific row.
     * @param row The row index.
     * @return The number of columns allocated for that row.
     */
    int getColsForRow(int row) const
    {
        if (row < 0 || row >= maxRows)
            throw std::out_of_range("Row index out of range.");
        return maxColsPerRow[row];
    }
};

#endif // TWODARRAY_H
