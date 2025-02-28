#include "OvernightPackage.h"
#include <iostream>
#include <stdexcept>

// Constructor
OvernightPackage::OvernightPackage(const std::string& sName, const std::string& sAddress, 
                                  const std::string& sCity, const std::string& sState, const std::string& sZip,
                                  const std::string& rName, const std::string& rAddress, 
                                  const std::string& rCity, const std::string& rState, const std::string& rZip,
                                  double wgt, double cost, double oRate)
    : Package(sName, sAddress, sCity, sState, sZip,
              rName, rAddress, rCity, rState, rZip, wgt, cost) {
    
    // Validate overnight rate
    if (oRate < 0) {
        throw std::invalid_argument("Overnight rate cannot be negative");
    }
    overnightRate = oRate;
}

// Setter for overnightRate
void OvernightPackage::setOvernightRate(double rate) {
    if (rate < 0) {
        throw std::invalid_argument("Overnight rate cannot be negative");
    }
    overnightRate = rate;
}

// Getter for overnightRate
double OvernightPackage::getOvernightRate() const {
    return overnightRate;
}

// Override calculateCost to include additional per-ounce rate
double OvernightPackage::calculateCost() const {
    // Base cost per ounce + additional overnight rate per ounce
    return getWeight() * (getCostPerOunce() + overnightRate);
}

// Override displayInfo to show overnight specific details
void OvernightPackage::displayInfo() const {
    std::cout << "Overnight Package Information:\n";
    std::cout << "  Sender: " << getSenderName() << "\n";
    std::cout << "  Address: " << getSenderAddress() << ", " << getSenderCity() << ", " 
              << getSenderState() << ", " << getSenderZip() << "\n";
    std::cout << "  Receiver: " << getReceiverName() << "\n";
    std::cout << "  Address: " << getReceiverAddress() << ", " << getReceiverCity() << ", " 
              << getReceiverState() << ", " << getReceiverZip() << "\n";
    std::cout << "  Weight: " << getWeight() << " oz\n";
    std::cout << "  Base cost per ounce: $" << getCostPerOunce() << "\n";
    std::cout << "  Additional overnight cost per ounce: $" << overnightRate << "\n";
    std::cout << "  Total cost per ounce: $" << (getCostPerOunce() + overnightRate) << "\n";
    std::cout << "  Total cost: $" << calculateCost() << "\n";
}