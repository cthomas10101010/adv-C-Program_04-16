#include "Package.h"
#include <iostream>
#include <stdexcept>

// Constructor implementation with validation
Package::Package(const std::string& sName, const std::string& sAddress, 
                 const std::string& sCity, const std::string& sState, const std::string& sZip,
                 const std::string& rName, const std::string& rAddress, 
                 const std::string& rCity, const std::string& rState, const std::string& rZip,
                 double wgt, double cost) 
    : senderName(sName), senderAddress(sAddress), senderCity(sCity), 
      senderState(sState), senderZip(sZip),
      receiverName(rName), receiverAddress(rAddress), receiverCity(rCity),
      receiverState(rState), receiverZip(rZip) {
    
    // Validate weight
    if (wgt <= 0) {
        throw std::invalid_argument("Weight must be greater than 0");
    }
    weight = wgt;
    
    // Validate cost per ounce
    if (cost <= 0) {
        throw std::invalid_argument("Cost per ounce must be greater than 0");
    }
    costPerOunce = cost;
}

// Setter implementations
void Package::setSenderName(const std::string& name) {
    senderName = name;
}

void Package::setSenderAddress(const std::string& address) {
    senderAddress = address;
}

void Package::setSenderCity(const std::string& city) {
    senderCity = city;
}

void Package::setSenderState(const std::string& state) {
    senderState = state;
}

void Package::setSenderZip(const std::string& zip) {
    senderZip = zip;
}

void Package::setReceiverName(const std::string& name) {
    receiverName = name;
}

void Package::setReceiverAddress(const std::string& address) {
    receiverAddress = address;
}

void Package::setReceiverCity(const std::string& city) {
    receiverCity = city;
}

void Package::setReceiverState(const std::string& state) {
    receiverState = state;
}

void Package::setReceiverZip(const std::string& zip) {
    receiverZip = zip;
}

void Package::setWeight(double wgt) {
    if (wgt <= 0) {
        throw std::invalid_argument("Weight must be greater than 0");
    }
    weight = wgt;
}

void Package::setCostPerOunce(double cost) {
    if (cost <= 0) {
        throw std::invalid_argument("Cost per ounce must be greater than 0");
    }
    costPerOunce = cost;
}

// Getter implementations
std::string Package::getSenderName() const {
    return senderName;
}

std::string Package::getSenderAddress() const {
    return senderAddress;
}

std::string Package::getSenderCity() const {
    return senderCity;
}

std::string Package::getSenderState() const {
    return senderState;
}

std::string Package::getSenderZip() const {
    return senderZip;
}

std::string Package::getReceiverName() const {
    return receiverName;
}

std::string Package::getReceiverAddress() const {
    return receiverAddress;
}

std::string Package::getReceiverCity() const {
    return receiverCity;
}

std::string Package::getReceiverState() const {
    return receiverState;
}

std::string Package::getReceiverZip() const {
    return receiverZip;
}

double Package::getWeight() const {
    return weight;
}

double Package::getCostPerOunce() const {
    return costPerOunce;
}

// Calculate cost for standard package
double Package::calculateCost() const {
    return weight * costPerOunce;
}

// Display package info
void Package::displayInfo() const {
    std::cout << "Package Information:\n";
    std::cout << "  Sender: " << senderName << "\n";
    std::cout << "  Address: " << senderAddress << ", " << senderCity << ", " 
              << senderState << ", " << senderZip << "\n";
    std::cout << "  Receiver: " << receiverName << "\n";
    std::cout << "  Address: " << receiverAddress << ", " << receiverCity << ", " 
              << receiverState << ", " << receiverZip << "\n";
    std::cout << "  Weight: " << weight << " oz\n";
    std::cout << "  Cost per ounce: $" << costPerOunce << "\n";
    std::cout << "  Total cost: $" << calculateCost() << "\n";
}