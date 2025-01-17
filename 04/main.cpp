#include <iostream>
#include <limits>  // for std::numeric_limits
#include "OverloadDemo.h"

int main() {
    std::cout << "Program 04: Operator Overloading Demo\n\n";

    // Prompt user for values of obj1
    int iVal;
    double dVal;
    std::string sVal;

    std::cout << "Enter values for obj1 (int, double, string): ";
    // Make sure to enter all three on one line (e.g., "5 3.2 Hello")
    std::cin >> iVal >> dVal;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear leftover input
    std::getline(std::cin, sVal);

    OverloadDemo obj1(iVal, dVal, sVal);

    // Prompt user for values of obj2
    std::cout << "Enter values for obj2 (int, double, string): ";
    // Same requirement: all three on one line (e.g., "2 1.5 World")
    std::cin >> iVal >> dVal;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::getline(std::cin, sVal);

    OverloadDemo obj2(iVal, dVal, sVal);

    std::cout << "\nobj1: (" << obj1.getIntOne() << ", "
              << obj1.getDoubleOne() << ", "
              << obj1.getStringOne() << ")\n";
    std::cout << "obj2: (" << obj2.getIntOne() << ", "
              << obj2.getDoubleOne() << ", "
              << obj2.getStringOne() << ")\n\n";

    // Demonstrate +
    OverloadDemo sum = obj1 + obj2;
    std::cout << "obj1 + obj2 => ("
              << sum.getIntOne() << ", "
              << sum.getDoubleOne() << ", "
              << sum.getStringOne() << ")\n";

    // Demonstrate -
    OverloadDemo diff = obj1 - obj2;
    std::cout << "obj1 - obj2 => ("
              << diff.getIntOne() << ", "
              << diff.getDoubleOne() << ", "
              << diff.getStringOne() << ")\n";

    // Demonstrate *
    OverloadDemo product = obj1 * obj2;
    std::cout << "obj1 * obj2 => ("
              << product.getIntOne() << ", "
              << product.getDoubleOne() << ", "
              << product.getStringOne() << ")\n";

    // Demonstrate /
    OverloadDemo quotient = obj1 / obj2;
    std::cout << "obj1 / obj2 => ("
              << quotient.getIntOne() << ", "
              << quotient.getDoubleOne() << ", "
              << quotient.getStringOne() << ")\n\n";

    // Demonstrate prefix increment
    std::cout << "++obj1 => ";
    ++obj1;
    std::cout << "(" << obj1.getIntOne() << ", "
              << obj1.getDoubleOne() << ", "
              << obj1.getStringOne() << ")\n";

    // Demonstrate postfix increment
    std::cout << "obj2++ => ";
    obj2++;
    std::cout << "(" << obj2.getIntOne() << ", "
              << obj2.getDoubleOne() << ", "
              << obj2.getStringOne() << ")\n\n";

    // Demonstrate prefix decrement
    std::cout << "--obj1 => ";
    --obj1;
    std::cout << "(" << obj1.getIntOne() << ", "
              << obj1.getDoubleOne() << ", "
              << obj1.getStringOne() << ")\n";

    // Demonstrate postfix decrement
    std::cout << "obj2-- => ";
    obj2--;
    std::cout << "(" << obj2.getIntOne() << ", "
              << obj2.getDoubleOne() << ", "
              << obj2.getStringOne() << ")\n\n";

    std::cout << "End of Program 04 Demo\n";

    return 0;
}