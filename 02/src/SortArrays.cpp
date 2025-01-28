#include "sortArrays.h"
#include <algorithm>  // for std::sort

void sortArrays(std::string builtInArr[], int sizeBuiltIn, 
                std::array<std::string, 5> &stdArr)
{
    // 1) Sort the built-in array using std::sort and pointer arithmetic
    //    Since it's a built-in array, we pass begin and end as pointers.
    std::sort(builtInArr, builtInArr + sizeBuiltIn);

    // 2) Sort the std::array using its begin/end iterators
    std::sort(stdArr.begin(), stdArr.end());
}
