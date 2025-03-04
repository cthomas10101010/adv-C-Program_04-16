#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <iomanip>
#include <cstring>

class PhoneNumber {
private:  // Changed from public to private
    char phone[15];     // holds entire phone number plus \0
    char areaCode[4];   // holds area code plus \0
    char exchange[4];   // holds exchange plus \0
    char line[5];       // holds line plus \0

public:
    PhoneNumber() {
        std::strcpy(phone, "");
        std::strcpy(areaCode, "");
        std::strcpy(exchange, "");
        std::strcpy(line, "");
    }

    // Add accessor functions since data is now private
    const char* getPhone() const { return phone; }
    const char* getAreaCode() const { return areaCode; }
    const char* getExchange() const { return exchange; }
    const char* getLine() const { return line; }

    friend std::ostream& operator<<(std::ostream&, const PhoneNumber&);
    friend std::istream& operator>>(std::istream&, PhoneNumber&);
};

#endif