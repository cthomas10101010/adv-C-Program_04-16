#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(const std::string& sName, const std::string& sAddr,
                             const std::string& sCity, const std::string& sSt,
                             const std::string& sZip, const std::string& rName,
                             const std::string& rAddr, const std::string& rCity,
                             const std::string& rSt, const std::string& rZip,
                             double w, double cost, double fee)
    : Package(sName, sAddr, sCity, sSt, sZip,
              rName, rAddr, rCity, rSt, rZip, w, cost) {
    setTwoDayFee(fee);
}

void TwoDayPackage::setTwoDayFee(double fee) {
    twoDayFee = (fee > 0) ? fee : 0.0;
}

double TwoDayPackage::calculateCost() const {
    // Base cost + fixed twoDayFee
    return Package::calculateCost() + twoDayFee;
}