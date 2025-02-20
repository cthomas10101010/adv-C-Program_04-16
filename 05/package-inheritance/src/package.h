#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package {
private:
    std::string senderName;
    std::string senderAddress;
    std::string receiverName;
    std::string receiverAddress;
    double weight;
    double costPerOunce;

public:
    Package(const std::string& senderName, const std::string& senderAddress,
            const std::string& receiverName, const std::string& receiverAddress,
            double weight, double costPerOunce);

    void setSenderName(const std::string& name);
    void setSenderAddress(const std::string& address);
    void setReceiverName(const std::string& name);
    void setReceiverAddress(const std::string& address);
    void setWeight(double weight);
    void setCostPerOunce(double cost);

    std::string getSenderName() const;
    std::string getSenderAddress() const;
    std::string getReceiverName() const;
    std::string getReceiverAddress() const;
    double getWeight() const;
    double getCostPerOunce() const;

    virtual double calculateCost() const;
};

#endif // PACKAGE_H