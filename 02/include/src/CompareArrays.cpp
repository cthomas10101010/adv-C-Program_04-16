#include "CompareArrays.h"

//-----------------------------------------------------
// Function Name: compareArrays
// Purpose      : Compare two built-in arrays of strings 
//-----------------------------------------------------
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
