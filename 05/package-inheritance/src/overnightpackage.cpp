#include "overnightpackage.h"

// Constructor for OvernightPackage
OvernightPackage::OvernightPackage(const std::string& senderName, const std::string& senderAddress,
                                   const std::string& receiverName, const std::string& receiverAddress,
                                   double weight, double costPerOunce, double overnightRate)
    : Package(senderName, senderAddress, receiverName, receiverAddress, weight, costPerOunce),
      overnightRate(overnightRate) {}

// Setter for overnightRate
void OvernightPackage::setOvernightRate(double rate) {
    overnightRate = rate;
}

// Getter for overnightRate
double OvernightPackage::getOvernightRate() const {
    return overnightRate;
}

// Overridden calculateCost function
double OvernightPackage::calculateCost() const {
    return Package::calculateCost() + overnightRate;
}