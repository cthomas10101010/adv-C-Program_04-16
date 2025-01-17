#include <iostream>
#include <limits>
#include "ContainerDemo.h"

// This program demonstrates containers and iterators (Chapter 15). 
// 3-level menu structure.

int main() {
    std::cout << "Program 09: Demonstrating Containers and Iterators\n\n";

    bool doneLvl1 = false;
    while (!doneLvl1) {
        std::cout << "\nSelect a container category:\n"
                  << " 1) Sequence Containers\n"
                  << " 2) Ordered Associative Containers\n"
                  << " 3) Unordered Associative Containers\n"
                  << " 4) Container Adapters\n"
                  << " 5) Quit\n"
                  << "Enter your choice: ";
        int choice1;
        std::cin >> choice1;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
            continue;
        }

        if (choice1 == 5) {
            doneLvl1 = true;
            continue;
        }

        bool doneLvl2 = false;
        while (!doneLvl2) {
            // 2nd-level menu depends on choice1
            switch (choice1) {
            case 1: // Sequence
                std::cout << "\nSelect a Sequence Container:\n"
                          << " 1) array\n"
                          << " 2) deque\n"
                          << " 3) forward_list\n"
                          << " 4) list\n"
                          << " 5) vector\n"
                          << " 6) Go Back\n"
                          << "Enter your choice: ";
                break;
            case 2: // Ordered
                std::cout << "\nSelect an Ordered Associative Container:\n"
                          << " 1) set\n"
                          << " 2) multiset\n"
                          << " 3) map\n"
                          << " 4) multimap\n"
                          << " 5) Go Back\n"
                          << "Enter your choice: ";
                break;
            case 3: // Unordered
                std::cout << "\nSelect an Unordered Associative Container:\n"
                          << " 1) unordered_set\n"
                          << " 2) unordered_multiset\n"
                          << " 3) unordered_map\n"
                          << " 4) unordered_multimap\n"
                          << " 5) Go Back\n"
                          << "Enter your choice: ";
                break;
            case 4: // Adapters
                std::cout << "\nSelect a Container Adapter:\n"
                          << " 1) stack\n"
                          << " 2) queue\n"
                          << " 3) priority_queue\n"
                          << " 4) Go Back\n"
                          << "Enter your choice: ";
                break;
            default:
                std::cout << "Invalid top-level choice.\n";
                doneLvl2 = true;
                continue;
            }

            int choice2;
            std::cin >> choice2;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input.\n";
                break;
            }
            if (choice2 < 1) {
                std::cout << "Invalid choice.\n";
                break;
            }

            // 3rd-level: Actually run the container demo or go back
            if ((choice1 == 1 && choice2 == 6) ||
                (choice1 == 2 && choice2 == 5) ||
                (choice1 == 3 && choice2 == 5) ||
                (choice1 == 4 && choice2 == 4)) {
                // user wants to go back
                doneLvl2 = true;
                continue;
            }

            switch (choice1) {
            case 1: // Sequence
                switch (choice2) {
                case 1: demoArray(); break;
                case 2: demoDeque(); break;
                case 3: demoForwardList(); break;
                case 4: demoList(); break;
                case 5: demoVector(); break;
                default: std::cout << "Invalid choice.\n"; break;
                }
                break;
            case 2: // Ordered
                switch (choice2) {
                case 1: demoSet(); break;
                case 2: demoMultiset(); break;
                case 3: demoMap(); break;
                case 4: demoMultimap(); break;
                default: std::cout << "Invalid choice.\n"; break;
                }
                break;
            case 3: // Unordered
                switch (choice2) {
                case 1: demoUnorderedSet(); break;
                case 2: demoUnorderedMultiset(); break;
                case 3: demoUnorderedMap(); break;
                case 4: demoUnorderedMultimap(); break;
                default: std::cout << "Invalid choice.\n"; break;
                }
                break;
            case 4: // Adapters
                switch (choice2) {
                case 1: demoStack(); break;
                case 2: demoQueue(); break;
                case 3: demoPriorityQueue(); break;
                default: std::cout << "Invalid choice.\n"; break;
                }
                break;
            }

            // Ask if user wants to try another second-level container in the same category
            std::cout << "\nTry another container in this category? (y/n) ";
            char ans;
            std::cin >> ans;
            if (ans != 'y' && ans != 'Y') {
                doneLvl2 = true;
            }
        }

        // Ask if user wants to change top-level container category
        std::cout << "\nChange container category? (y/n) ";
        char ans2;
        std::cin >> ans2;
        if (ans2 != 'y' && ans2 != 'Y') {
            doneLvl1 = true;
        }
    }

    // Graceful exit
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    std::cout << "\n\n<ENTER> to exit: ";
    std::cin.get();

    return 0;
}