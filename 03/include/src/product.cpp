#include "Product.h"

// Initialize static data member
int Product::productCount = 0;

// Default constructor
Product::Product()
    : productNum(0), productName(""), productDescription(""), productCreationTime("")
{
    ++productCount;
}

// Overloaded constructor
Product::Product(int pNum, const std::string &pName,
                 const std::string &pDesc, const std::string &cTime)
    : productNum(pNum), productName(pName),
      productDescription(pDesc), productCreationTime(cTime)
{
    ++productCount;
}

// Setters
void Product::setProductNum(int pNum) {
    productNum = pNum;
}

void Product::setProductName(const std::string &pName) {
    productName = pName;
}

void Product::setProductDescription(const std::string &pDesc) {
    productDescription = pDesc;
}

void Product::setProductCreationTime(const std::string &time) {
    productCreationTime = time;
}

// Getters
int Product::getProductNum() const {
    return productNum;
}

std::string Product::getProductName() const {
    return productName;
}

std::string Product::getProductDescription() const {
    return productDescription;
}

std::string Product::getProductCreationTime() const {
    return productCreationTime;
}

int Product::getProductCount() {
    return productCount;
}
