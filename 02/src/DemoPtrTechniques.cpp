#include <iostream>
#include "demoPtrTechniques.h"

using std::cout;
using std::endl;

// Some helper functions to demonstrate passing pointers in different ways.
static void pointerFunction1(int *ptr)
{
    if (ptr != nullptr)
    {
        *ptr += 1; // increments the value pointed to
    }
}

static void pointerFunction2(const int *ptr)
{
    // We can read the value but cannot modify it because it's a pointer to const data.
    if (ptr != nullptr)
    {
        cout << "pointerFunction2 sees value: " << *ptr << endl;
    }
}

static void pointerFunction3(int *&refToPtr)
{
    // This function receives a reference to a pointer.
    // We can change what the pointer points to (if needed).
    if (refToPtr != nullptr)
    {
        *refToPtr *= 2; 
    }
}

static void pointerFunction4(int *ptr)
{
    // Another variation: pointer param. We'll do something minimal here.
    if (ptr != nullptr)
    {
        cout << "pointerFunction4 sees value: " << *ptr << endl;
    }
}

void demoPtrTechniques()
{
    cout << "\n*** Demonstrating Pointer Techniques ***\n";

    int x = 10;
    int *p = &x;

    // 1) Non-const pointer to non-const data:
    pointerFunction1(p); 
    cout << "After pointerFunction1, x is: " << x << endl;

    // 2) Pointer to const data:
    pointerFunction2(p);

    // 3) Reference to a pointer:
    pointerFunction3(p);
    cout << "After pointerFunction3, x is: " << x << endl;

    // 4) Another pointer pass:
    pointerFunction4(p);

    cout << "*** End Pointer Techniques ***\n\n";
}
