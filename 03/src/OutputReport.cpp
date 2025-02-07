#include "OutputReport.h"
#include <iostream>

void outputReport(const std::vector<Customer>& customers,
                  const std::vector<Order>& orders,
                  const std::vector<Product>& products) {
    std::cout << "\n=== Customers ===\n";
    for (const auto& customer : customers) {
        std::cout << "Customer ID: " << customer.getCustID() << "\n"
                  << "Name: " << customer.getName() << "\n"
                  << "Address: " << customer.getAddress() << "\n"
                  << "Creation Time: " << customer.getCustomerCreationTime() << "\n"
                  << "Order Numbers: ";
        for (const auto& orderNum : customer.getOrderNums()) {
            std::cout << orderNum << " ";
        }
        std::cout << "\n\n";
    }

    std::cout << "\n=== Orders ===\n";
    for (const auto& order : orders) {
        std::cout << "Order Number: " << order.getOrderNum() << "\n"
                  << "Customer ID: " << order.getCustID() << "\n"
                  << "Creation Time: " << order.getOrderCreationTime() << "\n"
                  << "Product Numbers: ";
        for (const auto& productNum : order.getProductNums()) {
            std::cout << productNum << " ";
        }
        std::cout << "\n\n";
    }

    std::cout << "\n=== Products ===\n";
    for (const auto& product : products) {
        std::cout << "Product Number: " << product.getProductNum() << "\n"
                  << "Name: " << product.getProductName() << "\n"
                  << "Description: " << product.getProductDescription() << "\n"
                  << "Creation Time: " << product.getProductCreationTime() << "\n\n";
    }
}