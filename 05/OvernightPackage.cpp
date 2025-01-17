#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(const std::string& sName, const std::string& sAddr,
                                   const std::string& sCity, const std::string& sSt,
                                   const std::string& sZip, const std::string& rName,
                                   const std::string& rAddr, const std::string& rCity,
                                   const std::string& rSt, const std::string& rZip,
                                   double w, double cost, double rate)
    : Package(sName, sAddr, sCity, sSt, sZip,
              rName, rAddr, rCity, rSt, rZip, w, cost),
      overnightRate(rate) {}

void OvernightPackage::setOvernightRate(double rate) {
    overnightRate = (rate > 0) ? rate : 0.0;
}

double OvernightPackage::calculateCost() const {
    // Additional cost per ounce
    return Package::calculateCost() + (getWeight() * overnightRate);
}