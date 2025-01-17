
// Demonstration of file operations. 
// "CustomerMaster.txt" is assumed to contain 100 lines of data with format: 
// CustomerID%FirstName%LastName%StreetAddress%City%State%ZipCode
// The user can also add items to "Products.txt" and "Orders.txt" as specified.

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <string>
#include "Customer.h"
#include "Product.h"
#include "Order.h"

// Prototypes
void loadCustomers(std::vector<Customer> &customers, const std::string &filename);
void listCities(const std::vector<Customer> &customers);
void listStates(const std::vector<Customer> &customers);
void listCustomersInCity(const std::vector<Customer> &customers, const std::string &city);
void listCustomersInState(const std::vector<Customer> &customers, const std::string &state);
void addProductToFile(const std::string &filename);
void addOrderToFile(const std::string &filename);
void listOrdersByCustomerID(const std::string &ordersFile, const std::string &custID);
void listOrdersByZipCode(const std::vector<Customer> &customers,
                         const std::string &ordersFile, const std::string &zip);

int main() {
    std::cout << "Program 08: Demonstrating File Operations\n\n";

    // 1) Load the CustomerMaster.txt file into a vector
    std::vector<Customer> customers;
    loadCustomers(customers, "CustomerMaster.txt");

    bool done = false;
    while (!done) {
        // Prompt for operation
        std::cout << "\nSelect an operation:\n"
                  << "1) Add product to Products.txt\n"
                  << "2) Add order to Orders.txt\n"
                  << "3) List cities in CustomerMaster\n"
                  << "4) List states in CustomerMaster\n"
                  << "5) All customer records in a city\n"
                  << "6) All customer records in a state\n"
                  << "7) All orders by CustomerID\n"
                  << "8) All orders by ZipCode\n"
                  << "9) Quit\n"
                  << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (!std::cin.fail()) {
            switch (choice) {
                case 1:
                    addProductToFile("Products.txt");
                    break;
                case 2:
                    addOrderToFile("Orders.txt");
                    break;
                case 3:
                    listCities(customers);
                    break;
                case 4:
                    listStates(customers);
                    break;
                case 5: {
                    std::cout << "Enter city: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::string city;
                    std::getline(std::cin, city);
                    listCustomersInCity(customers, city);
                    break;
                }
                case 6: {
                    std::cout << "Enter state: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::string st;
                    std::getline(std::cin, st);
                    listCustomersInState(customers, st);
                    break;
                }
                case 7: {
                    std::cout << "Enter CustomerID: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::string cid;
                    std::getline(std::cin, cid);
                    listOrdersByCustomerID("Orders.txt", cid);
                    break;
                }
                case 8: {
                    std::cout << "Enter ZipCode: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::string zip;
                    std::getline(std::cin, zip);
                    listOrdersByZipCode(customers, "Orders.txt", zip);
                    break;
                }
                case 9:
                    done = true;
                    break;
                default:
                    std::cout << "Invalid choice. Try again.\n";
                    break;
            }
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
        }

        if (!done) {
            // Ask if user wants another request
            std::cout << "\nDo you have another request? (y/n) ";
            char again;
            std::cin >> again;
            if (again != 'y' && again != 'Y') {
                done = true;
            }
        }
    }

    // Graceful exit
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    std::cout << "\n\n<ENTER> to exit: ";
    std::cin.get();

    return 0;
}

//------------------------------------------------------------------------------
// Implementation of helper functions

void loadCustomers(std::vector<Customer> &customers, const std::string &filename) {
    std::ifstream inFile(filename.c_str());
    if (!inFile) {
        std::cerr << "Unable to open " << filename << "\n";
        return;
    }
    std::string line;
    while (std::getline(inFile, line)) {
        Customer cust;
        if (cust.loadFromLine(line)) {
            customers.push_back(cust);
        }
    }
    inFile.close();
}

