#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package {
private:
    // Sender information
    std::string senderName;
    std::string senderAddress;
    std::string senderCity;
    std::string senderState;
    std::string senderZip;
    
    // Receiver information
    std::string receiverName;
    std::string receiverAddress;
    std::string receiverCity;
    std::string receiverState;
    std::string receiverZip;
    
    double weight; // in ounces
    double costPerOunce;

public:
    // Constructor
    Package(const std::string& sName, const std::string& sAddress, 
            const std::string& sCity, const std::string& sState, const std::string& sZip,
            const std::string& rName, const std::string& rAddress, 
            const std::string& rCity, const std::string& rState, const std::string& rZip,
            double wgt, double cost);
    
    // Setter functions
    void setSenderName(const std::string& name);
    void setSenderAddress(const std::string& address);
    void setSenderCity(const std::string& city);
    void setSenderState(const std::string& state);
    void setSenderZip(const std::string& zip);
    
    void setReceiverName(const std::string& name);
    void setReceiverAddress(const std::string& address);
    void setReceiverCity(const std::string& city);
    void setReceiverState(const std::string& state);
    void setReceiverZip(const std::string& zip);
    
    void setWeight(double wgt);
    void setCostPerOunce(double cost);
    
    // Getter functions
    std::string getSenderName() const;
    std::string getSenderAddress() const;
    std::string getSenderCity() const;
    std::string getSenderState() const;
    std::string getSenderZip() const;
    
    std::string getReceiverName() const;
    std::string getReceiverAddress() const;
    std::string getReceiverCity() const;
    std::string getReceiverState() const;
    std::string getReceiverZip() const;
    
    double getWeight() const;
    double getCostPerOunce() const;
    
    // Calculate shipping cost - virtual for polymorphism
    virtual double calculateCost() const;
    
    // Display package info
    virtual void displayInfo() const;
};

#endif