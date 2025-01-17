#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order {
private:
    std::string orderID;
    std::string customerID;
    std::string productID;
    int quantity;
    double orderTotal;

public:
    Order() : quantity(0), orderTotal(0.0) {}
    Order(const std::string &oid, const std::string &cid, const std::string &pid,
          int qty, double total)
        : orderID(oid), customerID(cid), productID(pid), quantity(qty), orderTotal(total) {}

    // Getters
    std::string getOrderID()    const { return orderID; }
    std::string getCustomerID() const { return customerID; }
    std::string getProductID()  const { return productID; }
    int getQuantity()           const { return quantity; }
    double getOrderTotal()      const { return orderTotal; }

    // Setters
    void setOrderID(const std::string &oid)       { orderID = oid; }
    void setCustomerID(const std::string &cid)    { customerID = cid; }
    void setProductID(const std::string &pid)     { productID = pid; }
    void setQuantity(int qty)                     { quantity = qty; }
    void setOrderTotal(double total)              { orderTotal = total; }
};

#endif