#ifndef OVERLOADDEMO_H
#define OVERLOADDEMO_H

#include <string>

class OverloadDemo {
private:
    int intOne;
    double doubleOne;
    std::string stringOne;

public:
    // Constructors
    OverloadDemo(int i = 0, double d = 0.0, std::string s = "")
        : intOne(i), doubleOne(d), stringOne(s) {}

    // Setters
    void setIntOne(int i) { intOne = i; }
    void setDoubleOne(double d) { doubleOne = d; }
    void setStringOne(const std::string& s) { stringOne = s; }

    // Getters
    int getIntOne() const { return intOne; }
    double getDoubleOne() const { return doubleOne; }
    std::string getStringOne() const { return stringOne; }

    // Operator Overloads
    OverloadDemo operator+(const OverloadDemo& rhs) const;
    OverloadDemo operator-(const OverloadDemo& rhs) const;
    OverloadDemo operator*(const OverloadDemo& rhs) const;
    OverloadDemo operator/(const OverloadDemo& rhs) const;

    // Prefix ++
    OverloadDemo& operator++();
    // Postfix ++
    OverloadDemo operator++(int);

    // Prefix --
    OverloadDemo& operator--();
    // Postfix --
    OverloadDemo operator--(int);
};

#endif