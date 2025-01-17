#include "OverloadDemo.h"

// + operator
OverloadDemo OverloadDemo::operator+(const OverloadDemo& rhs) const {
    OverloadDemo temp;
    temp.intOne = intOne + rhs.intOne;
    temp.doubleOne = doubleOne + rhs.doubleOne;
    temp.stringOne = stringOne + rhs.stringOne;
    return temp;
}

// - operator
OverloadDemo OverloadDemo::operator-(const OverloadDemo& rhs) const {
    OverloadDemo temp;
    temp.intOne = intOne - rhs.intOne;
    temp.doubleOne = doubleOne - rhs.doubleOne;

    // Remove rhs.stringOne at the end of stringOne if found
    temp.stringOne = stringOne;
    size_t pos = temp.stringOne.rfind(rhs.stringOne);
    if (pos != std::string::npos) {
        temp.stringOne.erase(pos, rhs.stringOne.size());
    }
    return temp;
}

// * operator
OverloadDemo OverloadDemo::operator*(const OverloadDemo& rhs) const {
    OverloadDemo temp;
    temp.intOne = intOne * rhs.intOne;
    temp.doubleOne = doubleOne * rhs.doubleOne;

    // Repeat stringOne rhs.intOne times
    for (int i = 0; i < rhs.intOne; ++i) {
        temp.stringOne += stringOne;
    }
    return temp;
}

// / operator
OverloadDemo OverloadDemo::operator/(const OverloadDemo& rhs) const {
    OverloadDemo temp;
    // Avoid divide-by-zero
    temp.intOne   = (rhs.intOne != 0) ? intOne / rhs.intOne : 0;
    temp.doubleOne = (rhs.doubleOne != 0.0) ? doubleOne / rhs.doubleOne : 0.0;

    // Example: take half of stringOne
    temp.stringOne = stringOne.substr(0, stringOne.size() / 2);
    return temp;
}

// Prefix ++
OverloadDemo& OverloadDemo::operator++() {
    ++intOne;
    ++doubleOne;
    return *this;
}

// Postfix ++
OverloadDemo OverloadDemo::operator++(int) {
    OverloadDemo temp(*this);
    ++(*this);
    return temp;
}

// Prefix --
OverloadDemo& OverloadDemo::operator--() {
    --intOne;
    --doubleOne;
    return *this;
}

// Postfix --
OverloadDemo OverloadDemo::operator--(int) {
    OverloadDemo temp(*this);
    --(*this);
    return temp;
}