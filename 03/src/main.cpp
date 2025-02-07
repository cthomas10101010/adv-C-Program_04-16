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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input; please enter a number.\n";
            continue;
        }
        
        switch (choice) {
            case 1: {
                cout << "Enter Customer ID: ";
                int custID;
                cin >> custID;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Flush leftover input
                
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

    cout << "Enter product numbers for this order (-1 to stop):\n";
    while (true) {
        cout << "Product Number: ";
        int prodNum;
        cin >> prodNum;
        if (prodNum < 0) {
            break;
        }
        newOrder.addProductNum(prodNum);
    }
    orders.push_back(newOrder);

    cout << "Order created successfully!\n";
    break;
}
case 3: {
    cout << "Enter Product Number: ";
    int prodNum;
    cin >> prodNum;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Product Name: ";
    string prodName;
    getline(cin, prodName);

    cout << "Enter Product Description: ";
    string prodDesc;
    getline(cin, prodDesc);

    string dateTime;
    getTime(dateTime);

    Product newProd(prodNum, prodName, prodDesc, dateTime);
    products.push_back(newProd);

    cout << "Product created successfully!\n";
    break;
}
            case 4: {
                outputReport(customers, orders, products);
                break;
            }
            case 5: {
                cout << "Exiting program...\n";
                break;
            }
            default: {
                cout << "Invalid choice.\n";
                break;
            }
        }
    }
    
    return 0;
}