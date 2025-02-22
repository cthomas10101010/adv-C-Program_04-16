#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "package.h"

class OvernightPackage : public Package {
private:
    double overnightRate; // Additional cost per ounce for overnight shipping

public:
    // Constructor
    OvernightPackage(const std::string& senderName, const std::string& senderAddress,
                     const std::string& senderCity, const std::string& senderState,
                     const std::string& senderZip, const std::string& receiverName,
                     const std::string& receiverAddress, const std::string& receiverCity,
                     const std::string& receiverState, const std::string& receiverZip,
                     double weight, double costPerOunce, double overnightRate);

    // Setter and getter for overnightRate
    void setOvernightRate(double rate);
    double getOvernightRate() const;

    // Override calculateCost to include overnightRate
    double calculateCost() const override;
};

#endif // OVERNIGHTPACKAGE_H