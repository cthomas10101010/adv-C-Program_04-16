#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    int productNum;
    std::string productName;
    std::string productDescription;
    std::string productCreationTime;
    static int productCount; // shared among all Product objects

public:
    // Constructors
    Product();
    Product(int pNum, const std::string &pName,
            const std::string &pDesc, const std::string &cTime);

    // Setters
    void setProductNum(int pNum);
    void setProductName(const std::string &pName);
    void setProductDescription(const std::string &pDesc);
    void setProductCreationTime(const std::string &time);

    // Getters
    int getProductNum() const;
    std::string getProductName() const;
    std::string getProductDescription() const;
    std::string getProductCreationTime() const;

    // Static function to get how many Product objects have been created
    static int getProductCount();
};

#endif
