#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

int main() {
    std::cout << "Program 05: Demonstrating Inheritance\n\n";

    // Prompt user for sender info
    std::string sName, sAddr, sCity, sSt, sZip;
    std::cout << "Enter sender information (Name Address City State Zip):\n";
    std::cin >> sName >> sAddr >> sCity >> sSt >> sZip;

    // Prompt user for receiver info
    std::string rName, rAddr, rCity, rSt, rZip;
    std::cout << "Enter receiver information (Name Address City State Zip):\n";
    std::cin >> rName >> rAddr >> rCity >> rSt >> rZip;

    // Prompt for weight and cost per ounce
    double weight, costPerOunce;
    std::cout << "Enter weight and costPerOunce (e.g. 5 0.5):\n";
    std::cin >> weight >> costPerOunce;

    // Create a base Package
    Package pkg(sName, sAddr, sCity, sSt, sZip, 
                rName, rAddr, rCity, rSt, rZip,
                weight, costPerOunce);

    std::cout << "\nBase Package cost: " << pkg.calculateCost() << "\n\n";

    // Prompt user for TwoDayPackage fee
    double twoDayFee;
    std::cout << "Enter twoDayFee (e.g. 2.0): ";
    std::cin >> twoDayFee;

    // Create and display TwoDayPackage cost
    TwoDayPackage twoDayPkg(sName, sAddr, sCity, sSt, sZip,
                            rName, rAddr, rCity, rSt, rZip,
                            weight, costPerOunce, twoDayFee);
    std::cout << "TwoDayPackage cost: " << twoDayPkg.calculateCost() << "\n\n";

    // Prompt user for OvernightPackage rate
    double overnightRate;
    std::cout << "Enter overnightRate (e.g. 0.75): ";
    std::cin >> overnightRate;

    // Create and display OvernightPackage cost
    OvernightPackage overnightPkg(sName, sAddr, sCity, sSt, sZip,
                                  rName, rAddr, rCity, rSt, rZip,
                                  weight, costPerOunce, overnightRate);
    std::cout << "OvernightPackage cost: " << overnightPkg.calculateCost() << "\n\n";

    std::cout << "End of Program 05\n";
    return 0;
}