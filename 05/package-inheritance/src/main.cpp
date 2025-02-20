#include <iostream>
#include <string>
#include "package.h"
#include "twodaypackage.h"
#include "overnightpackage.h"

using namespace std;

int main() {
    // Welcome message
    cout << "Package Delivery Service Demo\n";
    cout << "============================\n\n";

    // Create a basic package
    Package package1("John Smith", "123 Main St", "Houston", "TX", "77001",
                    "Mary Johnson", "456 Oak Rd", "Dallas", "TX", "75001",
                    10.5, 0.50);

    // Create a two-day package
    TwoDayPackage package2("Bob Wilson", "789 Pine Ave", "Austin", "TX", "78701",
                          "Sarah Davis", "321 Elm St", "San Antonio", "TX", "78201",
                          8.5, 0.50, 5.00);

    // Create an overnight package
    OvernightPackage package3("Mike Brown", "741 Cedar Ln", "Fort Worth", "TX", "76101",
                            "Lisa White", "852 Maple Dr", "El Paso", "TX", "79901",
                            12.25, 0.50, 0.75);

    // Display standard package details
    cout << "Standard Package Delivery:\n";
    cout << "From: " << package1.getSenderName() << "\n";
    cout << "To: " << package1.getReceiverName() << "\n";
    cout << "Weight: " << package1.getWeight() << " ounces\n";
    cout << "Cost: $" << package1.calculateCost() << "\n\n";

    // Display two-day package details
    cout << "Two-Day Package Delivery:\n";
    cout << "From: " << package2.getSenderName() << "\n";
    cout << "To: " << package2.getReceiverName() << "\n";
    cout << "Weight: " << package2.getWeight() << " ounces\n";
    cout << "Cost: $" << package2.calculateCost() << "\n\n";

    // Display overnight package details
    cout << "Overnight Package Delivery:\n";
    cout << "From: " << package3.getSenderName() << "\n";
    cout << "To: " << package3.getReceiverName() << "\n";
    cout << "Weight: " << package3.getWeight() << " ounces\n";
    cout << "Cost: $" << package3.calculateCost() << "\n";

    return 0;
}