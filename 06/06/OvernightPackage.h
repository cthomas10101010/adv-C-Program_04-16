#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package {
private:
    double overnightRate; // additional cost per ounce for overnight shipping

public:
    // Constructor
    OvernightPackage(const std::string& sName, const std::string& sAddress, 
                    const std::string& sCity, const std::string& sState, const std::string& sZip,
                    const std::string& rName, const std::string& rAddress, 
                    const std::string& rCity, const std::string& rState, const std::string& rZip,
                    double wgt, double cost, double oRate);
                 
    // Setter and getter for overnightRate
    void setOvernightRate(double rate);
    double getOvernightRate() const;
    
    // Override calculateCost() to include overnightRate
    virtual double calculateCost() const override;
    
    // Override displayInfo to show overnight specific info
    virtual void displayInfo() const override;
};

#endif