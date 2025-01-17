#include <iostream>
#include <string>
#include <array>

// Our headers
#include "CalculateDiscount.h"
#include "DetermineLarger.h"
#include "CompareArrays.h"
#include "SortArrays.h"
#include "DemoPtrTechniques.h"

int main()
{
    //------------------------------------------------
    // #01 & #02: Function One - calculateDiscount
    //------------------------------------------------
    double listPrice, discountPercent;
    std::cout << "Enter the list price: ";
    std::cin >> listPrice;
    std::cout << "Enter the discount percentage (e.g. 10 for 10%): ";
    std::cin >> discountPercent;

    double discountedPrice = 0.0; 
    calculateDiscount(listPrice, discountPercent, discountedPrice);

    std::cout << "\nThe discounted price is: " << discountedPrice << "\n\n";

    //------------------------------------------------
    // #03: Function Two - determineLarger
    //------------------------------------------------
    int intOne, intTwo;
    std::cout << "Enter first integer: ";
    std::cin >> intOne;
    std::cout << "Enter second integer: ";
    std::cin >> intTwo;

    int largerValue = 0;
    determineLarger(intOne, intTwo, &largerValue);
    std::cout << "\nThe larger of " << intOne << " and " << intTwo
              << " is: " << largerValue << "\n\n";

    //------------------------------------------------
    // #04: Function Three - compareArrays
    //------------------------------------------------
    const int SIZE = 3;
    std::string arr1[SIZE];
    std::string arr2[SIZE];

    std::cout << "Populate built-in array1 of size " << SIZE << ":\n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "arr1[" << i << "]: ";
        std::cin >> arr1[i];
    }
    std::cout << "\nPopulate built-in array2 of size " << SIZE << ":\n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "arr2[" << i << "]: ";
        std::cin >> arr2[i];
    }

    bool sameArrays = compareArrays(arr1, arr2, SIZE);
    if(sameArrays)
        std::cout << "\nBoth arrays contain the same elements.\n\n";
    else
        std::cout << "\nThe arrays are different.\n\n";

    //------------------------------------------------
    // #05: Function Four - sortArrays
    //------------------------------------------------
    // Built-in array of strings to sort
    std::string builtInArr[5] = {"pear", "apple", "orange", "banana", "grape"};

    // std::array of strings to sort
    std::array<std::string, 5> stdArrayObj = {"delta", "alpha", "charlie", "bravo", "echo"};

    std::cout << "Before sorting builtInArr: ";
    for(const auto& str : builtInArr) 
        std::cout << str << " ";
    std::cout << "\n";

    std::cout << "Before sorting stdArrayObj: ";
    for(const auto& str : stdArrayObj)
        std::cout << str << " ";
    std::cout << "\n\n";

    sortArrays(builtInArr, 5, stdArrayObj);

    std::cout << "After sorting builtInArr: ";
    for(const auto& str : builtInArr) 
        std::cout << str << " ";
    std::cout << "\n";

    std::cout << "After sorting stdArrayObj: ";
    for(const auto& str : stdArrayObj)
        std::cout << str << " ";
    std::cout << "\n\n";

    //------------------------------------------------
    // #06: Function Five - demoPtrTechniques
    //------------------------------------------------
    demoPtrTechniques();

    // Program completed
    std::cout << "\n=== End of Program ===\n";
    return 0;
}
