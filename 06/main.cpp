#include <iostream>
#include <vector>  // for std::vector
#include <limits>
#include <iomanip> // for std::setprecision
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

int main() {
    std::cout << "Program 06: Demonstrating Polymorphism with Packages\n\n";

    // Create a vector of Package pointers
    std::vector<Package*> packages;

    try {
        // Get common sender info
        std::cout << "Enter Sender Information (this will be used for all packages):\n";
        std::cout << "Name: ";
        std::string sName;
        std::cin >> sName;
        
        std::cout << "Address: ";
        std::string sAddr;
        std::cin >> sAddr;
        
        std::cout << "City: ";
        std::string sCity;
        std::cin >> sCity;
        
        std::cout << "State: ";
        std::string sState;
        std::cin >> sState;
        
        std::cout << "Zip: ";
        std::string sZip;
        std::cin >> sZip;
        
        // Process standard package
        std::cout << "\n--- STANDARD PACKAGE ---\n";
        std::cout << "Enter Receiver Information:\n";
        
        std::cout << "Name: ";
        std::string rName;
        std::cin >> rName;
        
        std::cout << "Address: ";
        std::string rAddr;
        std::cin >> rAddr;
        
        std::cout << "City: ";
        std::string rCity;
        std::cin >> rCity;
        
        std::cout << "State: ";
        std::string rState;
        std::cin >> rState;
        
        std::cout << "Zip: ";
        std::string rZip;
        std::cin >> rZip;
        
        std::cout << "Weight (oz): ";
        double weight;
        std::cin >> weight;
        
        std::cout << "Cost per ounce ($): ";
        double costPerOunce;
        std::cin >> costPerOunce;
        
        // Create standard package and add to vector
        packages.push_back(new Package(sName, sAddr, sCity, sState, sZip, 
                                      rName, rAddr, rCity, rState, rZip,
                                      weight, costPerOunce));
                                      
        // Process Two-Day Package
        std::cout << "\n--- TWO-DAY PACKAGE ---\n";
        std::cout << "Enter Receiver Information:\n";
        
        std::cout << "Name: ";
        std::cin >> rName;
        
        std::cout << "Address: ";
        std::cin >> rAddr;
        
        std::cout << "City: ";
        std::cin >> rCity;
        
        std::cout << "State: ";
        std::cin >> rState;
        
        std::cout << "Zip: ";
        std::cin >> rZip;
        
        std::cout << "Weight (oz): ";
        std::cin >> weight;
        
        std::cout << "Cost per ounce ($): ";
        std::cin >> costPerOunce;
        
        std::cout << "Flat fee for two-day delivery ($): ";
        double twoDayFee;
        std::cin >> twoDayFee;
        
        // Create two-day package and add to vector
        packages.push_back(new TwoDayPackage(sName, sAddr, sCity, sState, sZip,
                                            rName, rAddr, rCity, rState, rZip,
                                            weight, costPerOunce, twoDayFee));
                                            
        // Process Overnight Package
        std::cout << "\n--- OVERNIGHT PACKAGE ---\n";
        std::cout << "Enter Receiver Information:\n";
        
        std::cout << "Name: ";
        std::cin >> rName;
        
        std::cout << "Address: ";
        std::cin >> rAddr;
        
        std::cout << "City: ";
        std::cin >> rCity;
        
        std::cout << "State: ";
        std::cin >> rState;
        
        std::cout << "Zip: ";
        std::cin >> rZip;
        
        std::cout << "Weight (oz): ";
        std::cin >> weight;
        
        std::cout << "Cost per ounce ($): ";
        std::cin >> costPerOunce;
        
        std::cout << "Additional cost per ounce for overnight delivery ($): ";
        double overnightRate;
        std::cin >> overnightRate;
        
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