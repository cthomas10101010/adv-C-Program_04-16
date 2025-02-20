#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "package.h"

class OvernightPackage : public Package {
private:
    double overnightRate;

public:
    OvernightPackage(const std::string &senderName, const std::string &senderAddress,
                     const std::string &receiverName, const std::string &receiverAddress,
                     double weight, double costPerOunce, double rate);

    void setOvernightRate(double rate);
    double getOvernightRate() const;

    double calculateCost() const override;
};

#endif // OVERNIGHTPACKAGE_H