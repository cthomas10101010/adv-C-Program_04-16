#include "BitUtilities.h"
#include <iostream>
#include <bitset>
#include <limits>

void BitUtilities::performBitwiseOperations() {
    std::cout << "\n--- Bitwise Operations ---\n";
    
    unsigned int a, b;
    std::cout << "Enter first unsigned integer: ";
    std::cin >> a;
    std::cout << "Enter second unsigned integer: ";
    std::cin >> b;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume newline

    std::cout << "a = " << a << " (" << std::bitset<8>(a) << ")\n";
    std::cout << "b = " << b << " (" << std::bitset<8>(b) << ")\n";

    std::cout << "a & b = " << (a & b) << " (" << std::bitset<8>(a & b) << ")\n";
    std::cout << "a | b = " << (a | b) << " (" << std::bitset<8>(a | b) << ")\n";
    std::cout << "a ^ b = " << (a ^ b) << " (" << std::bitset<8>(a ^ b) << ")\n";
    std::cout << "~a = " << (~a) << " (" << std::bitset<8>(~a) << ")\n";
    std::cout << "a << 1 = " << (a << 1) << " (" << std::bitset<8>(a << 1) << ")\n";
    std::cout << "a >> 1 = " << (a >> 1) << " (" << std::bitset<8>(a >> 1) << ")\n";
}