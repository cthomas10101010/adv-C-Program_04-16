#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <string>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

// Helper function to clear input buffer
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Helper function to get string input that may contain spaces
std::string getStringInput() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

// Helper function to get positive double input
double getPositiveDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            if (value > 0) {
                clearInputBuffer(); // Clear the buffer after successful input
                return value;
            } else {
                std::cout << "Error: Value must be greater than 0. Please try again.\n";
            }
        } else {
            std::cout << "Error: Invalid input. Please enter a number.\n";
            std::cin.clear();  // Clear the error flag
            clearInputBuffer();
        }
    }
}

int main() {
    std::cout << "Program 06: Demonstrating Polymorphism with Packages\n\n";

    std::vector<Package*> packages;

    try {
        // Get common sender info
        std::cout << "Enter Sender Information (this will be used for all packages):\n";
        
        std::cout << "Name: ";
        clearInputBuffer(); // Clear any residual input
        std::string sName = getStringInput();
        
        std::cout << "Address: ";
        std::string sAddr = getStringInput();
        
        std::cout << "City: ";
        std::string sCity = getStringInput();
        
        std::cout << "State: ";
        std::string sState = getStringInput();
        
        std::cout << "Zip: ";
        std::string sZip = getStringInput();
        
        // Process standard package
        std::cout << "\n--- STANDARD PACKAGE ---\n";
        std::cout << "Enter Receiver Information:\n";
        
        std::cout << "Name: ";
        std::string rName = getStringInput();
        
        std::cout << "Address: ";
        std::string rAddr = getStringInput();
        
        std::cout << "City: ";
        std::string rCity = getStringInput();
        
        std::cout << "State: ";
        std::string rState = getStringInput();
        
        std::cout << "Zip: ";
        std::string rZip = getStringInput();
        
        double weight = getPositiveDouble("Weight (oz): ");
        double costPerOunce = getPositiveDouble("Cost per ounce ($): ");
        
        // Create standard package and add to vector
        packages.push_back(new Package(sName, sAddr, sCity, sState, sZip, 
                                      rName, rAddr, rCity, rState, rZip,
                                      weight, costPerOunce));
                                      
        // Process Two-Day Package
        std::cout << "\n--- TWO-DAY PACKAGE ---\n";
        std::cout << "Enter Receiver Information:\n";
        
        std::cout << "Name: ";
        rName = getStringInput();
        
        std::cout << "Address: ";
        rAddr = getStringInput();
        
        std::cout << "City: ";
        rCity = getStringInput();
        
        std::cout << "State: ";
        rState = getStringInput();
        
        std::cout << "Zip: ";
        rZip = getStringInput();
        
        weight = getPositiveDouble("Weight (oz): ");
        costPerOunce = getPositiveDouble("Cost per ounce ($): ");
        double twoDayFee = getPositiveDouble("Flat fee for two-day delivery ($): ");
        
        // Create two-day package and add to vector
        packages.push_back(new TwoDayPackage(sName, sAddr, sCity, sState, sZip,
                                            rName, rAddr, rCity, rState, rZip,
                                            weight, costPerOunce, twoDayFee));
                                            
        // Process Overnight Package
        std::cout << "\n--- OVERNIGHT PACKAGE ---\n";
        std::cout << "Enter Receiver Information:\n";
        
        std::cout << "Name: ";
        rName = getStringInput();
        
        std::cout << "Address: ";
        rAddr = getStringInput();
        
        std::cout << "City: ";
        rCity = getStringInput();
        
        std::cout << "State: ";
        rState = getStringInput();
        
        std::cout << "Zip: ";
        rZip = getStringInput();
        
        weight = getPositiveDouble("Weight (oz): ");
        costPerOunce = getPositiveDouble("Cost per ounce ($): ");
        double overnightRate = getPositiveDouble("Additional cost per ounce for overnight delivery ($): ");
        
        // Create overnight package and add to vector
        packages.push_back(new OvernightPackage(sName, sAddr, sCity, sState, sZip,
                                               rName, rAddr, rCity, rState, rZip,
                                               weight, costPerOunce, overnightRate));
                                               
        // Process packages polymorphically
        std::cout << "\n\n--- PROCESSING PACKAGES POLYMORPHICALLY ---\n\n";
        double totalCost = 0.0;
        
        // Iterate through packages vector to process each package polymorphically
        for (size_t i = 0; i < packages.size(); ++i) {
            // Display package information
            packages[i]->displayInfo();
            
            // Add this package's cost to the total
            totalCost += packages[i]->calculateCost();
            
            std::cout << std::endl;
        }
        
        // Display total cost of all packages
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Total cost of all packages: $" << totalCost << std::endl;
        
        // Clean up dynamically allocated memory
        for (size_t i = 0; i < packages.size(); ++i) {
            delete packages[i];
        }
    }
    catch (std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}