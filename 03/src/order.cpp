#include "Order.h"

// Initialize static data member
int Order::orderCount = 0;

// Default constructor
Order::Order()
    : orderNum(0), custID(0), orderCreationTime("")
{
    ++orderCount;
}

// Overloaded constructor
Order::Order(int ordNum, int cID, const std::string &cTime)
    : orderNum(ordNum), custID(cID), orderCreationTime(cTime)
{
    ++orderCount;
}

// Setters
void Order::setOrderNum(int ordNum) {
    orderNum = ordNum;
}

void Order::setCustID(int cID) {
    custID = cID;
}

void Order::setOrderCreationTime(const std::string &time) {
    orderCreationTime = time;
}

void Order::addProductNum(int prodNum) {
    productNums.push_back(prodNum);
}

// Getters
int Order::getOrderNum() const {
    return orderNum;
}

int Order::getCustID() const {
    return custID;
}

std::string Order::getOrderCreationTime() const {
    return orderCreationTime;
}

const std::vector<int>& Order::getProductNums() const {
    return productNums;
}

// Return how many Order objects have been created
int Order::getOrderCount() {
    return orderCount;
}
