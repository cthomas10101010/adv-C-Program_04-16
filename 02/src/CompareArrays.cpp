#include "compareArrays.h"

// compareArrays
// Parameters:
//   arr1, arr2 - built-in string arrays
//   size       - number of elements in each array
// Returns: bool (true if identical; false otherwise).
bool compareArrays(const std::string arr1[], const std::string arr2[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}
