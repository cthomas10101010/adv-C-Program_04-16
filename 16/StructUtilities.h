#ifndef STRUCTUTILITIES_H
#define STRUCTUTILITIES_H

struct Person {
    char name[50];
    int age;
    unsigned int id;
};

class StructUtilities {
public:
    /**
     * @brief Demonstrates structure operations.
     */
    void handleStructures();
};

#endif // STRUCTUTILITIES_H