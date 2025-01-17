#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string productID;
    std::string description;
    double price;

public:
    Product() : price(0.0) {}
    Product(const std::string &pid, const std::string &desc, double p)
        : productID(pid), description(desc), price(p) {}

    // Getters
    std::string getProductID()   const { return productID; }
    std::string getDescription() const { return description; }
    double getPrice()            const { return price; }

    // Setters
    void setProductID(const std::string &pid)   { productID = pid; }
    void setDescription(const std::string &desc){ description = desc; }
    void setPrice(double p)                     { price = p; }
};

#endif