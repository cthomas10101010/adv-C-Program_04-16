#include "twodaypackage.h"

// Constructor
TwoDayPackage::TwoDayPackage(const std::string& senderName, const std::string& senderAddress,
                             const std::string& senderCity, const std::string& senderState,
                             const std::string& senderZip, const std::string& receiverName,
                             const std::string& receiverAddress, const std::string& receiverCity,
                             const std::string& receiverState, const std::string& receiverZip,
                             double weight, double costPerOunce, double twoDayFee)
    : Package(senderName, senderAddress, senderCity, senderState, senderZip,
              receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
              weight, costPerOunce), twoDayFee(twoDayFee) {}

// Setter for twoDayFee
void TwoDayPackage::setTwoDayFee(double fee) {
    twoDayFee = fee;
}

// Getter for twoDayFee
double TwoDayPackage::getTwoDayFee() const {
    return twoDayFee;
}

// Overridden calculateCost function
double TwoDayPackage::calculateCost() const {
    return Package::calculateCost() + twoDayFee;
}