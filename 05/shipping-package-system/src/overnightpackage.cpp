#include "overnightpackage.h"

OvernightPackage::OvernightPackage(const std::string& senderName, const std::string& senderAddress, const std::string& senderCity, const std::string& senderState, const std::string& senderZip,
                                   const std::string& receiverName, const std::string& receiverAddress, const std::string& receiverCity, const std::string& receiverState, const std::string& receiverZip,
                                   double weight, double costPerOunce, double overnightRate)
    : Package(senderName, senderAddress, senderCity, senderState, senderZip, receiverName, receiverAddress, receiverCity, receiverState, receiverZip, weight, costPerOunce), 
      overnightRate(overnightRate) {
    if (overnightRate < 0) {
        this->overnightRate = 0; // Ensure overnightRate is non-negative
    }
}

void OvernightPackage::setOvernightRate(double rate) {
    if (rate >= 0) {
        overnightRate = rate;
    }
}

double OvernightPackage::getOvernightRate() const {
    return overnightRate;
}

double OvernightPackage::calculateCost() const {
    return Package::calculateCost() + (overnightRate * getWeight());
}