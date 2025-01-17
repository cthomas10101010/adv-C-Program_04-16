#include "CStringUtilities.h"
#include <iostream>
#include <cstring>
#include <algorithm> // Required for std::reverse

void CStringUtilities::handleCStrings() {
    std::cout << "\n--- C-String Operations ---\n";

    const int SIZE = 100;
    char str1[SIZE], str2[SIZE];

    std::cout << "Enter first C-string: ";
    std::cin.getline(str1, SIZE);
    std::cout << "Enter second C-string: ";
    std::cin.getline(str2, SIZE);

    // Copy
    char copyStr[SIZE];
    strcpy(copyStr, str1);
    std::cout << "Copied String: " << copyStr << "\n";

    // Concatenate
    strcat(copyStr, " ");
    strcat(copyStr, str2);
    std::cout << "Concatenated String: " << copyStr << "\n";

    // Compare
    int cmp = strcmp(str1, str2);
    if (cmp == 0)
        std::cout << "The C-strings are equal.\n";
    else
        std::cout << "The C-strings are not equal.\n";

    // Length
    std::cout << "Length of first C-string: " << strlen(str1) << "\n";
    std::cout << "Length of second C-string: " << strlen(str2) << "\n";

    // Reverse
    std::reverse(str1, str1 + strlen(str1)); // Ensure std::reverse is correctly used
    std::cout << "Reversed first C-string: " << str1 << "\n";
}