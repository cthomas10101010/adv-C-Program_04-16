#include "ExceptionDemo.h"
#include <iostream>
#include <new>
#include <exception>
#include <cstdlib>

// Custom exception class for division by zero
class DivisionByZeroException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Division by zero is undefined.";
    }
};

// Function to demonstrate Division by Zero exception handling
void demoDivisionByZero() {
    std::cout << "\n--- Division by Zero Demo ---\n";
    int numerator, denominator;
    std::cout << "Enter numerator: ";
    std::cin >> numerator;
    std::cout << "Enter denominator: ";
    std::cin >> denominator;

    try {
        if (denominator == 0) {
            throw DivisionByZeroException();
        }
        double result = static_cast<double>(numerator) / denominator;
        std::cout << "Result: " << result << "\n";
    }
    catch (const DivisionByZeroException& e) {
        std::cout << e.what() << "\n";
    }
    catch (...) {
        std::cout << "An unexpected error occurred.\n";
    }
}

// Function to demonstrate Rethrowing Exceptions
void demoRethrowingException() {
    std::cout << "\n--- Rethrowing Exceptions Demo ---\n";

    try {
        try {
            std::cout << "Attempting to perform an invalid operation...\n";
            throw std::runtime_error("Initial exception.");
        }
        catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << "\n";
            std::cout << "Rethrowing the exception...\n";
            throw; // Rethrow the current exception
        }
    }
    catch (const std::exception& e) {
        std::cout << "Caught rethrown exception: " << e.what() << "\n";
    }
    catch (...) {
        std::cout << "An unexpected error occurred.\n";
    }
}

// Function to demonstrate Stack Unwinding
void functionLevel3() {
    std::cout << "Entering functionLevel3.\n";
    throw std::runtime_error("Exception in functionLevel3.");
    std::cout << "Exiting functionLevel3.\n"; // This line will not be executed
}

void functionLevel2() {
    std::cout << "Entering functionLevel2.\n";
    try {
        functionLevel3();
    }
    catch (const std::exception& e) {
        std::cout << "Caught in functionLevel2: " << e.what() << "\n";
        throw; // Rethrow to demonstrate further stack unwinding
    }
    std::cout << "Exiting functionLevel2.\n";
}

void functionLevel1() {
    std::cout << "Entering functionLevel1.\n";
    try {
        functionLevel2();
    }
    catch (const std::exception& e) {
        std::cout << "Caught in functionLevel1: " << e.what() << "\n";
    }
    std::cout << "Exiting functionLevel1.\n";
}

void demoStackUnwinding() {
    std::cout << "\n--- Stack Unwinding Demo ---\n";
    try {
        functionLevel1();
    }
    catch (const std::exception& e) {
        std::cout << "Caught in main: " << e.what() << "\n";
    }
    catch (...) {
        std::cout << "An unexpected error occurred in main.\n";
    }
}

// Custom new handler to demonstrate set_new_handler
void customNewHandler() {
    std::cerr << "Custom new handler called: Unable to allocate memory.\n";
    std::exit(EXIT_FAILURE); // Terminate the program
}

// Function to demonstrate throwing bad_alloc using 'new'
void demoBadAlloc() {
    std::cout << "\n--- Throwing bad_alloc with 'new' Demo ---\n";

    try {
        // Attempt to allocate an extremely large amount of memory to force bad_alloc
        std::cout << "Attempting to allocate a huge block of memory...\n";
        size_t size = static_cast<size_t>(-1); // Maximum possible size
        int* ptr = new int[size]; // This should throw bad_alloc
        // If allocation succeeds (which is highly unlikely), prevent memory leak
        delete[] ptr;
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Caught bad_alloc exception: " << e.what() << "\n";
    }
    catch (...) {
        std::cout << "An unexpected error occurred.\n";
    }
}

// Function to demonstrate set_new_handler with 'new'
void demoSetNewHandler() {
    std::cout << "\n--- set_new_handler with 'new' Demo ---\n";

    // Set the custom new handler
    std::set_new_handler(customNewHandler);

    try {
        // Attempt to allocate an extremely large amount of memory to trigger the new handler
        std::cout << "Attempting to allocate a huge block of memory to trigger set_new_handler...\n";
        size_t size = static_cast<size_t>(-1); // Maximum possible size
        int* ptr = new int[size]; // Should invoke customNewHandler
        // If allocation succeeds, which is highly unlikely, prevent memory leak
        delete[] ptr;
    }
    catch (const std::bad_alloc& e) {
        // This catch block may not be reached if set_new_handler exits the program
        std::cout << "Caught bad_alloc exception: " << e.what() << "\n";
    }
    catch (...) {
        std::cout << "An unexpected error occurred.\n";
    }

    // Reset the new handler to default to avoid affecting other parts of the program
    std::set_new_handler(nullptr);
}