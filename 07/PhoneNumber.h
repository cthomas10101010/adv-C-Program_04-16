#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstring>

class PhoneNumber {
private:
    char phone[15];     // Holds entire phone number plus '\0'
    char areaCode[4];   // Holds area code plus '\0'
    char exchange[4];   // Holds exchange plus '\0'
    char line[5];       // Holds line plus '\0'

public:
    PhoneNumber() {
        std::strcpy(phone,    "");
        std::strcpy(areaCode, "");
        std::strcpy(exchange, "");
        std::strcpy(line,     "");
    }

    friend std::ostream &operator<<(std::ostream &output, const PhoneNumber &num);
    friend std::istream &operator>>(std::istream &input, PhoneNumber &num);
};

#endif