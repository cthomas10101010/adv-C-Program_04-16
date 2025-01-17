// filepath: /c:/Users/johnj/adv-C-Program_04-16/06/main.cpp
#include <iostream>
#include <vector>  // for std::vector
#include <limits>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

int main() {
    std::cout << "Program 06: Demonstrating Polymorphism with Packages\n\n";

    // Create a vector of Package pointers
    std::vector<Package*> packages;

    // Prompt user for base Package info
    std::cout << "Enter Base Package info:\n";
    std::cout << "Sender (Name Address City State Zip): ";
    std::string sName, sAddr, sCity, sState, sZip;
    std::cin >> sName >> sAddr >> sCity >> sState >> sZip;

    std::cout << "Receiver (Name Address City State Zip): ";
    std::string rName, rAddr, rCity, rState, rZip;
    std::cin >> rName >> rAddr >> rCity >> rState >> rZip;

    std::cout << "Weight and costPerOunce (e.g. 5 0.5): ";
    double weight, costPerOunce;
    std::cin >> weight >> costPerOunce;

    // Dynamically create a base Package
    Package* basePkg = new Package(sName, sAddr, sCity, sState, sZip,
                                   rName, rAddr, rCity, rState, rZip,
                                   weight, costPerOunce);
    packages.push_back(basePkg);

    // Prompt user for TwoDayPackage info
    std::cout << "\nEnter TwoDayPackage additional fee: ";
    double twoDayFee;
    std::cin >> twoDayFee;
    // Create a TwoDayPackage using the same addresses
    Package* twoDay = new TwoDayPackage(sName, sAddr, sCity, sState, sZip,
                                        rName, rAddr, rCity, rState, rZip,
                                        weight, costPerOunce, twoDayFee);
    packages.push_back(twoDay);

    // Prompt user for OvernightPackage info
    std::cout << "\nEnter OvernightPackage rate (e.g. 0.75): ";
    double overnightRate;
    std::cin >> overnightRate;
    // Create an OvernightPackage using the same addresses
    Package* overnight = new OvernightPackage(sName, sAddr, sCity, sState, sZip,
                                              rName, rAddr, rCity, rState, rZip,
                                              weight, costPerOunce, overnightRate);
    packages.push_back(overnight);

    // Now iterate through the vector polymorphically
    double totalCost = 0.0;
    std::cout << "\nPackage Details and Costs:\n";
    for (Package* pkg : packages) {
        std::cout << "Sender:   " << pkg->getSenderName()   << ", "
                  << pkg->getSenderAddress() << ", "
                  << pkg->getSenderCity()    << ", "
                  << pkg->getSenderState()   << ", "
                  << pkg->getSenderZip()     << "\n";

        std::cout << "Receiver: " << pkg->getReceiverName() << ", "
                  << pkg->getReceiverAddress() << ", "
                  << pkg->getReceiverCity()    << ", "
                  << pkg->getReceiverState()   << ", "
                  << pkg->getReceiverZip()     << "\n";

        double cost = pkg->calculateCost();
        std::cout << "Cost: $" << cost << "\n\n";
        totalCost += cost;
    }

    std::cout << "Total Cost of All Packages: $" << totalCost << "\n";

    // Clean up
    for (Package* pkg : packages) {
        delete pkg;
    }
    packages.clear();

    std::cout << "\nEnd of Program 06\n";
    return 0;
}