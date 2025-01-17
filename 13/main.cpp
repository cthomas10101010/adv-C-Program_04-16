
#include <iostream>
#include <string>
#include <limits> // Include this header for std::numeric_limits
#include "List.h"

int main() {
    std::cout << "Program 13: Demonstrating Custom Templatized Data Structures\n\n";

    bool exitProgram = false;
    while (!exitProgram) {
        std::cout << "\nSelect the type of list:\n"
                  << " 1) Integer List\n"
                  << " 2) Double List\n"
                  << " 3) String List\n"
                  << " 4) Exit\n"
                  << "Enter your choice: ";
        int listChoice;
        std::cin >> listChoice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (listChoice) {
            case 1: {
                List<int> intList;
                bool exitIntList = false;
                while (!exitIntList) {
                    std::cout << "\nInteger List Operations:\n"
                              << " 1) Insert at Beginning\n"
                              << " 2) Insert at End\n"
                              << " 3) Delete from Beginning\n"
                              << " 4) Delete from End\n"
                              << " 5) Insert at Index\n"
                              << " 6) Delete by Value\n"
                              << " 7) Display List\n"
                              << " 8) Back to List Type Selection\n"
                              << "Enter your choice: ";
                    int opChoice;
                    std::cin >> opChoice;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter a number between 1 and 8.\n";
                        continue;
                    }

                    try {
                        switch (opChoice) {
                            case 1: {
                                int value;
                                std::cout << "Enter integer to insert at beginning: ";
                                std::cin >> value;
                                intList.insertAtBeginning(value);
                                std::cout << value << " inserted at the beginning of the list.\n";
                                break;
                            }
                            case 2: {
                                int value;
                                std::cout << "Enter integer to insert at end: ";
                                std::cin >> value;
                                intList.insertAtEnd(value);
                                std::cout << value << " inserted at the end of the list.\n";
                                break;
                            }
                            case 3: {
                                int value = intList.deleteFromBeginning();
                                std::cout << value << " deleted from the beginning of the list.\n";
                                break;
                            }
                            case 4: {
                                int value = intList.deleteFromEnd();
                                std::cout << value << " deleted from the end of the list.\n";
                                break;
                            }
                            case 5: {
                                int index, value;
                                std::cout << "Enter index to insert at: ";
                                std::cin >> index;
                                std::cout << "Enter integer to insert: ";
                                std::cin >> value;
                                intList.insertAt(index, value);
                                std::cout << value << " inserted at index " << index << ".\n";
                                break;
                            }
                            case 6: {
                                int value;
                                std::cout << "Enter integer value to delete: ";
                                std::cin >> value;
                                intList.deleteByValue(value);
                                std::cout << value << " deleted from the list.\n";
                                break;
                            }
                            case 7: {
                                std::cout << "Current List: ";
                                intList.display();
                                break;
                            }
                            case 8:
                                exitIntList = true;
                                break;
                            default:
                                std::cout << "Invalid choice. Please select a number between 1 and 8.\n";
                                break;
                        }
                    }
                    catch (const std::exception& e) {
                        std::cout << "Exception: " << e.what() << "\n";
                    }
                }
                break;
            }
            case 2: {
                List<double> doubleList;
                bool exitDoubleList = false;
                while (!exitDoubleList) {
                    std::cout << "\nDouble List Operations:\n"
                              << " 1) Insert at Beginning\n"
                              << " 2) Insert at End\n"
                              << " 3) Delete from Beginning\n"
                              << " 4) Delete from End\n"
                              << " 5) Insert at Index\n"
                              << " 6) Delete by Value\n"
                              << " 7) Display List\n"
                              << " 8) Back to List Type Selection\n"
                              << "Enter your choice: ";
                    int opChoice;
                    std::cin >> opChoice;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter a number between 1 and 8.\n";
                        continue;
                    }

                    try {
                        switch (opChoice) {
                            case 1: {
                                double value;
                                std::cout << "Enter double to insert at beginning: ";
                                std::cin >> value;
                                doubleList.insertAtBeginning(value);
                                std::cout << value << " inserted at the beginning of the list.\n";
                                break;
                            }
                            case 2: {
                                double value;
                                std::cout << "Enter double to insert at end: ";
                                std::cin >> value;
                                doubleList.insertAtEnd(value);
                                std::cout << value << " inserted at the end of the list.\n";
                                break;
                            }
                            case 3: {
                                double value = doubleList.deleteFromBeginning();
                                std::cout << value << " deleted from the beginning of the list.\n";
                                break;
                            }
                            case 4: {
                                double value = doubleList.deleteFromEnd();
                                std::cout << value << " deleted from the end of the list.\n";
                                break;
                            }
                            case 5: {
                                int index;
                                double value;
                                std::cout << "Enter index to insert at: ";
                                std::cin >> index;
                                std::cout << "Enter double to insert: ";
                                std::cin >> value;
                                doubleList.insertAt(index, value);
                                std::cout << value << " inserted at index " << index << ".\n";
                                break;
                            }
                            case 6: {
                                double value;
                                std::cout << "Enter double value to delete: ";
                                std::cin >> value;
                                doubleList.deleteByValue(value);
                                std::cout << value << " deleted from the list.\n";
                                break;
                            }
                            case 7: {
                                std::cout << "Current List: ";
                                doubleList.display();
                                break;
                            }
                            case 8:
                                exitDoubleList = true;
                                break;
                            default:
                                std::cout << "Invalid choice. Please select a number between 1 and 8.\n";
                                break;
                        }
                    }
                    catch (const std::exception& e) {
                        std::cout << "Exception: " << e.what() << "\n";
                    }
                }
                break;
            }
            case 3: {
                List<std::string> stringList;
                bool exitStringList = false;
                while (!exitStringList) {
                    std::cout << "\nString List Operations:\n"
                              << " 1) Insert at Beginning\n"
                              << " 2) Insert at End\n"
                              << " 3) Delete from Beginning\n"
                              << " 4) Delete from End\n"
                              << " 5) Insert at Index\n"
                              << " 6) Delete by Value\n"
                              << " 7) Display List\n"
                              << " 8) Back to List Type Selection\n"
                              << "Enter your choice: ";
                    int opChoice;
                    std::cin >> opChoice;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter a number between 1 and 8.\n";
                        continue;
                    }

                    try {
                        switch (opChoice) {
                            case 1: {
                                std::string value;
                                std::cout << "Enter string to insert at beginning: ";
                                std::cin.ignore(); // To consume the leftover newline
                                std::getline(std::cin, value);
                                stringList.insertAtBeginning(value);
                                std::cout << "\"" << value << "\" inserted at the beginning of the list.\n";
                                break;
                            }
                            case 2: {
                                std::string value;
                                std::cout << "Enter string to insert at end: ";
                                std::cin.ignore();
                                std::getline(std::cin, value);
                                stringList.insertAtEnd(value);
                                std::cout << "\"" << value << "\" inserted at the end of the list.\n";
                                break;
                            }
                            case 3: {
                                std::string value = stringList.deleteFromBeginning();
                                std::cout << "\"" << value << "\" deleted from the beginning of the list.\n";
                                break;
                            }
                            case 4: {
                                std::string value = stringList.deleteFromEnd();
                                std::cout << "\"" << value << "\" deleted from the end of the list.\n";
                                break;
                            }
                            case 5: {
                                int index;
                                std::string value;
                                std::cout << "Enter index to insert at: ";
                                std::cin >> index;
                                std::cin.ignore(); // Consume the newline
                                std::cout << "Enter string to insert: ";
                                std::getline(std::cin, value);
                                stringList.insertAt(index, value);
                                std::cout << "\"" << value << "\" inserted at index " << index << ".\n";
                                break;
                            }
                            case 6: {
                                std::string value;
                                std::cout << "Enter string value to delete: ";
                                std::cin.ignore();
                                std::getline(std::cin, value);
                                stringList.deleteByValue(value);
                                std::cout << "\"" << value << "\" deleted from the list.\n";
                                break;
                            }
                            case 7: {
                                std::cout << "Current List: ";
                                stringList.display();
                                break;
                            }
                            case 8:
                                exitStringList = true;
                                break;
                            default:
                                std::cout << "Invalid choice. Please select a number between 1 and 8.\n";
                                break;
                        }
                    }
                    catch (const std::exception& e) {
                        std::cout << "Exception: " << e.what() << "\n";
                    }
                }
                break;
            }
            case 4:
                exitProgram = true;
                break;
            default:
                std::cout << "Invalid choice. Please select a number between 1 and 4.\n";
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



// must adheer to sall these strict reuieerments::Requirements
// Requirements
// This program demonstrates custom templatized data structures. Supply appropriate interaction (input/output) with your user. Again, provide appropriate interaction (input/output) with your user.
//  #02	Implement a Custom Class List Template with the capabilities outlined below.
//  #03	
// In a loop, enable your user to select an action from the list of operations of the Custom Class List Template:

// insert at the beginning of the list
// insert at the end of the list
// delete from the beginning of the list
// delete from the end of the list
// insert at a location (index value) in the list
// delete a node from the list based on its value
// end list processing
//  #04	Appropriately catch exceptions thrown during list operations. Do not exit upon exception. Notify user of exception and provide another list operation opportunity.

// 6. Complete and submit the requirements confirmation a also online main function in main.cpp, each .cpp must have a .h file, and the main.cpp must include all the .h files.