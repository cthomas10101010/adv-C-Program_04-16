#ifndef OUTPUTREPORT_H
#define OUTPUTREPORT_H

#include <vector>
#include "Customer.h"
#include "Order.h"
#include "Product.h"

// Outputs a report listing all stored objects' data
void outputReport(const std::vector<Customer> &customers, 
                  const std::vector<Order> &orders, 
                  const std::vector<Product> &products);

#endif
