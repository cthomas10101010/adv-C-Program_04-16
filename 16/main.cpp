#include <iostream>
#include <limits>
#include "StringUtilities.h"
#include "BitUtilities.h"
#include "CStringUtilities.h"
#include "StructUtilities.h"

int main() {
    std::cout << "Program 16: Demonstrating Advanced Operations in C++\n\n";

    try {
        // String Operations
        StringUtilities su;
        su.promptUserStrings();
        su.assignStrings();
        su.concatenateStrings();
        su.compareSubstrings();
        su.displayStringForward();
        su.displayStringReverse();
        su.demonstrateIOStreams();

        // Bitwise Operations
        BitUtilities bu;
        bu.performBitwiseOperations();

        // C-String Operations
        CStringUtilities cu;
        cu.handleCStrings();

        // Structure Operations
        StructUtilities steu;
        steu.handleStructures();
    }
    catch (const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << "\n";
    }

    // Graceful exit
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    std::cout << "\n<ENTER> to exit: ";
    std::cin.get();

    return 0;
}