#ifndef STRINGUTILITIES_H
#define STRINGUTILITIES_H

#include <string>

class StringUtilities {
private:
    std::string str1;
    std::string str2;

public:
    /**
     * @brief Prompts the user to enter two strings.
     */
    void promptUserStrings();

    /**
     * @brief Demonstrates three ways to assign values to strings.
     */
    void assignStrings();

    /**
     * @brief Demonstrates two ways to concatenate strings.
     */
    void concatenateStrings();

    /**
     * @brief Enables the user to select portions of two strings to compare.
     */
    void compareSubstrings();

    /**
     * @brief Displays a string in forward order using an iterator.
     */
    void displayStringForward();

    /**
     * @brief Displays a string in reverse order using a reverse iterator.
     */
    void displayStringReverse();

    /**
     * @brief Demonstrates standard I/O, file I/O, and string stream I/O.
     */
    void demonstrateIOStreams();
};

#endif // STRINGUTILITIES_H