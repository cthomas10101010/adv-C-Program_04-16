#include "twodaypackage.h"

TwoDayPackage::TwoDayPackage(const std::string& senderName, const std::string& senderAddress, const std::string& senderCity, const std::string& senderState, const std::string& senderZip,
                             const std::string& receiverName, const std::string& receiverAddress, const std::string& receiverCity, const std::string& receiverState, const std::string& receiverZip,
                             double weight, double costPerOunce, double fee)
    : Package(senderName, senderAddress, senderCity, senderState, senderZip, receiverName, receiverAddress, receiverCity, receiverState, receiverZip, weight, costPerOunce), twoDayFee(fee) {
    if (fee < 0) {
        twoDayFee = 0; // Ensure fee is non-negative
    }
}

void TwoDayPackage::setTwoDayFee(double fee) {
    if (fee >= 0) {
        twoDayFee = fee;
    }
}

double TwoDayPackage::getTwoDayFee() const {
    return twoDayFee;
}

double TwoDayPackage::calculateCost() const {
    return Package::calculateCost() + twoDayFee; // Include two-day fee in total cost
}