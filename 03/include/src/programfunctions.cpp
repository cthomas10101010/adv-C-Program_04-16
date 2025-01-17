#include "ProgramFunctions.h"
#include <iostream>
#include <vector>
#include <stdexcept>    // for std::runtime_error, etc.

#include "Customer.h"
#include "Order.h"
#include "Product.h"
#include "TimeFunctions.h"
#include "OutputReport.h"

void runProgram()
{
    std::vector<Customer> customers;
    std::vector<Order> orders;
    std::vector<Product> products;

    bool done = false;
    while(!done)
    {
        std::cout << "\n=== Simple Product Ordering System ===\n";
        std::cout << "1) Create New Customer\n";
        std::cout << "2) Create New Order\n";
        std::cout << "3) Create New Product\n";
        std::cout << "4) Output Report\n";
        std::cout << "5) Quit\n";
        std::cout << "Enter choice: ";
        
        int choice;
        std::cin >> choice;
        
        switch(choice)
        {
        case 1:
        {
            // Create new Customer
            try
            {
                int cID;
                std::string cName, cAddress;
                std::string cTime;
                getTime(cTime); // get the current time

                std::cout << "Enter Customer ID: ";
                std::cin >> cID;
                if(cID < 0)
                {
                    // Basic demonstration of exception
                    throw std::runtime_error("Customer ID cannot be negative.");
                }

                std::cin.ignore(); // flush newline
                std::cout << "Enter Customer Name: ";
                std::getline(std::cin, cName);

                std::cout << "Enter Customer Address: ";
                std::getline(std::cin, cAddress);

                Customer newCust(cID, cName, cAddress, cTime);
                customers.push_back(newCust);
                std::cout << "Customer created successfully!\n";
            }
            catch(const std::exception &ex)
            {
                std::cerr << "Error: " << ex.what() << "\n";
            }
            break;
        }
        case 2:
        {
            // Create new Order
            try
            {
                int oNum, cID;
                std::string oTime;
                getTime(oTime);

                std::cout << "Enter Order Number: ";
                std::cin >> oNum;
                if(oNum < 0)
                {
                    throw std::runtime_error("Order number cannot be negative.");
                }

                std::cout << "Enter Customer ID for this order: ";
                std::cin >> cID;

                Order newOrder(oNum, cID, oTime);
                // Optionally, add product numbers right here:
                bool addMore = true;
                while(addMore)
                {
                    std::cout << "Add a product number (negative to stop): ";
                    int pNum;
                    std::cin >> pNum;
                    if(pNum < 0)
                        break;
                    newOrder.addProductNum(pNum);
                }
                
                orders.push_back(newOrder);

                // Also optionally add this order to the matching customer
                for(auto &cust : customers)
                {
                    if(cust.getCustID() == cID)
                    {
                        cust.addOrderNum(oNum);
                        break;
                    }
                }

                std::cout << "Order created successfully!\n";
            }
            catch(const std::exception &ex)
            {
                std::cerr << "Error: " << ex.what() << "\n";
            }
            break;
        }
        case 3:
        {
            // Create new Product
            try
            {
                int pNum;
                std::string pName, pDesc;
                std::string pTime;
                getTime(pTime);

                std::cout << "Enter Product Number: ";
                std::cin >> pNum;
                if(pNum < 0)
                {
                    throw std::runtime_error("Product number cannot be negative.");
                }

                std::cin.ignore(); // flush newline
                std::cout << "Enter Product Name: ";
                std::getline(std::cin, pName);

                std::cout << "Enter Product Description: ";
                std::getline(std::cin, pDesc);

                Product newProduct(pNum, pName, pDesc, pTime);
                products.push_back(newProduct);

                std::cout << "Product created successfully!\n";
            }
            catch(const std::exception &ex)
            {
                std::cerr << "Error: " << ex.what() << "\n";
            }
            break;
        }
        case 4:
            // Output report
            outputReport(customers, orders, products);
            break;
        case 5:
            done = true;
            break;
        default:
            std::cout << "Invalid choice.\n";
            break;
        }
    }

    std::cout << "Exiting program...\n";
}
