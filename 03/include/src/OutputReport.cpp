#include "OutputReport.h"
#include <iostream>
using namespace std;
#include <vector>
// #06 Function - void outputReport()
// Output a report which lists:
//   All customers with all member data
//   All orders with all member data
//   All products with all member data
void outputReport(const std::vector<Customer> &customers,
                  const std::vector<Order> &orders,
                  const std::vector<Product> &products) {
    std::cout << "\n=== OUTPUT REPORT ===\n\n";
    cout << "\n=== OUTPUT REPORT ===\n\n";

    cout << "All Customers:\n";
    for (const auto &cust : customers) {
        cout << "  Customer ID: " << cust.getCustID() << "\n"
             << "  Name: " << cust.getName() << "\n"
             << "  Address: " << cust.getAddress() << "\n"
             << "  Creation Time: " << cust.getCustomerCreationTime() << "\n"
             << "  Order Numbers: ";
        for (int ordNum : cust.getOrderNums()) {
            cout << ordNum << " ";
        }
        cout << "\n\n";
    }

    cout << "All Orders:\n";
    for (const auto &ord : orders) {
        cout << "  Order Number: " << ord.getOrderNum() << "\n"
             << "  Customer ID: " << ord.getCustID() << "\n"
             << "  Creation Time: " << ord.getOrderCreationTime() << "\n"
             << "  Product Numbers: ";
        for (int pNum : ord.getProductNums()) {
            cout << pNum << " ";
        }
        cout << "\n\n";
    }

    cout << "All Products:\n";
    for (const auto &prod : products) {
        cout << "  Product Number: " << prod.getProductNum() << "\n"
             << "  Product Name: " << prod.getProductName() << "\n"
             << "  Product Description: " << prod.getProductDescription() << "\n"
             << "  Creation Time: " << prod.getProductCreationTime() << "\n\n";
    }
}