void listCities(const std::vector<Customer> &customers) {
    std::vector<std::string> cities;
    for (const auto &c : customers) {
        bool found = false;
        for (auto &existing : cities) {
            if (existing == c.getCity()) {
                found = true;
                break;
            }
        }
        if (!found && !c.getCity().empty()) {
            cities.push_back(c.getCity());
        }
    }
    std::cout << "\nUnique Cities:\n";
    for (auto &ct : cities) {
        std::cout << ct << "\n";
    }
}

void listStates(const std::vector<Customer> &customers) {
    std::vector<std::string> states;
    for (const auto &c : customers) {
        bool found = false;
        for (auto &existing : states) {
            if (existing == c.getState()) {
                found = true;
                break;
            }
        }
        if (!found && !c.getState().empty()) {
            states.push_back(c.getState());
        }
    }
    std::cout << "\nUnique States:\n";
    for (auto &st : states) {
        std::cout << st << "\n";
    }
}

void listCustomersInCity(const std::vector<Customer> &customers, const std::string &city) {
    std::cout << "\nCustomers in city: " << city << "\n";
    for (const auto &c : customers) {
        if (c.getCity() == city) {
            std::cout << c.getCustomerID() << ", "
                      << c.getFirstName() << " " << c.getLastName() << ", "
                      << c.getStreetAddress() << ", "
                      << c.getCity() << ", " << c.getState() << ", " << c.getZipCode()
                      << "\n";
        }
    }
}

void listCustomersInState(const std::vector<Customer> &customers, const std::string &state) {
    std::cout << "\nCustomers in state: " << state << "\n";
    for (const auto &c : customers) {
        if (c.getState() == state) {
            std::cout << c.getCustomerID() << ", "
                      << c.getFirstName() << " " << c.getLastName() << ", "
                      << c.getStreetAddress() << ", "
                      << c.getCity() << ", " << c.getState() << ", " << c.getZipCode()
                      << "\n";
        }
    }
}

void addProductToFile(const std::string &filename) {
    std::ofstream outFile(filename.c_str(), std::ios::app);
    if (!outFile) {
        std::cerr << "Unable to open " << filename << " for writing.\n";
        return;
    }
    std::string pid, desc;
    double price = 0.0;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter ProductID: ";
    std::getline(std::cin, pid);
    std::cout << "Enter Description: ";
    std::getline(std::cin, desc);
    std::cout << "Enter Price: ";
    std::cin >> price;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid price.\n";
        return;
    }
    // Append line: ProductID,Description,Price
    outFile << pid << "," << desc << "," << price << "\n";
    outFile.close();
    std::cout << "Product added.\n";
}

void addOrderToFile(const std::string &filename) {
    std::ofstream outFile(filename.c_str(), std::ios::app);
    if (!outFile) {
        std::cerr << "Unable to open " << filename << " for writing.\n";
        return;
    }
    std::string oid, cid, pid;
    int qty = 0;
    double total = 0.0;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter OrderID: ";
    std::getline(std::cin, oid);
    std::cout << "Enter CustomerID: ";
    std::getline(std::cin, cid);
    std::cout << "Enter ProductID: ";
    std::getline(std::cin, pid);
    std::cout << "Enter Quantity: ";
    std::cin >> qty;
    std::cout << "Enter OrderTotal: ";
    std::cin >> total;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid numeric input.\n";
        return;
    }
    // Append line: OrderID,CustomerID,ProductID,Quantity,OrderTotal
    outFile << oid << "," << cid << "," << pid << "," << qty << "," << total << "\n";
    outFile.close();
    std::cout << "Order added.\n";
}

