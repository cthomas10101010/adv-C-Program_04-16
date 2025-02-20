#include "package.h"

// Constructor
Package::Package(const std::string& senderName, const std::string& senderAddress,
                 const std::string& receiverName, const std::string& receiverAddress,
                 double weight, double costPerOunce)
    : senderName(senderName), senderAddress(senderAddress),
      receiverName(receiverName), receiverAddress(receiverAddress),
      weight(weight), costPerOunce(costPerOunce) {}

// Setters
void Package::setSenderName(const std::string& name) {
    senderName = name;
}

void Package::setSenderAddress(const std::string& address) {
    senderAddress = address;
}

void Package::setReceiverName(const std::string& name) {
    receiverName = name;
}

void Package::setReceiverAddress(const std::string& address) {
    receiverAddress = address;
}

void Package::setWeight(double weight) {
    this->weight = weight;
}

void Package::setCostPerOunce(double cost) {
    costPerOunce = cost;
}

// Getters
std::string Package::getSenderName() const {
    return senderName;
}

std::string Package::getSenderAddress() const {
    return senderAddress;
}

std::string Package::getReceiverName() const {
    return receiverName;
}

std::string Package::getReceiverAddress() const {
    return receiverAddress;
}

double Package::getWeight() const {
    return weight;
}

double Package::getCostPerOunce() const {
    return costPerOunce;
}

// Calculate cost
double Package::calculateCost() const {
    return weight * costPerOunce;
}