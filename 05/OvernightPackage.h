#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package {
private:
    double overnightRate;
public:
    OvernightPackage(const std::string& sName = "", const std::string& sAddr = "",
                     const std::string& sCity = "", const std::string& sSt = "",
                     const std::string& sZip = "", const std::string& rName = "",
                     const std::string& rAddr = "", const std::string& rCity = "",
                     const std::string& rSt = "", const std::string& rZip = "",
                     double w = 0.0, double cost = 0.0, double rate = 0.0);

    void setOvernightRate(double rate);
    double getOvernightRate() const { return overnightRate; }

    virtual double calculateCost() const override;
};

#endif