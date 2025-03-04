#include "PhoneNumber.h"
#include <cctype>

std::ostream& operator<<(std::ostream& output, const PhoneNumber& num) {
    output << "(" << num.areaCode << ") " << num.exchange << "-" << num.line;
    return output;
}

std::istream& operator>>(std::istream& input, PhoneNumber& num) {
    // Use a larger buffer to handle potential overflow
    char temp[25] = "";
    
    // Read the first line of input (up to newline) with a max size
    input.getline(temp, 25);
    
    // Check if we read any characters
    int length = std::strlen(temp);
    
    // Check length
    if (length != 14) {
        input.setstate(std::ios::failbit);
        return input;
    }

    // Validate format: (XXX) XXX-XXXX
    if (temp[0] != '(' || temp[4] != ')' || temp[5] != ' ' || temp[9] != '-') {
        input.setstate(std::ios::failbit);
        return input;
    }

    // Check if area code and exchange digits are valid (not 0 or 1)
    if (temp[1] == '0' || temp[1] == '1' || temp[6] == '0' || temp[6] == '1') {
        input.setstate(std::ios::failbit);
        return input;
    }

    // Validate all digits in proper positions
    for (int j = 1; j <= 3; ++j) {
        if (!isdigit(temp[j])) { // area code
            input.setstate(std::ios::failbit);
            return input;
        }
    }
    
    for (int j = 6; j <= 8; ++j) {
        if (!isdigit(temp[j])) { // exchange
            input.setstate(std::ios::failbit);
            return input;
        }
    }
    
    for (int j = 10; j <= 13; ++j) {
        if (!isdigit(temp[j])) { // line number
            input.setstate(std::ios::failbit);
            return input;
        }
    }

    // If we get here, format is valid - copy to number
    std::strcpy(num.phone, temp);
    
    // Extract area code
    strncpy(num.areaCode, &temp[1], 3);
    num.areaCode[3] = '\0';
    
    // Extract exchange
    strncpy(num.exchange, &temp[6], 3);
    num.exchange[3] = '\0';
    
    // Extract line number
    strncpy(num.line, &temp[10], 4);
    num.line[4] = '\0';

    return input;
}