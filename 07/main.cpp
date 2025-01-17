
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

        if (!std::cin.fail()) {
            // Success: show data
            std::cout << "\nPhone number entered successfully!\n";
            std::cout << "Full raw phone array: " << number << "\n";
            // or if you want to display area code/exchange/line separately, you'd write accessors
        } else {
            // Fail: clear error, show message
            std::cin.clear();
            std::cout << "\nInvalid phone number entered.\n";
        }

        // Ask if user wants to try another number
        std::cout << "\nWould you like to enter another phone number? (y/n) ";
        char response;
        std::cin >> response;
        // Clear leftover newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (response != 'y' && response != 'Y') {
            done = true;
        }
    }

    // Graceful exit per requirement
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    std::cout << "\n\n<ENTER> to exit: ";
    std::cin.get();

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
// Chapter 13: Stream Input/Output: A Deeper Look

// Streams
// Stream output
// Stream input
// Unformatted I/O using read, write, and gcount
// Stream manipulators: A deeper look
// Stream format states and stream manipulators
// Stream error states
// Tying an output stream to an input stream
// Wrap-up



// must adheer to sall these strict reuieerments::Requirements
// his program demonstrates overloaded stream operators. Supply appropriate interaction (input/output) with your user. Again, provide appropriate interaction (input/output) with your user.
//  #02	Begin with code Fig. 10.3, Fig. 10.4, and Fig. 10.5. Modify that code as follows.
//  #03	The PhoneNumber class should include the following member data:

// private:
// char phone[15]; // holds entire phone number plus \0
// char areaCode[4]; // holds area code plus \0
// char exchange[4]; // holds exchange plus \0
// char line[5]; // holds line plus \0
//  #04	Rewrite the overloaded extraction operator to include the following:
// Phone number should be entered of the form: (888) 555-1234
// Input the entire phone number (from user) into the phone[] character array.
// Test that the correct number of characters (14) have been entered.
// Test that the area code and exchange do not begin with 0 or 1.
// Set the fail bit using "input.setstate(ios::failbit)" if an error condition is encountered.
//  #05	If the fail bit has been set then message that an invalid phone number has been entered and ask your user if s/he would like to enter another phone number.
//  #06	If the fail bit has NOT been set then copy the appropriate parts of the phone[] array into the PhoneNumber object data members. Output the PhoneNumber object data members and other relevant information to your user.
//  #07	Include the following at the end of main() to provide a graceful exit:

// cin.ignore(numeric_limits<streamsize>::max(), '\n');
// cin.clear();
// cout << "\n\n<ENTER> to exit: ";
// cin.get();
//  #08	Include statements in a file named Statements.txt explaining your technical experiences with Program 07. Make this authentic (minimum of 2-3 sentences).
// Submit screenshots and Statements.txt files individually (not compressed). Compress project directory and submit to
// 6. Complete and submit the requirements confirmation a also online main function in main.cpp, each .cpp must have a .h file, and the main.cpp must include all the .h files.