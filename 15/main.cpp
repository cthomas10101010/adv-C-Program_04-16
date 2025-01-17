#include <iostream>
#include <limits> // Include this header for std::numeric_limits
#include "StringUtilities.h"

int main() {
    std::cout << "Program 15: Demonstrating String Operations and String Stream Processing\n\n";

    StringUtilities su;
    su.promptUserStrings();
    su.assignStrings();
    su.concatenateStrings();
    su.compareSubstrings();
    su.displayStringForward();
    su.displayStringReverse();
    su.demonstrateIOStreams();

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
// Chapter 18: Introduction to Custom Templates

// Class templates
// Creating class template Stack<T>
// Class template Stack<T>’s data representation
// Class template Stack<T>’s member functions
// Declaring a class template’s member functions outside the class template definition
// Testing class template Stack<T>
// Function template to manipulate a class-template specialization object
// Nontype parameters
// Default arguments for template type parameters
// Overloading function templates
// Wrap-up

// Chapter 19: Custom Templatized Data Structures

// Self-Referential Classes: Introduction to classes that contain pointers to instances of the same class.
// Linked Lists:
// Implementing singly linked lists using class templates.
// Operations such as insertion, deletion, and traversal.
// Testing the linked list implementation.
// Stacks:
// Implementing stack data structures using linked lists.
// Push and pop operations.
// Queues:
// Implementing queue data structures using linked lists.
// Enqueue and dequeue operations.
// Trees:
// Introduction to binary trees and binary search trees.
// Insertion, searching, and traversal algorithms.
// Wrap-Up: Summary of custom templated data structures and their applications.

// Chapter 20: Searching and Sorting

// Searching Algorithms:
// Linear search: Sequentially searching through data.
// Binary search: Efficient searching in sorted data.
// Sorting Algorithms:
// Insertion sort: Building a sorted array one item at a time.
// Selection sort: Repeatedly selecting the smallest element.
// Merge sort: Dividing the array into halves, sorting, and merging.
// Wrap-Up: Overview of algorithm efficiency and Big-O notation.


// Chapter 21: Class string and String Stream Processing: A Deeper Look

// Class string:
// String assignment and concatenation.
// Comparing strings.
// Extracting substrings.
// Swapping, finding, and replacing characters in strings.
// Inserting characters into strings.
// Converting strings to C-style strings.
// String Stream Processing:
// Using string streams for input and output operations.
// Formatting data with string streams.
// Wrap-Up: Best practices for using the string class and string streams.

// must adheer to sall these strict reuieerments::Requirements
// Requirements
// T
// Check Only if Complete	Requirements
 
// Check Only if Complete	Requirements
//  #01	This program demonstrates string operations and string stream processing. Supply appropriate interaction (input/output) with your user. Again, provide appropriate interaction (input/output) with your user.
//  #02	Prompt your user to enter strings used in operations below.
//  #03	Demonstrate three ways to assign values to strings.
//  #04	Demonstrate two ways to concatenate strings.
//  #05	Enable your user to select which portions of two strings to compare with one another and compare those portions.
//  #06	Demonstrate a string iterator displaying a string in forward order.
//  #07	Demonstrate a string iterator displaying a string in reverse order.
//  #08	
// Demonstrate the three common I/O streams using insertion (<<) and extraction(>>) operators:

// standard I/O (monitor)
// file I/O
// string stream I/O
//  #09	Include statements in a file named Statements.txt explaining your technical experiences with Program 15. Make this authentic (minimum of 2-3 sentences).



// 6. Complete and submit the requirements confirmation a also online main function in main.cpp, each .cpp must have a .h file, and the main.cpp must include all the .h files.