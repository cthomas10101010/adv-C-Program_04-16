#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "package.h"

class TwoDayPackage : public Package {
private:
    double twoDayFee; // Additional flat rate fee for two-day shipping

public:
    // Constructor
    TwoDayPackage(const std::string& senderName, const std::string& senderAddress,
                  const std::string& senderCity, const std::string& senderState,
                  const std::string& senderZip, const std::string& receiverName,
                  const std::string& receiverAddress, const std::string& receiverCity,
                  const std::string& receiverState, const std::string& receiverZip,
                  double weight, double costPerOunce, double fee);

    // Setter and getter for twoDayFee
    void setTwoDayFee(double fee);
    double getTwoDayFee() const;

    // Override calculateCost to include twoDayFee
    double calculateCost() const override;
};

#endif // TWODAYPACKAGE_H