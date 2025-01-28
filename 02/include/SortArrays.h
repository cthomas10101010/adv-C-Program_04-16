#ifndef SORTARRAYS_H
#define SORTARRAYS_H

#include <array>
#include <string>

// Sorts both a built-in array and a std::array of strings.
// sizeBuiltIn is the size of the built-in array.
// sizeStdArray is the size of the std::array.
void sortArrays(std::string builtInArr[], int sizeBuiltIn, 
                std::array<std::string, 5> &stdArr);

#endif
