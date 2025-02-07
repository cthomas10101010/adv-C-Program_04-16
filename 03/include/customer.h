#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

class Customer {
private:
    int custID;
    std::string name;
    std::string address;
    std::vector<int> orderNums;
    std::string customerCreationTime;
    static int customerCount;

public:
    Customer(int id, const std::string& n, const std::string& addr, const std::string& time);
    
    // Getters
    int getCustID() const { return custID; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::vector<int> getOrderNums() const { return orderNums; }
    std::string getCustomerCreationTime() const { return customerCreationTime; }
    static int getCustomerCount() { return customerCount; }
    
    // Setters
    void setCustID(int id) { custID = id; }
    void setName(const std::string& n) { name = n; }
    void setAddress(const std::string& addr) { address = addr; }
    void addOrderNum(int orderNum) { orderNums.push_back(orderNum); }
};

#endif