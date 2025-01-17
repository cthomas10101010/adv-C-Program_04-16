#include "SortArrays.h"

// Simple helper function to swap two strings
static void swapStrings(std::string& a, std::string& b)
{
    std::string temp = a;
    a = b;
    b = temp;
}

//-----------------------------------------------------------
// Bubble sort for built-in array
//-----------------------------------------------------------
static void bubbleSortBuiltIn(std::string arr[], int size)
{
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapStrings(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no elements were swapped, array is sorted
        if (!swapped) break;
    }
}

//-----------------------------------------------------------
// Bubble sort for std::array
//-----------------------------------------------------------
static void bubbleSortStdArray(std::array<std::string, 5>& arr)
{
    bool swapped;
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapStrings(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

//-----------------------------------------------------------
// Function Name: sortArrays
// Purpose      : Sort built-in array and std::array 
//-----------------------------------------------------------
void sortArrays(std::string builtInArr[], int builtInSize,
                std::array<std::string, 5>& stdArrayObj)
{
    // Sort the built-in array
    bubbleSortBuiltIn(builtInArr, builtInSize);

    // Sort the std::array
    bubbleSortStdArray(stdArrayObj);
}
