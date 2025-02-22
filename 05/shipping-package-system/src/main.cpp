#include <iostream>
#include <string>
#include "package.h"
#include "twodaypackage.h"
#include "overnightpackage.h"

using namespace std;

int main() {
    string senderName, senderAddress, senderCity, senderState, senderZip;
    string receiverName, receiverAddress, receiverCity, receiverState, receiverZip;
    double weight, costPerOunce, twoDayFee, overnightRate;

    // Input sender details
    cout << "Enter sender's name: ";
    getline(cin, senderName);
    cout << "Enter sender's address: ";
    getline(cin, senderAddress);
    cout << "Enter sender's city: ";
    getline(cin, senderCity);
    cout << "Enter sender's state: ";
    getline(cin, senderState);
    cout << "Enter sender's zip code: ";
    getline(cin, senderZip);

    // Input receiver details
    cout << "Enter receiver's name: ";
    getline(cin, receiverName);
    cout << "Enter receiver's address: ";
    getline(cin, receiverAddress);
    cout << "Enter receiver's city: ";
    getline(cin, receiverCity);
    cout << "Enter receiver's state: ";
    getline(cin, receiverState);
    cout << "Enter receiver's zip code: ";
    getline(cin, receiverZip);

    // Input package details
    cout << "Enter weight of the package: ";
    cin >> weight;
    cout << "Enter cost per ounce: ";
    cin >> costPerOunce;

    // Create Package object
    Package package(senderName, senderAddress, senderCity, senderState, senderZip,
                    receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
                    weight, costPerOunce);
    cout << "Cost of standard package: $" << package.calculateCost() << endl;

    // Input two-day package details
    cout << "Enter two-day shipping fee: ";
    cin >> twoDayFee;
    TwoDayPackage twoDayPackage(senderName, senderAddress, senderCity, senderState, senderZip,
                                 receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
                                 weight, costPerOunce, twoDayFee);
    cout << "Cost of two-day package: $" << twoDayPackage.calculateCost() << endl;

    // Input overnight package details
    cout << "Enter overnight rate per ounce: ";
    cin >> overnightRate;
    OvernightPackage overnightPackage(senderName, senderAddress, senderCity, senderState, senderZip,
                                      receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
                                      weight, costPerOunce, overnightRate);
    cout << "Cost of overnight package: $" << overnightPackage.calculateCost() << endl;

    return 0;
}