#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string customerID;
    std::string firstName;
    std::string lastName;
    std::string streetAddress;
    std::string city;
    std::string state;
    std::string zipCode;

public:
    Customer() = default;
    Customer(const std::string &id, const std::string &fName, const std::string &lName,
             const std::string &address, const std::string &c, const std::string &st,
             const std::string &zip)
        : customerID(id), firstName(fName), lastName(lName),
          streetAddress(address), city(c), state(st), zipCode(zip) {}

    // Getters
    std::string getCustomerID() const { return customerID; }
    std::string getFirstName()  const { return firstName; }
    std::string getLastName()   const { return lastName; }
    std::string getStreetAddress() const { return streetAddress; }
    std::string getCity()       const { return city; }
    std::string getState()      const { return state; }
    std::string getZipCode()    const { return zipCode; }

    // Helper function to load from a single line with percent-delimited fields
    bool loadFromLine(const std::string &line);
};

#endif