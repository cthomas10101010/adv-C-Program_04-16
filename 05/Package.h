#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package {
private:
    // Sender
    std::string senderName;
    std::string senderAddress;
    std::string senderCity;
    std::string senderState;
    std::string senderZip;
    // Receiver
    std::string receiverName;
    std::string receiverAddress;
    std::string receiverCity;
    std::string receiverState;
    std::string receiverZip;

    double weight;
    double costPerOunce;

public:
    Package(const std::string& sName = "", const std::string& sAddr = "",
            const std::string& sCity = "", const std::string& sSt = "",
            const std::string& sZip = "", const std::string& rName = "",
            const std::string& rAddr = "", const std::string& rCity = "",
            const std::string& rSt = "", const std::string& rZip = "",
            double w = 0.0, double cost = 0.0);

    // Setters
    void setSenderName(const std::string& name) { senderName = name; }
    void setSenderAddress(const std::string& address) { senderAddress = address; }
    void setSenderCity(const std::string& city) { senderCity = city; }
    void setSenderState(const std::string& state) { senderState = state; }
    void setSenderZip(const std::string& zip) { senderZip = zip; }

    void setReceiverName(const std::string& name) { receiverName = name; }
    void setReceiverAddress(const std::string& address) { receiverAddress = address; }
    void setReceiverCity(const std::string& city) { receiverCity = city; }
    void setReceiverState(const std::string& state) { receiverState = state; }
    void setReceiverZip(const std::string& zip) { receiverZip = zip; }

    void setWeight(double w);
    void setCostPerOunce(double cost);

    // Getters
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

    // calculateCost
    virtual double calculateCost() const;
};

#endif