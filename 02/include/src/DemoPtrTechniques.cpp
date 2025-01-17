#include <iostream>
#include "DemoPtrTechniques.h"

//-----------------------------------------------------
// Demonstrations for passing a pointer in four ways
//-----------------------------------------------------
static void passByPointer(int* ptr)
{
    std::cout << "[passByPointer] Value = " << *ptr 
              << " (Will increment by 10)\n";
    *ptr += 10;
}

static void passPointerToConst(const int* ptr)
{
    std::cout << "[passPointerToConst] Value = " << *ptr 
              << " (Cannot modify the data via ptr)\n";
    // *ptr += 10; // Not allowed because data is const
}

static void passConstPointer(int* const ptr)
{
    std::cout << "[passConstPointer] Value = " << *ptr 
              << " (Pointer address cannot change)\n";
    *ptr += 10; // We can modify the data
}

static void passConstPointerToConst(const int* const ptr)
{
    std::cout << "[passConstPointerToConst] Value = " << *ptr 
              << " (Cannot modify data or pointer)\n";
    // *ptr += 10; // Not allowed
    // ptr = nullptr; // Not allowed
}

//-----------------------------------------------------
// Function Name: demoPtrTechniques
// Purpose      : Demonstrate four ways to pass pointer
//-----------------------------------------------------
void demoPtrTechniques()
{
    std::cout << "=== Demo: Four Ways to Pass a Pointer ===\n";

    int myValue = 100;
    int* myPtr = &myValue;

    std::cout << "Initial myValue = " << myValue << "\n\n";
    
    // 1) passByPointer
    passByPointer(myPtr);
    std::cout << "After passByPointer: myValue = " << myValue << "\n\n";

    // 2) passPointerToConst
    passPointerToConst(myPtr);
    std::cout << "After passPointerToConst: myValue = " << myValue << "\n\n";

    // 3) passConstPointer
    passConstPointer(myPtr);
    std::cout << "After passConstPointer: myValue = " << myValue << "\n\n";

    // 4) passConstPointerToConst
    passConstPointerToConst(myPtr);
    std::cout << "After passConstPointerToConst: myValue = " << myValue << "\n\n";
}
