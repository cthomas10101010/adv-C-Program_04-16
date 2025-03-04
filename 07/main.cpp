#include <iostream>
#include <limits>
#include "PhoneNumber.h"

int main() {
    std::cout << "Program 07: Demonstrating Overloaded Stream Operators\n\n";

    bool done = false;

    while (!done) {
        PhoneNumber number;

        std::cout << "Enter a phone number of the form (888) 555-1234: ";
        std::cin >> number;
        
        // Clear any remaining characters in the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin.fail()) {
            // Success: show data
            std::cout << "\nPhone number entered successfully!\n";
            std::cout << "Raw phone array: \"" << number.getPhone() << "\"\n";
            std::cout << "Area code: \"" << number.getAreaCode() << "\"\n";
            std::cout << "Exchange: \"" << number.getExchange() << "\"\n";
            std::cout << "Line: \"" << number.getLine() << "\"\n";
            std::cout << "Formatted number: " << number << "\n";  // Added this line to show overloaded << operator
        } else {
            // Fail: clear error, show message
            std::cin.clear();
            std::cout << "\nInvalid phone number entered.\n";
        }

        // Ask if user wants to try another number
        std::cout << "\nWould you like to enter another phone number? (y/n) ";
        char response;
        std::cin >> response;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (response != 'y' && response != 'Y') {
            done = true;
        }
    }

    // Graceful exit per requirement - fixed to match exact specification
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    std::cout << "\n\n<ENTER> to exit: ";
    std::cin.get();

    return 0;
}