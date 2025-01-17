#include "StructUtilities.h"
#include <iostream>
#include <cstring>
#include <limits>     // Required for std::numeric_limits
#include <algorithm>  // Included as per previous setup

void StructUtilities::handleStructures() {
    std::cout << "\n--- Structure Operations ---\n";

    Person person1;
    Person person2;

    std::cout << "Enter name for Person 1: ";
    std::cin.getline(person1.name, 50);
    std::cout << "Enter age for Person 1: ";
    std::cin >> person1.age;
    std::cout << "Enter ID for Person 1: ";
    std::cin >> person1.id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume newline

    std::cout << "Enter name for Person 2: ";
    std::cin.getline(person2.name, 50);
    std::cout << "Enter age for Person 2: ";
    std::cin >> person2.age;
    std::cout << "Enter ID for Person 2: ";
    std::cin >> person2.id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume newline

    // Display information
    std::cout << "\n--- Person 1 Details ---\n";
    std::cout << "Name: " << person1.name << "\n";
    std::cout << "Age: " << person1.age << "\n";
    std::cout << "ID: " << person1.id << "\n";

    std::cout << "\n--- Person 2 Details ---\n";
    std::cout << "Name: " << person2.name << "\n";
    std::cout << "Age: " << person2.age << "\n";
    std::cout << "ID: " << person2.id << "\n";

    // Compare Ages
    if (person1.age > person2.age)
        std::cout << "\nPerson 1 is older than Person 2.\n";
    else if (person1.age < person2.age)
        std::cout << "\nPerson 2 is older than Person 1.\n";
    else
        std::cout << "\nBoth persons are of the same age.\n";
}