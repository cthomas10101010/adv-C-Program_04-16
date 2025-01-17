#ifndef LIST_H
#define LIST_H

#include <stdexcept>
#include <iostream>

/**
 * @brief Node structure for the List.
 * 
 * @tparam T Type of data stored in the node.
 */
template <class T>
struct Node {
    T data;
    Node<T>* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

/**
 * @brief Custom singly linked list template class.
 * 
 * @tparam T Type of elements stored in the list.
 */
template <class T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    /**
     * @brief Constructor initializes an empty list.
     */
    List() : head(nullptr), tail(nullptr), size(0) {}

    /**
     * @brief Destructor cleans up all nodes.
     */
    ~List() {
        clear();
    }

    /**
     * @brief Inserts an element at the beginning of the list.
     * 
     * @param value The value to insert.
     */
    void insertAtBeginning(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        if (size == 0) {
            tail = head;
        }
        size++;
    }

    /**
     * @brief Inserts an element at the end of the list.
     * 
     * @param value The value to insert.
     */
    void insertAtEnd(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (size == 0) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    /**
     * @brief Deletes an element from the beginning of the list.
     * 
     * @return The value of the deleted node.
     * @throws std::out_of_range If the list is empty.
     */
    T deleteFromBeginning() {
        if (size == 0) {
            throw std::out_of_range("List<>::deleteFromBeginning(): empty list");
        }
        Node<T>* temp = head;
        T value = temp->data;
        head = head->next;
        delete temp;
        size--;
        if (size == 0) {
            tail = nullptr;
        }
        return value;
    }

    /**
     * @brief Deletes an element from the end of the list.
     * 
     * @return The value of the deleted node.
     * @throws std::out_of_range If the list is empty.
     */
    T deleteFromEnd() {
        if (size == 0) {
            throw std::out_of_range("List<>::deleteFromEnd(): empty list");
        }
        Node<T>* temp = head;
        T value;
        if (size == 1) {
            value = head->data;
            delete head;
            head = tail = nullptr;
        }
        else {
            while (temp->next != tail) {
                temp = temp->next;
            }
            value = tail->data;
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        size--;
        return value;
    }

    /**
     * @brief Inserts an element at a specific index in the list.
     * 
     * @param index The position to insert at (0-based).
     * @param value The value to insert.
     * @throws std::out_of_range If the index is out of bounds.
     */
    void insertAt(int index, const T& value) {
        if (index < 0 || index > size) {
            throw std::out_of_range("List<>::insertAt(): index out of range");
        }
        if (index == 0) {
            insertAtBeginning(value);
            return;
        }
        if (index == size) {
            insertAtEnd(value);
            return;
        }
        Node<T>* newNode = new Node<T>(value);
        Node<T>* temp = head;
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    /**
     * @brief Deletes the first node with the specified value.
     * 
     * @param value The value to delete.
     * @throws std::invalid_argument If the value is not found in the list.
     */
    void deleteByValue(const T& value) {
        if (size == 0) {
            throw std::out_of_range("List<>::deleteByValue(): empty list");
        }
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            throw std::invalid_argument("List<>::deleteByValue(): value not found");
        }
        Node<T>* toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete == tail) {
            tail = temp;
        }
        delete toDelete;
        size--;
    }

    /**
     * @brief Checks if the list is empty.
     * 
     * @return true If the list is empty.
     * @return false Otherwise.
     */
    bool empty() const {
        return size == 0;
    }

    /**
     * @brief Clears the entire list.
     */
    void clear() {
        while (!empty()) {
            deleteFromBeginning();
        }
    }

    /**
     * @brief Displays the elements of the list.
     */
    void display() const {
        if (empty()) {
            std::cout << "List is empty.\n";
            return;
        }
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }
};

#endif // LIST_H