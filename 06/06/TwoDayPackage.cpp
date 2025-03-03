#include "TwoDayPackage.h"
#include <iostream>
#include <stdexcept>

// Constructor
TwoDayPackage::TwoDayPackage(const std::string& sName, const std::string& sAddress, 
                             const std::string& sCity, const std::string& sState, const std::string& sZip,
                             const std::string& rName, const std::string& rAddress, 
                             const std::string& rCity, const std::string& rState, const std::string& rZip,
                             double wgt, double cost, double fee)
    : Package(sName, sAddress, sCity, sState, sZip,
              rName, rAddress, rCity, rState, rZip, wgt, cost) {
    
    // Validate two-day fee
    if (fee < 0) {
        throw std::invalid_argument("Two-day fee cannot be negative");
    }
    twoDayFee = fee;
}

// Setter for twoDayFee
void TwoDayPackage::setTwoDayFee(double fee) {
    if (fee < 0) {
        throw std::invalid_argument("Two-day fee cannot be negative");
    }
    twoDayFee = fee;
}

// Getter for twoDayFee
double TwoDayPackage::getTwoDayFee() const {
    return twoDayFee;
}

// Override calculateCost to include flat fee
double TwoDayPackage::calculateCost() const {
    // Calculate base cost and add flat fee
    return Package::calculateCost() + twoDayFee;
}

// Override displayInfo to show two-day specific details
void TwoDayPackage::displayInfo() const {
    std::cout << "Two-Day Package Information:\n";
    std::cout << "  Sender: " << getSenderName() << "\n";
    std::cout << "  Address: " << getSenderAddress() << ", " << getSenderCity() << ", " 
              << getSenderState() << ", " << getSenderZip() << "\n";
    std::cout << "  Receiver: " << getReceiverName() << "\n";
    std::cout << "  Address: " << getReceiverAddress() << ", " << getReceiverCity() << ", " 
              << getReceiverState() << ", " << getReceiverZip() << "\n";
    std::cout << "  Weight: " << getWeight() << " oz\n";
    std::cout << "  Cost per ounce: $" << getCostPerOunce() << "\n";
    std::cout << "  Two-day flat fee: $" << twoDayFee << "\n";
    std::cout << "  Total cost: $" << calculateCost() << "\n";
}