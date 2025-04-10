/*
Program: ITSE2331 - Program 12 - Chapter 18 Templates
Description: This program demonstrates custom class and function templates.
It implements a custom Stack class template that uses a vector for storage.
The user can choose to work with a stack of integer, double, or string.
Stack member functions include push, pop, top, clear, and empty.
Exception handling is used to catch errors when performing operations on an empty stack.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <type_traits> // For std::is_same

using namespace std;

// Custom Class Stack Template using a vector for elements.
template <class T>
class Stack {
private:
    vector<T> elements;  // Data representation: Stack storage using vector.
public:
    // Adds an element to the top of the stack.
    void push(const T &element) {
        elements.push_back(element);
    }

    // Removes and returns the element from the top of the stack.
    // Throws an exception if the stack is empty.
    T pop() {
        if (elements.empty()) {
            throw runtime_error("Stack is empty! Cannot pop.");
        }
        T topElement = elements.back();
        elements.pop_back();
        return topElement;
    }

    // Returns (but does not remove) the element from the top of the stack.
    // Throws an exception if the stack is empty.
    T top() const {
        if (elements.empty()) {
            throw runtime_error("Stack is empty! Cannot retrieve top element.");
        }
        return elements.back();
    }

    // Removes all elements from the stack.
    void clear() {
        elements.clear();
    }

    // Returns true if the stack is empty; otherwise, false.
    bool empty() const {
        return elements.empty();
    }
};

// Displays the available stack operations.
void displayMenu() {
    cout << "\nPlease select a stack operation:\n"
         << "1. Push element\n"
         << "2. Pop element\n"
         << "3. Retrieve top element\n"
         << "4. Clear stack\n"
         << "5. Check if stack is empty\n"
         << "6. Exit\n"
         << "Enter your choice: ";
}

// Template function that performs stack operations interactively.
template <typename T>
void stackOperations() {
    Stack<T> stack;
    int choice;
    T element;
    bool exit = false;

    while (!exit) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: // Push element
                cout << "Enter element to push: ";
                if constexpr (is_same<T, string>::value) {
                    cin.ignore(); // Clear newline character for getline
                    getline(cin, element);
                } else {
                    cin >> element;
                }
                stack.push(element);
                cout << "Element pushed.\n";
                break;
            case 2: // Pop element
                try {
                    element = stack.pop();
                    cout << "Popped element: " << element << "\n";
                } catch (runtime_error &ex) {
                    cout << "Exception: " << ex.what() << "\n";
                }
                break;
            case 3: // Retrieve top element
                try {
                    element = stack.top();
                    cout << "Top element: " << element << "\n";
                } catch (runtime_error &ex) {
                    cout << "Exception: " << ex.what() << "\n";
                }
                break;
            case 4: // Clear stack
                stack.clear();
                cout << "Stack cleared.\n";
                break;
            case 5: // Check if stack is empty
                cout << "Stack is " << (stack.empty() ? "empty" : "not empty") << ".\n";
                break;
            case 6: // Exit
                exit = true;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

// Main function: prompts the user to select the type of stack and then enters the operations loop.
int main() {
    int typeChoice;
    cout << "Select the type of stack:\n"
         << "1. Integer\n"
         << "2. Double\n"
         << "3. String\n"
         << "Enter your choice: ";
    cin >> typeChoice;

    // Direct the program flow based on the user-selected type.
    switch (typeChoice) {
        case 1:
            cout << "You selected Integer stack.\n";
            stackOperations<int>();
            break;
        case 2:
            cout << "You selected Double stack.\n";
            stackOperations<double>();
            break;
        case 3:
            cout << "You selected String stack.\n";
            stackOperations<string>();
            break;
        default:
            cout << "Invalid choice. Exiting program.\n";
    }
    return 0;
}
