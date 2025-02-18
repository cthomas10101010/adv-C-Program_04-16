#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package {
private:
    std::string senderName;
    std::string senderAddress;
    std::string senderCity;
    std::string senderState;
    std::string senderZip;
    std::string receiverName;
    std::string receiverAddress;
    std::string receiverCity;
    std::string receiverState;
    std::string receiverZip;
    double weight;
    double costPerOunce;

public:
    Package(const std::string& sName, const std::string& sAddr,
            const std::string& sCity, const std::string& sSt,
            const std::string& sZip, const std::string& rName,
            const std::string& rAddr, const std::string& rCity,
            const std::string& rSt, const std::string& rZip,
            double w, double cost);

    void setWeight(double w);
    void setCostPerOunce(double cost);

    std::string getSenderName() const { return senderName; }
    std::string getSenderAddress() const { return senderAddress; }
    std::string getSenderCity() const { return senderCity; }
    std::string getSenderState() const { return senderState; }
    std::string getSenderZip() const { return senderZip; }

    std::string getReceiverName() const { return receiverName; }
    std::string getReceiverAddress() const { return receiverAddress; }
    std::string getReceiverCity() const { return receiverCity; }
    std::string getReceiverState() const { return receiverState; }
    std::string getReceiverZip() const { return receiverZip; }

    double getWeight() const { return weight; }
    double getCostPerOunce() const { return costPerOunce; }

    virtual double calculateCost() const;
};

#endif