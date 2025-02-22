#include <iostream>
#include "package.h"

// Constructor to initialize member data
Package::Package(const std::string& senderName, const std::string& senderAddress,
                 const std::string& senderCity, const std::string& senderState,
                 const std::string& senderZip, const std::string& receiverName,
                 const std::string& receiverAddress, const std::string& receiverCity,
                 const std::string& receiverState, const std::string& receiverZip,
                 double weight, double costPerOunce)
    : senderName(senderName), senderAddress(senderAddress), senderCity(senderCity),
      senderState(senderState), senderZip(senderZip), receiverName(receiverName),
      receiverAddress(receiverAddress), receiverCity(receiverCity),
      receiverState(receiverState), receiverZip(receiverZip), weight(weight),
      costPerOunce(costPerOunce) {
    if (weight <= 0 || costPerOunce <= 0) {
        throw std::invalid_argument("Weight and cost per ounce must be greater than 0.");
    }
}

// Setters
void Package::setSenderName(const std::string& name) { senderName = name; }
void Package::setSenderAddress(const std::string& address) { senderAddress = address; }
void Package::setSenderCity(const std::string& city) { senderCity = city; }
void Package::setSenderState(const std::string& state) { senderState = state; }
void Package::setSenderZip(const std::string& zip) { senderZip = zip; }
void Package::setReceiverName(const std::string& name) { receiverName = name; }
void Package::setReceiverAddress(const std::string& address) { receiverAddress = address; }
void Package::setReceiverCity(const std::string& city) { receiverCity = city; }
void Package::setReceiverState(const std::string& state) { receiverState = state; }
void Package::setReceiverZip(const std::string& zip) { receiverZip = zip; }
void Package::setWeight(double w) {
    if (w <= 0) throw std::invalid_argument("Weight must be greater than 0.");
    weight = w;
}
void Package::setCostPerOunce(double cost) {
    if (cost <= 0) throw std::invalid_argument("Cost per ounce must be greater than 0.");
    costPerOunce = cost;
}

// Getters
std::string Package::getSenderName() const { return senderName; }
std::string Package::getSenderAddress() const { return senderAddress; }
std::string Package::getSenderCity() const { return senderCity; }
std::string Package::getSenderState() const { return senderState; }
std::string Package::getSenderZip() const { return senderZip; }
std::string Package::getReceiverName() const { return receiverName; }
std::string Package::getReceiverAddress() const { return receiverAddress; }
std::string Package::getReceiverCity() const { return receiverCity; }
std::string Package::getReceiverState() const { return receiverState; }
std::string Package::getReceiverZip() const { return receiverZip; }
double Package::getWeight() const { return weight; }
double Package::getCostPerOunce() const { return costPerOunce; }

// Calculate cost
double Package::calculateCost() const {
    return weight * costPerOunce;
}