void listOrdersByCustomerID(const std::string &ordersFile, const std::string &custID) {
    std::ifstream inFile(ordersFile.c_str());
    if (!inFile) {
        std::cerr << "Cannot open " << ordersFile << " for reading.\n";
        return;
    }
    std::cout << "\nOrders for CustomerID: " << custID << "\n";
    std::string line;
    while (std::getline(inFile, line)) {
        // Format: OrderID,CustomerID,ProductID,Quantity,OrderTotal
        // We'll parse by splitting at ','.
        std::string fields[5];
        int index = 0;
        size_t start = 0;
        size_t end   = 0;
        while ((end = line.find(',', start)) != std::string::npos && index < 5) {
            fields[index++] = line.substr(start, end - start);
            start = end + 1;
        }
        if (index < 5) {
            fields[index++] = line.substr(start);
        }
        if (index == 5 && fields[1] == custID) {
            std::cout << "OrderID: " << fields[0] 
                      << ", ProductID: " << fields[2] 
                      << ", Quantity: " << fields[3] 
                      << ", OrderTotal: " << fields[4] << "\n";
        }
    }
    inFile.close();
}

void listOrdersByZipCode(const std::vector<Customer> &customers,
                         const std::string &ordersFile, const std::string &zip) {
    // First, find all CustomerIDs that match this zip
    std::vector<std::string> matchingCustIDs;
    for (auto &c : customers) {
        if (c.getZipCode() == zip) {
            matchingCustIDs.push_back(c.getCustomerID());
        }
    }
    if (matchingCustIDs.empty()) {
        std::cout << "No customers found with ZipCode: " << zip << "\n";
        return;
    }
    // Now read Orders and match
    std::ifstream inFile(ordersFile.c_str());
    if (!inFile) {
        std::cerr << "Cannot open " << ordersFile << " for reading.\n";
        return;
    }
    std::cout << "\nOrders for ZipCode: " << zip << "\n";
    std::string line;
    while (std::getline(inFile, line)) {
        // Format: OrderID,CustomerID,ProductID,Quantity,OrderTotal
        std::string fields[5];
        int index = 0;
        size_t start = 0;
        size_t end   = 0;
        while ((end = line.find(',', start)) != std::string::npos && index < 5) {
            fields[index++] = line.substr(start, end - start);
            start = end + 1;
        }
        if (index < 5) {
            fields[index++] = line.substr(start);
        }
        if (index == 5) {
            // fields[1] is CustomerID
            for (auto &id : matchingCustIDs) {
                if (fields[1] == id) {
                    std::cout << "OrderID: " << fields[0] 
                              << ", CustomerID: " << fields[1] 
                              << ", ProductID: " << fields[2] 
                              << ", Quantity: " << fields[3] 
                              << ", OrderTotal: " << fields[4] << "\n";
                    break; 
                }
            }
        }
    }
    inFile.close();
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


// must adheer to sall these strict reuieerments::Requirements
// Requirements
//  #01	This program demonstrates file operations. Supply appropriate interaction (input/output) with your user. Again, provide appropriate interaction (input/output) with your user.
//  #02	Use the file CustomerMaster.txt which contains 100 records of customer data in the following format: CustotmerID, FirstName, LastName, StreetAddress, City, State, ZipCode. All fields are separated by percent signs.
//  #03	
// Create the following files to support the operations below:

// Products.txt with the following fields: ProductID, Description, Price
// Orders.txt with the following format: OrderID, CustomerID, ProductID, Quantity, OrderTotal
//  #04	
// Enable your user to perform these minimum iterated operations:

// Add products to the Products.txt file and populate all fields
// Add orders to the Orders.txt file and populate all fields
// After each selection, ask your user if s/he has another request to process.

//  #05	
// Provide the following minimum reporting capabilities as iterated choices:

// List of cities in CustomerMaster.txt
// List of states in CustomerMaster.txt
// All customer records in a city
// All cusomer records in a state
// All orders associated with a customer by CustomerID
// All orders associated with a customer by ZipCode
// After each selection, ask your user if s/he has another request to process.

//  #06	Include statements in a file named Statements.txt explaining your technical experiences with Program 08. Make this authentic (minimum of 2-3 sentences).
// 6. Complete and submit the requirements confirmation a also online main function in main.cpp, each .cpp must have a .h file, and the main.cpp must include all the .h files.