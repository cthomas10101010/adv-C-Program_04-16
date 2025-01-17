#ifndef LIST_H
#define LIST_H

#include <stdexcept>
#include <iostream>
#include <vector>

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

    /**
     * @brief Performs a linear search for a value in the list.
     * 
     * @param target The value to search for.
     * @return int The index of the target if found; otherwise, -1.
     */
    int linearSearch(const T& target) const {
        Node<T>* temp = head;
        int index = 0;
        while (temp != nullptr) {
            if (temp->data == target) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    /**
     * @brief Sorts the list using Selection Sort algorithm.
     */
    void selectionSort() {
        if (size < 2) return;
        for (Node<T>* i = head; i->next != nullptr; i = i->next) {
            Node<T>* min = i;
            for (Node<T>* j = i->next; j != nullptr; j = j->next) {
                if (j->data < min->data) {
                    min = j;
                }
            }
            if (min != i) {
                std::swap(i->data, min->data);
            }
        }
    }

    /**
     * @brief Sorts the list using Merge Sort algorithm.
     */
    void mergeSort() {
        head = mergeSortRec(head);

        // Update tail after sorting
        tail = head;
        if (tail != nullptr) {
            while (tail->next != nullptr) {
                tail = tail->next;
            }
        }
    }

    /**
     * @brief Performs a binary search for a value in the sorted list.
     * 
     * @param target The value to search for.
     * @return int The index of the target if found; otherwise, -1.
     * @throws std::invalid_argument If the list is not sorted.
     */
    int binarySearch(const T& target) const {
        // Convert linked list to vector for binary search
        std::vector<T> vec;
        Node<T>* temp = head;
        while (temp != nullptr) {
            vec.push_back(temp->data);
            temp = temp->next;
        }

        int left = 0;
        int right = vec.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (vec[mid] == target) {
                return mid;
            }
            if (vec[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

private:
    /**
     * @brief Recursively splits and merges the list for Merge Sort.
     * 
     * @param headRef The head of the sublist.
     * @return Node<T>* The new head after sorting.
     */
    Node<T>* mergeSortRec(Node<T>* headRef) {
        if (headRef == nullptr || headRef->next == nullptr) {
            return headRef;
        }

        Node<T>* middle = getMiddle(headRef);
        Node<T>* nextOfMiddle = middle->next;

        middle->next = nullptr;

        Node<T>* left = mergeSortRec(headRef);
        Node<T>* right = mergeSortRec(nextOfMiddle);

        Node<T>* sortedList = sortedMerge(left, right);
        return sortedList;
    }

    /**
     * @brief Merges two sorted lists.
     * 
     * @param a First sorted list.
     * @param b Second sorted list.
     * @return Node<T>* Merged sorted list.
     */
    Node<T>* sortedMerge(Node<T>* a, Node<T>* b) {
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;

        Node<T>* result = nullptr;

        if (a->data <= b->data) {
            result = a;
            result->next = sortedMerge(a->next, b);
        }
        else {
            result = b;
            result->next = sortedMerge(a, b->next);
        }
        return result;
    }

    /**
     * @brief Finds the middle node of the list.
     * 
     * @param headRef The head of the list.
     * @return Node<T>* The middle node.
     */
    Node<T>* getMiddle(Node<T>* headRef) {
        if (headRef == nullptr)
            return headRef;

        Node<T>* slow = headRef;
        Node<T>* fast = headRef->next;

        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }
};

#endif // LIST_H