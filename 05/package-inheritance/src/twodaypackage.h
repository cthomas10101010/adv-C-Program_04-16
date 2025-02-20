#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "package.h"

class TwoDayPackage : public Package {
private:
    double twoDayFee;

public:
    TwoDayPackage(const std::string &senderName, const std::string &senderAddress,
                  const std::string &receiverName, const std::string &receiverAddress,
                  double weight, double costPerOunce, double fee);

    void setTwoDayFee(double fee);
    double getTwoDayFee() const;

    double calculateCost() const override;
};

#endif // TWODAYPACKAGE_H