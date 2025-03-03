#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package {
private:
    double twoDayFee; // additional flat rate fee

public:
    // Constructor
    TwoDayPackage(const std::string& sName, const std::string& sAddress, 
                 const std::string& sCity, const std::string& sState, const std::string& sZip,
                 const std::string& rName, const std::string& rAddress, 
                 const std::string& rCity, const std::string& rState, const std::string& rZip,
                 double wgt, double cost, double fee);
                 
    // Setter and getter for twoDayFee
    void setTwoDayFee(double fee);
    double getTwoDayFee() const;
    
    // Override calculateCost() to include twoDayFee
    virtual double calculateCost() const override;
    
    // Override displayInfo to show two-day specific info
    virtual void displayInfo() const override;
};

#endif