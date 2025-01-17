#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

class Order {
private:
    int orderNum;
    int custID;                   // which customer does this order belong to?
    std::vector<int> productNums; // product numbers in this order
    std::string orderCreationTime;
    static int orderCount;        // shared among all Order objects

public:
    // Constructors
    Order();
    Order(int ordNum, int cID, const std::string &cTime);

    // Setters
    void setOrderNum(int ordNum);
    void setCustID(int cID);
    void setOrderCreationTime(const std::string &time);

    // Adds a product number to this order
    void addProductNum(int prodNum);

    // Getters
    int getOrderNum() const;
    int getCustID() const;
    std::string getOrderCreationTime() const;
    const std::vector<int>& getProductNums() const;

    // Static function to get how many Order objects have been created
    static int getOrderCount();
};

#endif
