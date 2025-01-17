#include <iostream>
#include <string>
#include <vector>
#include <limits> // For numeric_limits<streamsize>
#include "Customer.h"
#include "Order.h"
#include "Product.h"
#include "TimeFunctions.h"
#include "OutputReport.h"

using namespace std;
//g++ -I include src\main.cpp src\ProgramFunctions.cpp src\Customer.cpp src\Order.cpp src\Product.cpp src\TimeFunctions.cpp src\OutputReport.cpp -o Program_03.exe

int main() {
    vector<Customer> customers;
    vector<Order> orders;
    vector<Product> products;

    int choice = 0;

    while (choice != 5) {
        cout << "\n=== Simple Product Ordering System ===\n\n"
             << "1. Create New Customer\n"
             << "2. Create New Order\n"
             << "3. Create New Product\n"
             << "4. Output Report\n"
             << "5. Quit\n"
             << "Enter choice: ";
        cin >> choice;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input; please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            cout << "Enter Customer ID: ";
            int custID;
            cin >> custID;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush leftover input

            cout << "Enter Customer Name: ";
            string name;
            getline(cin, name);

            cout << "Enter Customer Address: ";
            string address;
            getline(cin, address);

            string dateTime;
            getTime(dateTime);
            Customer newCust(custID, name, address, dateTime);
            customers.push_back(newCust);
            cout << "Customer created successfully!\n";
            break;
        }
        case 2: {
            cout << "Enter Order Number: ";
            int orderNum;
            cin >> orderNum;

            cout << "Enter Customer ID for this order: ";
            int cID;
            cin >> cID;

            string dateTime;
            getTime(dateTime);
            Order newOrder(orderNum, cID, dateTime);

            cout << "Add a product number (negative to stop): ";
            int productNum;
            cin >> productNum;

            while (productNum >= 0) {
                newOrder.addProductNum(productNum);
                cout << "Add a product number (negative to stop): ";
                cin >> productNum;
            }

            orders.push_back(newOrder);
            for (auto &cust : customers) {
                if (cust.getCustID() == cID) {
                    cust.addOrderNum(orderNum);
                    break;
                }
            }

            cout << "Order created successfully!\n";
            break;
        }
        case 3: {
            cout << "Enter Product Number: ";
            int pNum;
            cin >> pNum;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush leftover input

            cout << "Enter Product Name: ";
            string pName;
            getline(cin, pName);

            cout << "Enter Product Description: ";
            string pDesc;
            getline(cin, pDesc);

            string dateTime;
            getTime(dateTime);
            Product newProduct(pNum, pName, pDesc, dateTime);
            products.push_back(newProduct);

            cout << "Product created successfully!\n";
            break;
        }
        case 4: {
            outputReport(customers, orders, products);
            break;
        }
        case 5:
            cout << "Quitting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    }

    return 0;
}
