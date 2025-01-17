#include "StringUtilities.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

void StringUtilities::promptUserStrings() {
    std::cout << "Enter the first string: ";
    std::getline(std::cin, str1);
    std::cout << "Enter the second string: ";
    std::getline(std::cin, str2);
}

void StringUtilities::assignStrings() {
    std::cout << "\n--- String Assignments ---\n";

    // Method 1: Initialization
    std::string s1 = "Hello";
    std::cout << "Method 1 - Initialization: " << s1 << "\n";

    // Method 2: Assignment Operator
    std::string s2;
    s2 = "World";
    std::cout << "Method 2 - Assignment Operator: " << s2 << "\n";

    // Method 3: Constructor with C-style string
    std::string s3("C++ Programming");
    std::cout << "Method 3 - Constructor with C-style string: " << s3 << "\n";
}

void StringUtilities::concatenateStrings() {
    std::cout << "\n--- String Concatenation ---\n";

    // Method 1: Using + operator
    std::string concat1 = str1 + " " + str2;
    std::cout << "Method 1 - Using + operator: " << concat1 << "\n";

    // Method 2: Using append() function
    std::string concat2 = str1;
    concat2.append(" ").append(str2);
    std::cout << "Method 2 - Using append() function: " << concat2 << "\n";
}

void StringUtilities::compareSubstrings() {
    std::cout << "\n--- Compare Substrings ---\n";
    if (str1.empty() || str2.empty()) {
        std::cout << "One of the strings is empty. Cannot perform comparison.\n";
        return;
    }

    int start1, length1, start2, length2;
    std::cout << "Enter start index for first string: ";
    std::cin >> start1;
    std::cout << "Enter length for first string substring: ";
    std::cin >> length1;
    std::cin.ignore(); // Consume leftover newline

    std::cout << "Enter start index for second string: ";
    std::cin >> start2;
    std::cout << "Enter length for second string substring: ";
    std::cin >> length2;
    std::cin.ignore(); // Consume leftover newline

    // Validate indices
    if (start1 < 0 || start1 + length1 > str1.length() ||
        start2 < 0 || start2 + length2 > str2.length()) {
        std::cout << "Invalid substring indices.\n";
        return;
    }

    std::string substr1 = str1.substr(start1, length1);
    std::string substr2 = str2.substr(start2, length2);

    std::cout << "Substring from first string: \"" << substr1 << "\"\n";
    std::cout << "Substring from second string: \"" << substr2 << "\"\n";

    if (substr1 == substr2) {
        std::cout << "The substrings are equal.\n";
    }
    else {
        std::cout << "The substrings are not equal.\n";
    }
}

void StringUtilities::displayStringForward() {
    std::cout << "\n--- Display String Forward ---\n";
    std::cout << "Forward Order: ";
    for (std::string::iterator it = str1.begin(); it != str1.end(); ++it) {
        std::cout << *it;
    }
    std::cout << "\n";
}

void StringUtilities::displayStringReverse() {
    std::cout << "\n--- Display String Reverse ---\n";
    std::cout << "Reverse Order: ";
    for (std::string::reverse_iterator rit = str1.rbegin(); rit != str1.rend(); ++rit) {
        std::cout << *rit;
    }
    std::cout << "\n";
}

void StringUtilities::demonstrateIOStreams() {
    std::cout << "\n--- I/O Streams Demonstration ---\n";

    // Standard I/O (monitor)
    std::cout << "Standard I/O:\n";
    std::cout << "You entered: " << str1 << " and " << str2 << "\n";

    // File I/O
    std::ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << "File I/O Example:\n";
        outFile << "First String: " << str1 << "\n";
        outFile << "Second String: " << str2 << "\n";
        outFile.close();
        std::cout << "File I/O: Data written to output.txt\n";
    }
    else {
        std::cout << "Unable to open file for writing.\n";
    }

    std::ifstream inFile("output.txt");
    if (inFile.is_open()) {
        std::cout << "File I/O: Reading from output.txt\n";
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << "\n";
        }
        inFile.close();
    }
    else {
        std::cout << "Unable to open file for reading.\n";
    }

    // String Stream I/O
    std::stringstream ss;
    ss << "String Stream I/O Example:\n";
    ss << "First String: " << str1 << "\n";
    ss << "Second String: " << str2 << "\n";
    std::cout << "String Stream I/O:\n" << ss.str();

    // Extracting data from string stream
    std::string extracted;
    std::getline(ss, extracted);
    std::cout << "Extracted from string stream: " << extracted << "\n";
}