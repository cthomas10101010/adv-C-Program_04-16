#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template <class T>
class Stack {
private:
    std::vector<T> elements;

public:
    // Adds element to top of stack
    void push(const T& item) {
        elements.push_back(item);
    }

    // Returns and removes element from top of stack
    T pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        T topElement = elements.back();
        elements.pop_back();
        return topElement;
    }

    // Returns (but does not remove) element from top of stack
    T top() const {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elements.back();
    }

    // Removes all elements from stack
    void clear() {
        elements.clear();
    }

    // Returns true if empty, else false
    bool empty() const {
        return elements.empty();
    }
};

#endif // STACK_H