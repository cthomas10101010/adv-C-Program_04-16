#include "Customer.h"

int Customer::customerCount = 0;

Customer::Customer(int id, const std::string& n, const std::string& addr, const std::string& time)
    : custID(id), name(n), address(addr), customerCreationTime(time)
{
    customerCount++;
}