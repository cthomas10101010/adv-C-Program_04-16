#include <iostream>
#include <string>
#include <array>
#include "CalculateDiscount.h"
#include "DetermineLarger.h"
#include "CompareArrays.h"
#include "SortArrays.h"
#include "DemoPtrTechniques.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;

int main() {
    // 1) Function One - calculateDiscount
    double listPrice = 0.0;
    double discountPercent = 0.0;
    double discountedPrice = 0.0;

    cout << "\n=== Discount Calculator ===\n";
    cout << "Please enter the list price ($): ";
    cin >> listPrice;
    cout << "Please enter the discount percentage: ";
    cin >> discountPercent;

    calculateDiscount(listPrice, discountPercent, discountedPrice);

    cout << "Original price: $" << listPrice << endl;
    cout << "After " << discountPercent << "% discount: $" << discountedPrice << endl;
    cout << "You save: $" << (listPrice - discountedPrice) << endl << endl;

    // 2) Function Two - determineLarger
    int intOne = 0;
    int intTwo = 0;
    int largerValue = 0;

    cout << "Enter integer one: ";
    cin >> intOne;
    cout << "Enter integer two: ";
    cin >> intTwo;

    determineLarger(intOne, intTwo, &largerValue);
    cout << "The larger of the two is: " << largerValue << endl << endl;

    // 3) Function Three - compareArrays
    const int SIZE = 3;
    string arr1[SIZE];
    string arr2[SIZE];

    cout << "Enter 3 strings for arr1:\n";
    for (int i = 0; i < SIZE; ++i) {
        cin >> arr1[i];
    }

    cout << "Enter 3 strings for arr2:\n";
    for (int i = 0; i < SIZE; ++i) {
        cin >> arr2[i];
    }

    bool arraysMatch = compareArrays(arr1, arr2, SIZE);
    cout << "The two arrays do " << (arraysMatch ? "" : "NOT ") << "match.\n\n";

    // 4) Function Four - sortArrays
    string builtInArr[5];
    array<string, 5> stdArr;

    cout << "Enter 5 strings for builtInArr:\n";
    for (int i = 0; i < 5; ++i) {
        cin >> builtInArr[i];
    }

    cout << "Enter 5 strings for stdArr:\n";
    for (int i = 0; i < 5; ++i) {
        cin >> stdArr[i];
    }

    sortArrays(builtInArr, 5, stdArr);

    cout << "builtInArr after sort:\n";
    for (int i = 0; i < 5; ++i) {
        cout << builtInArr[i] << " ";
    }
    cout << endl;

    cout << "stdArr after sort:\n";
    for (const auto &s : stdArr) {
        cout << s << " ";
    }
    cout << endl << endl;

    // 5) Function Five - demoPtrTechniques
    demoPtrTechniques();

    cout << "Program finished.\n";
    return 0;
}