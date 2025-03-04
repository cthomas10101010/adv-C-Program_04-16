#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <string>
#include "Customer.h"
#include "Product.h"
#include "Order.h"

void createSampleCustomerMasterFile(const std::string &filename) {
    // Check if file already exists
    std::ifstream checkFile(filename.c_str());
    if (checkFile) {
        // File exists, no need to create it
        checkFile.close();
        return;
    }
    
    // File doesn't exist, create it with sample data
    std::ofstream outFile(filename.c_str());
    if (!outFile) {
        std::cerr << "Unable to create " << filename << "\n";
        return;
    }
    
    // Create 100 sample customer records (as per requirement #02)
    // First 10 are detailed, rest are generated with patterns
    outFile << "C001%John%Doe%123 Main St%Austin%TX%78701\n";
    outFile << "C002%Jane%Smith%456 Elm St%Dallas%TX%75201\n";
    outFile << "C003%Robert%Johnson%789 Oak St%Houston%TX%77001\n";
    outFile << "C004%Sarah%Williams%101 Pine St%San Antonio%TX%78201\n";
    outFile << "C005%Michael%Brown%202 Maple St%Austin%TX%78702\n";
    outFile << "C006%Emily%Davis%303 Cedar St%New York%NY%10001\n";
    outFile << "C007%David%Miller%404 Birch St%Los Angeles%CA%90001\n";
    outFile << "C008%Jennifer%Wilson%505 Walnut St%Chicago%IL%60601\n";
    outFile << "C009%James%Moore%606 Cherry St%Houston%TX%77002\n";
    outFile << "C010%Lisa%Taylor%707 Spruce St%Dallas%TX%75202\n";
    
    // Generate 90 more records to meet the 100 record requirement
    std::string cities[] = {"Austin", "Dallas", "Houston", "San Antonio", "New York", 
                           "Los Angeles", "Chicago", "Phoenix", "Philadelphia", "San Diego"};
    std::string states[] = {"TX", "NY", "CA", "IL", "AZ", "PA", "FL", "OH", "MI", "GA"};
    std::string streets[] = {"Main St", "Elm St", "Oak St", "Pine St", "Maple St"};
    
    for (int i = 11; i <= 100; i++) {
        std::string custId = "C";
        if (i < 100) {
            if (i < 10) custId += "00" + std::to_string(i);
            else custId += "0" + std::to_string(i);
        } else {
            custId += std::to_string(i);
        }
        
        int cityIndex = (i % 10);
        int stateIndex = (i % 10);
        int streetIndex = (i % 5);
        int houseNum = (i * 10);
        std::string zipCode = std::to_string(70000 + i);
        
        outFile << custId << "%"
                << "FirstName" << i << "%"
                << "LastName" << i << "%"
                << houseNum << " " << streets[streetIndex] << "%"
                << cities[cityIndex] << "%"
                << states[stateIndex] << "%"
                << zipCode << "\n";
    }
    
    outFile.close();
    std::cout << "Created sample " << filename << " file with 100 records.\n";
}

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

    // First create the sample file if needed, then load the customers
    createSampleCustomerMasterFile("CustomerMaster.txt");
    
    // Now load the customer file into a vector
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
            // Ask if user wants another request with proper input validation
            char again = 'n';
            bool validInput = false;
            
            while (!validInput) {
                std::cout << "\nDo you have another request? (y/n) ";
                std::cin >> again;
                
                // Check if input is valid
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
                } else {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    again = tolower(again);
                    if (again == 'y' || again == 'n') {
                        validInput = true;
                    } else {
                        std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
                    }
                }
            }
            
            if (again == 'n') {
                done = true;
            }
        }
    }

    // Graceful exit
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
    for (size_t i = 0; i < customers.size(); ++i) {
        bool found = false;
        for (size_t j = 0; j < cities.size(); ++j) {
            if (cities[j] == customers[i].getCity()) {
                found = true;
                break;
            }
        }
        if (!found && !customers[i].getCity().empty()) {
            cities.push_back(customers[i].getCity());
        }
    }
    std::cout << "\nUnique Cities:\n";
    for (size_t i = 0; i < cities.size(); ++i) {
        std::cout << cities[i] << "\n";
    }
}

void listStates(const std::vector<Customer> &customers) {
    std::vector<std::string> states;
    for (size_t i = 0; i < customers.size(); ++i) {
        bool found = false;
        for (size_t j = 0; j < states.size(); ++j) {
            if (states[j] == customers[i].getState()) {
                found = true;
                break;
            }
        }
        if (!found && !customers[i].getState().empty()) {
            states.push_back(customers[i].getState());
        }
    }
    std::cout << "\nUnique States:\n";
    for (size_t i = 0; i < states.size(); ++i) {
        std::cout << states[i] << "\n";
    }
}

