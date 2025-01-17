#include "Package.h"

Package::Package(const std::string& sName, const std::string& sAddr,
                 const std::string& sCity, const std::string& sSt,
                 const std::string& sZip, const std::string& rName,
                 const std::string& rAddr, const std::string& rCity,
                 const std::string& rSt, const std::string& rZip,
                 double w, double cost)
    : senderName(sName), senderAddress(sAddr), senderCity(sCity),
      senderState(sSt), senderZip(sZip), receiverName(rName),
      receiverAddress(rAddr), receiverCity(rCity), receiverState(rSt),
      receiverZip(rZip), weight(w), costPerOunce(cost) {}

void Package::setWeight(double w) {
    if (w > 0) {
        weight = w;
    } else {
        weight = 0.0;
    }
}

void Package::setCostPerOunce(double cost) {
    if (cost > 0) {
        costPerOunce = cost;
    } else {
        costPerOunce = 0.0;
    }
}

double Package::calculateCost() const {
    return weight * costPerOunce;
}