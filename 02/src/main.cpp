#include <iostream>
#include <string>
#include <array>
#include "calculateDiscount.h"
#include "determineLarger.h"
#include "compareArrays.h"
#include "sortArrays.h"
#include "demoPtrTechniques.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::array;

int main()
{
    // 1) Function One - calculateDiscount
    double listPrice = 0.0;
    double discountPercent = 0.0;
    double discountedPrice = 0.0;

    cout << "Enter the list price: ";
    cin >> listPrice;
    cout << "Enter the discount percentage: ";
    cin >> discountPercent;

    // call calculateDiscount
    calculateDiscount(listPrice, discountPercent, discountedPrice);

    cout << "Discounted price is: " << discountedPrice << endl << endl;

    // 2) Function Two - determineLarger
    int intOne = 0;
    int intTwo = 0;
    int largerValue = 0; // will receive result via pointer

    cout << "Enter integer one: ";
    cin >> intOne;
    cout << "Enter integer two: ";
    cin >> intTwo;

    determineLarger(intOne, intTwo, &largerValue);
    cout << "The larger of the two is: " << largerValue << endl << endl;

    // 3) Function Three - compareArrays
    // We'll create two built-in arrays of the same size, and ask user for data.
    const int SIZE = 3;
    std::string arr1[SIZE];
    std::string arr2[SIZE];

    cout << "Enter 3 strings for arr1:\n";
    for (int i = 0; i < SIZE; ++i)
    {
        cin >> arr1[i];
    }

    cout << "Enter 3 strings for arr2:\n";
    for (int i = 0; i < SIZE; ++i)
    {
        cin >> arr2[i];
    }

    bool arraysMatch = compareArrays(arr1, arr2, SIZE);
    if (arraysMatch)
    {
        cout << "The two arrays have identical data.\n";
    }
    else
    {
        cout << "The two arrays do NOT match.\n";
    }
    cout << endl;

    // 4) Function Four - sortArrays
    // Example built-in array (size 5) and std::array (size 5).
    std::string builtInArr[5];
    array<string, 5> stdArr;

    cout << "Enter 5 strings for builtInArr:\n";
    for (int i = 0; i < 5; ++i)
    {
        cin >> builtInArr[i];
    }

    cout << "Enter 5 strings for stdArr:\n";
    for (int i = 0; i < 5; ++i)
    {
        cin >> stdArr[i];
    }

    sortArrays(builtInArr, 5, stdArr);

    cout << "builtInArr after sort:\n";
    for (int i = 0; i < 5; ++i)
    {
        cout << builtInArr[i] << " ";
    }
    cout << endl;

    cout << "stdArr after sort:\n";
    for (const auto &s : stdArr)
    {
        cout << s << " ";
    }
    cout << endl << endl;

    // 5) Function Five - demoPtrTechniques
    demoPtrTechniques();

    cout << "Program finished.\n";
    return 0;
}
