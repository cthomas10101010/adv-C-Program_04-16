#include <iostream>
#include <limits>
#include "ExceptionDemo.h"

using namespace std;

// This program demonstrates exception handling.
// It allows users to select different exception-based operations to see how exceptions work in C++.
// Author: John J

int main() {
    std::cout << "Program 11: Demonstrating Exception Handling\n\n";

    bool exitProgram = false;
    while (!exitProgram) {
        std::cout << "\nSelect an exception-based operation to perform:\n"
                  << " 1) Division by Zero\n"
                  << " 2) Rethrowing Exceptions\n"
                  << " 3) Stack Unwinding\n"
                  << " 4) Throwing bad_alloc with 'new'\n"
                  << " 5) Demonstrate set_new_handler with 'new'\n"
                  << " 6) Exit\n"
                  << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 6.\n";
            continue;
        }

        switch (choice) {
            case 1:
                demoDivisionByZero();
                break;
            case 2:
                demoRethrowingException();
                break;
            case 3:
                demoStackUnwinding();
                break;
            case 4:
                demoBadAlloc();
                break;
            case 5:
                demoSetNewHandler();
                break;
            case 6:
                exitProgram = true;
                break;
            default:
                std::cout << "Invalid choice. Please select a number between 1 and 6.\n";
                break;
        }
    }

    // Graceful exit
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    std::cout << "\n<ENTER> to exit: ";
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


// Chapter 14: File Processing

// Files and streams
// Creating a sequential file
// Reading data from a sequential file
// Updating sequential files
// Random-access files
// Creating a random-access file
// Writing data randomly to a random-access file
// Reading data sequentially from a random-access file
// Case study: A transaction-processing program
// Object serialization
// Wrap-up

// Chapter 15: Standard Library Containers and Iterators

// Introduction to containers
// Introduction to iterators
// Introduction to algorithms
// Sequence containers
// vector sequence container
// list sequence container
// deque sequence container
// Associative containers
// multiset associative container
// set associative container
// multimap associative container
// map associative container
// Container adapters
// stack adapter
// queue adapter
// priority_queue adapter
// Class bitset
// Wrap-up

// Chapter 16: Standard Library Algorithms

// Introduction to algorithms
// Minimum iterator requirements
// Lambda expressions
// Algorithm for_each
// Lambda with an empty introducer
// Lambda with a nonempty introducer—capturing local variables
// Lambda return types
// Algorithms
// fill, fill_n, generate, and generate_n
// equal, mismatch, and lexicographical_compare
// remove, remove_if, remove_copy, and remove_copy_if
// unique, reverse, and rotate
// random_shuffle and shuffle
// partition and stable_partition
// sort, stable_sort, partial_sort, and nth_element
// lower_bound, upper_bound, and equal_range
// merge, includes, set_union, set_intersection, set_difference, and set_symmetric_difference
// min, max, minmax, and minmax_element
// Function objects
// Standard Library algorithm summary
// Wrap-up

// Chapter 17: Exception Handling: A Deeper Look

// Exception-handling flow of control; defining an exception class
// Rethrowing an exception
// Stack unwinding
// When to use exception handling
// noexcept: Declaring functions that do not throw exceptions
// Constructors, destructors, and exception handling
// Processing new failures
// new throwing bad_alloc on failure
// new returning nullptr on failure
// Handling new failures using function set_new_handler
// Class unique_ptr and dynamic memory allocation
// unique_ptr ownership
// unique_ptr to a built-in array
// Standard Library exception hierarchy
// Wrap-up


// must adheer to sall these strict reuieerments::Requirements
// Requirements
// mplete	Requirements
// heck Only if Complete	Requirements
//  #01	This program demonstrates exception handling. Supply appropriate interaction (input/output) with your user. Again, provide appropriate interaction (input/output) with your user.
//  #02	
// In a loop, enable your user to select an action from the list of exception-based operations below:

// Division by zero
// Rethrowing exceptions
// Stack unwinding
// Using the 'new' operator to throw a bad_alloc exception type
// Using the 'new' operator to demonstrate set_new_handler
//  #03	Employ the appropriate try-throw-catch paradigm with each of the above.
//  #04	Provide appropriate feedback/status to your user.
//  #05	Include statements in a file named Statements.txt explaining your technical experiences with Program 11. Make this authentic (minimum of 2-3 sentences).


// 6. Complete and submit the requirements confirmation a also online main function in main.cpp, each .cpp must have a .h file, and the main.cpp must include all the .h files.