void listCustomersInCity(const std::vector<Customer> &customers, const std::string &city) {
    std::cout << "\nCustomers in city: " << city << "\n";
    bool found = false;
    for (size_t i = 0; i < customers.size(); ++i) {
        if (customers[i].getCity() == city) {
            found = true;
            std::cout << customers[i].getCustomerID() << ", "
                      << customers[i].getFirstName() << " " << customers[i].getLastName() << ", "
                      << customers[i].getStreetAddress() << ", "
                      << customers[i].getCity() << ", " << customers[i].getState() << ", " 
                      << customers[i].getZipCode() << "\n";
        }
    }
    if (!found) {
        std::cout << "No customers found in " << city << ".\n";
    }
}

void listCustomersInState(const std::vector<Customer> &customers, const std::string &state) {
    std::cout << "\nCustomers in state: " << state << "\n";
    bool found = false;
    for (size_t i = 0; i < customers.size(); ++i) {
        if (customers[i].getState() == state) {
            found = true;
            std::cout << customers[i].getCustomerID() << ", "
                      << customers[i].getFirstName() << " " << customers[i].getLastName() << ", "
                      << customers[i].getStreetAddress() << ", "
                      << customers[i].getCity() << ", " << customers[i].getState() << ", " 
                      << customers[i].getZipCode() << "\n";
        }
    }
    if (!found) {
        std::cout << "No customers found in " << state << ".\n";
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
    // Append line with '%' as separator: ProductID%Description%Price
    outFile << pid << "%" << desc << "%" << price << "\n";
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
    // Append line with '%' as separator: OrderID%CustomerID%ProductID%Quantity%OrderTotal
    outFile << oid << "%" << cid << "%" << pid << "%" << qty << "%" << total << "\n";
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
    bool found = false;
    std::string line;
    while (std::getline(inFile, line)) {
        // Format: OrderID%CustomerID%ProductID%Quantity%OrderTotal
        std::string fields[5];
        int index = 0;
        size_t start = 0;
        size_t end   = 0;
        while ((end = line.find('%', start)) != std::string::npos && index < 5) {
            fields[index++] = line.substr(start, end - start);
            start = end + 1;
        }
        if (index < 5) {
            fields[index++] = line.substr(start);
        }
        if (index == 5 && fields[1] == custID) {
            found = true;
            std::cout << "OrderID: " << fields[0] 
                      << ", ProductID: " << fields[2] 
                      << ", Quantity: " << fields[3] 
                      << ", OrderTotal: $" << fields[4] << "\n";
        }
    }
    if (!found) {
        std::cout << "No orders found for customer ID: " << custID << ".\n";
    }
    inFile.close();
}

void listOrdersByZipCode(const std::vector<Customer> &customers,
                         const std::string &ordersFile, const std::string &zip) {
    // First, find all CustomerIDs that match this zip
    std::vector<std::string> matchingCustIDs;
    for (size_t i = 0; i < customers.size(); ++i) {
        if (customers[i].getZipCode() == zip) {
            matchingCustIDs.push_back(customers[i].getCustomerID());
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
    bool found = false;
    std::string line;
    while (std::getline(inFile, line)) {
        // Format: OrderID%CustomerID%ProductID%Quantity%OrderTotal
        std::string fields[5];
        int index = 0;
        size_t start = 0;
        size_t end   = 0;
        while ((end = line.find('%', start)) != std::string::npos && index < 5) {
            fields[index++] = line.substr(start, end - start);
            start = end + 1;
        }
        if (index < 5) {
            fields[index++] = line.substr(start);
        }
        if (index == 5) {
            // fields[1] is CustomerID
            for (size_t i = 0; i < matchingCustIDs.size(); ++i) {
                if (fields[1] == matchingCustIDs[i]) {
                    found = true;
                    std::cout << "OrderID: " << fields[0] 
                              << ", CustomerID: " << fields[1] 
                              << ", ProductID: " << fields[2] 
                              << ", Quantity: " << fields[3] 
                              << ", OrderTotal: $" << fields[4] << "\n";
                    break; 
                }
            }
        }
    }
    if (!found) {
        std::cout << "No orders found for customers in ZipCode: " << zip << ".\n";
    }
    inFile.close();
}