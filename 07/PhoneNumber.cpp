#include "PhoneNumber.h"

std::ostream &operator<<(std::ostream &output, const PhoneNumber &num) {
    output << "(" << num.areaCode << ") " << num.exchange << "-" << num.line;
    return output;
}

std::istream &operator>>(std::istream &input, PhoneNumber &num) {
    // Read up to 14 characters + null terminator (15 total).
    // Using input.get() to get exactly 14 chars plus '\0'.
    // Or you can use input.getline(num.phone, 15), but here we want exactly 14 chars.
    // We'll do a temporary buffer to handle exactly 14 characters plus '\0'.
    char buffer[15] = "";
    input.get(buffer, 15); // reads up to 14 chars, stops before '\n'
    if (!input) {
        return input; // stream might already be in fail state
    }

    // If the user pressed ENTER too soon or there's leftover data,
    // consume the leftover newline from the buffer.
    if (input.peek() == '\n') {
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Validate length == 14, format: (888) 555-1234
    if (std::strlen(buffer) != 14) {
        input.setstate(std::ios::failbit);
        return input;
    }
    // Check expected punctuation
    if (buffer[0] != '(' || buffer[4] != ')' || buffer[5] != ' ' || buffer[9] != '-') {
        input.setstate(std::ios::failbit);
        return input;
    }
    // Check areaCode and exchange do not begin with 0 or 1
    // areaCode is buffer[1..3], exchange is buffer[6..8]
    if (buffer[1] == '0' || buffer[1] == '1' ||
        buffer[2] == '0' || buffer[2] == '1' ||
        buffer[3] == '0' || buffer[3] == '1' ||
        buffer[6] == '0' || buffer[6] == '1' ||
        buffer[7] == '0' || buffer[7] == '1' ||
        buffer[8] == '0' || buffer[8] == '1') {
        input.setstate(std::ios::failbit);
        return input;
    }

    // If no fail so far, copy entire phone number
    std::strcpy(num.phone, buffer);

    // Copy areaCode (chars [1..3])
    num.areaCode[0] = buffer[1];
    num.areaCode[1] = buffer[2];
    num.areaCode[2] = buffer[3];
    num.areaCode[3] = '\0';

    // Copy exchange (chars [6..8])
    num.exchange[0] = buffer[6];
    num.exchange[1] = buffer[7];
    num.exchange[2] = buffer[8];
    num.exchange[3] = '\0';

    // Copy line (chars [10..13])
    num.line[0] = buffer[10];
    num.line[1] = buffer[11];
    num.line[2] = buffer[12];
    num.line[3] = buffer[13];
    num.line[4] = '\0';

    return input;
}