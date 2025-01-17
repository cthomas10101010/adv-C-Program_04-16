#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package {
private:
    double twoDayFee;
public:
    TwoDayPackage(const std::string& sName = "", const std::string& sAddr = "",
                  const std::string& sCity = "", const std::string& sSt = "",
                  const std::string& sZip = "", const std::string& rName = "",
                  const std::string& rAddr = "", const std::string& rCity = "",
                  const std::string& rSt = "", const std::string& rZip = "",
                  double w = 0.0, double cost = 0.0, double fee = 0.0);

    void setTwoDayFee(double fee);
    double getTwoDayFee() const { return twoDayFee; }

    virtual double calculateCost() const override;
};

#endif