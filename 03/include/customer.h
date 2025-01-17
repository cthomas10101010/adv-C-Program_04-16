#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

class Customer {
private:
    int custID;
    std::string name;
    std::string address;
    std::vector<int> orderNums;         // vector of order numbers
    std::string customerCreationTime;   // date and time
    static int customerCount;           // shared among all Customer objects

public:
    // Constructors
    Customer();
    Customer(int id, const std::string &nm, const std::string &addr, const std::string &cTime);

    // Setters
    void setCustID(int id);
    void setName(const std::string &nm);
    void setAddress(const std::string &addr);
    void setCustomerCreationTime(const std::string &time);

    // Adds an order number to this customer's vector of orders
    void addOrderNum(int orderNum);

    // Getters
    int getCustID() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getCustomerCreationTime() const;
    const std::vector<int>& getOrderNums() const;

    // Static function to get how many Customer objects have been created
    static int getCustomerCount();
};

#endif
