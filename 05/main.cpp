#include <iostream>
#include <limits>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

int main() {
    std::cout << "Program 05: Demonstrating Inheritance\n\n";

    // Prompt user for Package details
    std::string sName, sAddr, sCity, sSt, sZip;
    std::string rName, rAddr, rCity, rSt, rZip;
    double weight, costPerOunce;

    std::cout << "Enter sender information (Name Address City State Zip):\n";
    std::cin >> sName >> sAddr >> sCity >> sSt >> sZip;

    std::cout << "Enter receiver information (Name Address City State Zip):\n";
    std::cin >> rName >> rAddr >> rCity >> rSt >> rZip;

    std::cout << "Enter weight and costPerOunce (e.g. 5 0.5):\n";
    std::cin >> weight >> costPerOunce;

    // Create a base Package
    Package basePkg(sName, sAddr, sCity, sSt, sZip,
                    rName, rAddr, rCity, rSt, rZip,
                    weight, costPerOunce);

    std::cout << "\nBase Package cost: " << basePkg.calculateCost() << "\n\n";

    // Prompt user for TwoDayPackage fee
    double twoDayFee;
    std::cout << "Enter twoDayFee (e.g. 2.0): ";
    std::cin >> twoDayFee;

    TwoDayPackage twoDayPkg(sName, sAddr, sCity, sSt, sZip,
                            rName, rAddr, rCity, rSt, rZip,
                            weight, costPerOunce, twoDayFee);

    std::cout << "TwoDayPackage cost: " << twoDayPkg.calculateCost() << "\n\n";

    // Prompt user for OvernightPackage rate
    double overnightRate;
    std::cout << "Enter overnightRate (e.g. 0.75): ";
    std::cin >> overnightRate;

    OvernightPackage overnightPkg(sName, sAddr, sCity, sSt, sZip,
                                  rName, rAddr, rCity, rSt, rZip,
                                  weight, costPerOunce, overnightRate);

    std::cout << "OvernightPackage cost: " << overnightPkg.calculateCost() << "\n\n";

    std::cout << "End of Program 05\n";
    return 0;
}

// very important you must only use what is covered in these chapters:: Chapter 7: Class Templates array and vector; Catching Exceptions

// Introduction to class templates array and vector
// Declaring and using arrays
// Examples of array usage
// Range-based for statement
// Case study: Class GradeBook using an array to store grades
// Sorting and searching arrays
// Multidimensional arrays
// Case study: Class GradeBook using a two-dimensional array
// Introduction to C++ Standard Library class template vector
// Wrap-up
// Chapter 8: Pointers

// Introduction to pointers
// Pointer variable declarations and initialization
// Pointer operators
// Pass-by-reference with pointers
// Built-in arrays
// Using const with pointers
// sizeof operator
// Pointer expressions and pointer arithmetic
// Relationship between pointers and built-in arrays
// Pointer-based strings (optional)
// Note about smart pointers
// Wrap-up
// Chapter 9: Classes: A Deeper Look

// Time class case study: Separating interface from implementation
// Compilation and linking process
// Class scope and accessing class members
// Access functions and utility functions
// Time class case study: Constructors with default arguments
// Destructors
// When constructors and destructors are called
// Time class case study: A subtle trap—returning a reference or a pointer to a private data member
// Default memberwise assignment
// const objects and const member functions
// Composition: Objects as members of classes
// friend functions and friend classes
// Using the this pointer
// static class members
// Wrap-up
// Chapter 10: Operator Overloading; Class string

// Using the overloaded operators of Standard Library class string
// Fundamentals of operator overloading
// Overloading binary operators
// Overloading the binary stream insertion and stream extraction operators
// Overloading unary operators
// Overloading the increment and decrement operators
// Case study: A Date class
// Dynamic memory management
// Case study: Array class
// Operators as member vs. non-member functions
// Converting between types
// explicit constructors and conversion operators
// Overloading the function call operator ()
// Wrap-up
// Chapter 11: Object-Oriented Programming: Inheritance

// Base classes and derived classes
// Relationship between base and derived classes
// Constructors and destructors in derived classes
// public, protected, and private inheritance
// Wrap-up 

// must adheer to sall these strict reuieerments::Requirements
//  #01	This program demonstrates inheritance. Supply appropriate interaction (input/output) with your user. Again, provide appropriate interaction (input/output) with your user.
//  #02	Class Package - contains the following:
// Member data: name, address, city, state, zip for both sender and receiver. weight, costPerOunce
// Member functions: constructor to initialize all member data. setters and getters for all member data
// Member function: calculateCost() returns a double of weight x costPerOunce
// Ensure weight and costPerOunce > 0
//  #03	Class TwoDayPackage - inherits from Class Package and contains the following:
// Member data: twoDayFee (an additional flat rate fee for two day shipping)
// Member functions: setTwoDayFee(), getTwoDayFee(), Override calculateCost() to include twoDayFee
//  #04	Class OvernightPackage - inherits from Class Package and contains the following:
// Member data: overnightRate (an additional cost per ounce rate for overnight shipping)
// Member functions: setOvernightRate(), getOvernightRate(), Override calculateCost() to include overnightRate
//  #05	Include statements in a file named Statements.txt explaining your technical experiences with Program 05. Make this authentic (minimum of 2-3 sentences).
//  and these general reuienements • The requirements below are common to all program assignments
// • Use techniques in the chapters specified in each assignment to solve the
// coding requirements. Also, use information from previous chapters as
// required. Do NOT use techniques beyond the sections up to and including
// the current assignment.
// • Develop the application for your user – Communicate with your user. This
// means - output the progress/purpose of your program. For instance, if a
// requirement is to sort an array, output the results – the sorted array.
// Common Requirements:
// 1. Submit at least three screenshots of your program successfully running.
// Submit your screenshots to Bb individually; do not .zip.
// 2. Include statements in a file named Statements.txt explaining your technical
// experiences with the program. Make this authentic (minimum of 2-3
// sentences). Minimal effort on experience statements will impact grade.
// 3. Compose your experience statement in a Statements.txt file and submit
// individually, at the top level, like your screenshots.
// 4. After completing your program, screenshots, and Statements.txt file,
// compress the Project Directory (created by Visual Studio). To compress, in
// Windows File Manager, compress the Project Directory by R-clicking on the
// directory | Send to | Compressed (zipped) folder. This will produce a .zip
// file of the compressed Project Directory.
// 5. Upload your screenshots, and Statements.txt file, and compressed Project
// Directory (.zip file) to Bb by the due date. The screenshots and
// Statements.txt should NOT be compressed in your Project Directory.
// 6. Complete and submit the requirements confirmation a also online main function in main.cpp, each .cpp must have a .h file, and the main.cpp must include all the .h files.