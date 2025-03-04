#include "Customer.h"
#include <sstream>

bool Customer::loadFromLine(const std::string &line) {
    // Format: CustomerID%FirstName%LastName%StreetAddress%City%State%ZipCode
    // We'll parse by splitting at '%'.
    size_t start = 0;
    size_t end   = 0;
    int fieldIndex = 0;
    std::string fields[7];

    while ((end = line.find('%', start)) != std::string::npos && fieldIndex < 7) {
        fields[fieldIndex++] = line.substr(start, end - start);
        start = end + 1;
    }
    // Last field (zip code)
    if (fieldIndex < 7) {
        fields[fieldIndex++] = line.substr(start);
    }

    if (fieldIndex == 7) {
        customerID     = fields[0];
        firstName      = fields[1];
        lastName       = fields[2];
        streetAddress  = fields[3];
        city           = fields[4];
        state          = fields[5];
        zipCode        = fields[6];
        return true;
    }
    // If line is malformed
    return false;
}