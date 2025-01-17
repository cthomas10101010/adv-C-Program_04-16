#include "Customer.h"

// Initialize static data member (must happen outside the class)
int Customer::customerCount = 0;

// Default constructor
Customer::Customer()
    : custID(0), name(""), address(""), customerCreationTime("")
{
    ++customerCount;
}

// Overloaded constructor
Customer::Customer(int id, const std::string &nm,
                   const std::string &addr, const std::string &cTime)
    : custID(id), name(nm), address(addr), customerCreationTime(cTime)
{
    ++customerCount;
}

// Setters
void Customer::setCustID(int id) {
    custID = id;
}

void Customer::setName(const std::string &nm) {
    name = nm;
}

void Customer::setAddress(const std::string &addr) {
    address = addr;
}

void Customer::setCustomerCreationTime(const std::string &time) {
    customerCreationTime = time;
}

void Customer::addOrderNum(int orderNum) {
    orderNums.push_back(orderNum);
}

// Getters
int Customer::getCustID() const {
    return custID;
}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getAddress() const {
    return address;
}

std::string Customer::getCustomerCreationTime() const {
    return customerCreationTime;
}

const std::vector<int>& Customer::getOrderNums() const {
    return orderNums;
}

// Return how many Customer objects have been created
int Customer::getCustomerCount() {
    return customerCount;
}
