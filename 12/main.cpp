#include <iostream>
#include <string>
#include <limits> // Include this header for std::numeric_limits
#include "Stack.h"

int main() {
    std::cout << "Program 12: Demonstrating Custom Class Templates\n\n";

    bool exitProgram = false;
    while (!exitProgram) {
        std::cout << "\nSelect the type of stack:\n"
                  << " 1) Integer Stack\n"
                  << " 2) Double Stack\n"
                  << " 3) String Stack\n"
                  << " 4) Exit\n"
                  << "Enter your choice: ";
        int stackChoice;
        std::cin >> stackChoice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (stackChoice) {
            case 1: {
                Stack<int> intStack;
                bool exitIntStack = false;
                while (!exitIntStack) {
                    std::cout << "\nInteger Stack Operations:\n"
                              << " 1) Push\n"
                              << " 2) Pop\n"
                              << " 3) Top\n"
                              << " 4) Clear\n"
                              << " 5) Check if Empty\n"
                              << " 6) Back to Stack Type Selection\n"
                              << "Enter your choice: ";
                    int opChoice;
                    std::cin >> opChoice;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter a number between 1 and 6.\n";
                        continue;
                    }

                    try {
                        switch (opChoice) {
                            case 1: {
                                int value;
                                std::cout << "Enter integer to push: ";
                                std::cin >> value;
                                intStack.push(value);
                                std::cout << value << " pushed to stack.\n";
                                break;
                            }
                            case 2: {
                                int value = intStack.pop();
                                std::cout << value << " popped from stack.\n";
                                break;
                            }
                            case 3: {
                                int value = intStack.top();
                                std::cout << "Top element: " << value << "\n";
                                break;
                            }
                            case 4:
                                intStack.clear();
                                std::cout << "Stack cleared.\n";
                                break;
                            case 5:
                                std::cout << "Stack is " << (intStack.empty() ? "empty." : "not empty.") << "\n";
                                break;
                            case 6:
                                exitIntStack = true;
                                break;
                            default:
                                std::cout << "Invalid choice. Please select a number between 1 and 6.\n";
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
                Stack<double> doubleStack;
                bool exitDoubleStack = false;
                while (!exitDoubleStack) {
                    std::cout << "\nDouble Stack Operations:\n"
                              << " 1) Push\n"
                              << " 2) Pop\n"
                              << " 3) Top\n"
                              << " 4) Clear\n"
                              << " 5) Check if Empty\n"
                              << " 6) Back to Stack Type Selection\n"
                              << "Enter your choice: ";
                    int opChoice;
                    std::cin >> opChoice;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter a number between 1 and 6.\n";
                        continue;
                    }

                    try {
                        switch (opChoice) {
                            case 1: {
                                double value;
                                std::cout << "Enter double to push: ";
                                std::cin >> value;
                                doubleStack.push(value);
                                std::cout << value << " pushed to stack.\n";
                                break;
                            }
                            case 2: {
                                double value = doubleStack.pop();
                                std::cout << value << " popped from stack.\n";
                                break;
                            }
                            case 3: {
                                double value = doubleStack.top();
                                std::cout << "Top element: " << value << "\n";
                                break;
                            }
                            case 4:
                                doubleStack.clear();
                                std::cout << "Stack cleared.\n";
                                break;
                            case 5:
                                std::cout << "Stack is " << (doubleStack.empty() ? "empty." : "not empty.") << "\n";
                                break;
                            case 6:
                                exitDoubleStack = true;
                                break;
                            default:
                                std::cout << "Invalid choice. Please select a number between 1 and 6.\n";
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
                Stack<std::string> stringStack;
                bool exitStringStack = false;
                while (!exitStringStack) {
                    std::cout << "\nString Stack Operations:\n"
                              << " 1) Push\n"
                              << " 2) Pop\n"
                              << " 3) Top\n"
                              << " 4) Clear\n"
                              << " 5) Check if Empty\n"
                              << " 6) Back to Stack Type Selection\n"
                              << "Enter your choice: ";
                    int opChoice;
                    std::cin >> opChoice;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter a number between 1 and 6.\n";
                        continue;
                    }

                    try {
                        switch (opChoice) {
                            case 1: {
                                std::string value;
                                std::cout << "Enter string to push: ";
                                std::cin.ignore(); // To consume the leftover newline
                                std::getline(std::cin, value);
                                stringStack.push(value);
                                std::cout << "\"" << value << "\" pushed to stack.\n";
                                break;
                            }
                            case 2: {
                                std::string value = stringStack.pop();
                                std::cout << "\"" << value << "\" popped from stack.\n";
                                break;
                            }
                            case 3: {
                                std::string value = stringStack.top();
                                std::cout << "Top element: \"" << value << "\"\n";
                                break;
                            }
                            case 4:
                                stringStack.clear();
                                std::cout << "Stack cleared.\n";
                                break;
                            case 5:
                                std::cout << "Stack is " << (stringStack.empty() ? "empty." : "not empty.") << "\n";
                                break;
                            case 6:
                                exitStringStack = true;
                                break;
                            default:
                                std::cout << "Invalid choice. Please select a number between 1 and 6.\n";
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