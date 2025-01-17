#include "ContainerDemo.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <random>

// Function Objects
struct Square {
    void operator()(int &x) const {
        x = x * x;
    }
};

struct Multiply {
    int factor;
    Multiply(int f) : factor(f) {}
    int operator()(int x) const {
        return x * factor;
    }
};

struct IsEven {
    bool operator()(int x) const {
        return x % 2 == 0;
    }
};

struct Print {
    void operator()(const int &x) const {
        std::cout << x << " ";
    }
};

// Vector Demonstration
void demoVector() {
    std::vector<int> vec;
    int num;
    std::cout << "\nPopulate vector<int>. Enter -1 to stop:\n";
    while (true) {
        std::cout << "Enter integer: ";
        std::cin >> num;
        if (num == -1) break;
        vec.push_back(num);
    }

    std::cout << "\nOriginal vector: ";
    std::for_each(vec.begin(), vec.end(), Print());

    // Modifying Sequence Algorithms
    std::for_each(vec.begin(), vec.end(), Square()); // Modify: square each element
    std::cout << "\nAfter squaring elements: ";
    std::for_each(vec.begin(), vec.end(), Print());

    std::transform(vec.begin(), vec.end(), vec.begin(), Multiply(2)); // Modify: multiply by 2
    std::cout << "\nAfter multiplying by 2: ";
    std::for_each(vec.begin(), vec.end(), Print());

    // Non-Modifying Sequence Algorithms
    int sum = std::accumulate(vec.begin(), vec.end(), 0); // Numerical algorithm
    std::cout << "\nSum of elements: " << sum;

    double average = static_cast<double>(sum) / vec.size();
    std::cout << "\nAverage of elements: " << average;

    bool hasEven = std::any_of(vec.begin(), vec.end(), IsEven()); // Non-modifying
    std::cout << "\nVector has even numbers: " << (hasEven ? "Yes" : "No");

    // Sorting Algorithms
    std::sort(vec.begin(), vec.end()); // Sort in ascending order
    std::cout << "\nAfter sort: ";
    std::for_each(vec.begin(), vec.end(), Print());

    std::reverse(vec.begin(), vec.end()); // Reverse the vector
    std::cout << "\nAfter reverse: ";
    std::for_each(vec.begin(), vec.end(), Print());

    // Numerical Algorithms
    int maxVal = *std::max_element(vec.begin(), vec.end());
    std::cout << "\nMaximum element: " << maxVal;

    int minVal = *std::min_element(vec.begin(), vec.end());
    std::cout << "\nMinimum element: " << minVal;

    // Function Objects in Algorithms
    std::for_each(vec.begin(), vec.end(), Print());
    std::cout << "\n";
}

// List Demonstration
void demoList() {
    std::list<int> lst;
    int num;
    std::cout << "\nPopulate list<int>. Enter -1 to stop:\n";
    while (true) {
        std::cout << "Enter integer: ";
        std::cin >> num;
        if (num == -1) break;
        lst.push_back(num);
    }

    std::cout << "\nOriginal list: ";
    std::for_each(lst.begin(), lst.end(), Print());

    // Modifying Sequence Algorithms
    std::for_each(lst.begin(), lst.end(), Square()); // Modify: square each element
    std::cout << "\nAfter squaring elements: ";
    std::for_each(lst.begin(), lst.end(), Print());

    lst.remove_if(IsEven()); // Modify: remove even numbers
    std::cout << "\nAfter removing even elements: ";
    std::for_each(lst.begin(), lst.end(), Print());

    // Non-Modifying Sequence Algorithms
    int sum = std::accumulate(lst.begin(), lst.end(), 0); // Numerical algorithm
    std::cout << "\nSum of elements: " << sum;

    bool allPositive = std::all_of(lst.begin(), lst.end(), [](int x) { return x > 0; });
    std::cout << "\nAll elements positive: " << (allPositive ? "Yes" : "No");

    // Sorting Algorithms
    lst.sort(); // Sort in ascending order
    std::cout << "\nAfter sort: ";
    std::for_each(lst.begin(), lst.end(), Print());

    lst.reverse(); // Reverse the list
    std::cout << "\nAfter reverse: ";
    std::for_each(lst.begin(), lst.end(), Print());

    // Sorting Related Algorithms
    lst.sort(std::greater<int>()); // Sort in descending order
    std::cout << "\nAfter sorting in descending order: ";
    std::for_each(lst.begin(), lst.end(), Print());

    // Numerical Algorithms
    int maxVal = lst.empty() ? 0 : *std::max_element(lst.begin(), lst.end());
    std::cout << "\nMaximum element: " << maxVal;

    // Function Objects in Algorithms
    std::for_each(lst.begin(), lst.end(), Print());
    std::cout << "\n";
}

// Deque Demonstration
void demoDeque() {
    std::deque<int> dq;
    int num;
    std::cout << "\nPopulate deque<int>. Enter -1 to stop:\n";
    while (true) {
        std::cout << "Enter integer: ";
        std::cin >> num;
        if (num == -1) break;
        dq.push_back(num);
    }

    std::cout << "\nOriginal deque: ";
    std::for_each(dq.begin(), dq.end(), Print());

    // Modifying Sequence Algorithms
    std::for_each(dq.begin(), dq.end(), Square()); // Modify: square each element
    std::cout << "\nAfter squaring elements: ";
    std::for_each(dq.begin(), dq.end(), Print());

    std::transform(dq.begin(), dq.end(), dq.begin(), Multiply(3)); // Modify: multiply by 3
    std::cout << "\nAfter multiplying by 3: ";
    std::for_each(dq.begin(), dq.end(), Print());

    // Non-Modifying Sequence Algorithms
    int sum = std::accumulate(dq.begin(), dq.end(), 0); // Numerical algorithm
    std::cout << "\nSum of elements: " << sum;

    bool hasOdd = std::any_of(dq.begin(), dq.end(), [](int x) { return x % 2 != 0; });
    std::cout << "\nDeque has odd numbers: " << (hasOdd ? "Yes" : "No");

    // Sorting Algorithms
    std::sort(dq.begin(), dq.end()); // Sort in ascending order
    std::cout << "\nAfter sort: ";
    std::for_each(dq.begin(), dq.end(), Print());

    std::reverse(dq.begin(), dq.end()); // Reverse the deque
    std::cout << "\nAfter reverse: ";
    std::for_each(dq.begin(), dq.end(), Print());

    // Sorting Related Algorithms
    std::partial_sort(dq.begin(), dq.begin() + 3, dq.end()); // Partial sort
    std::cout << "\nAfter partial sort (first 3 elements): ";
    std::for_each(dq.begin(), dq.end(), Print());

    // Numerical Algorithms
    int maxVal = *std::max_element(dq.begin(), dq.end());
    std::cout << "\nMaximum element: " << maxVal;

    // Function Objects in Algorithms
    std::for_each(dq.begin(), dq.end(), Print());
    std::cout << "\n";
}

// Set Demonstration
void demoSet() {
    std::set<int> st;
    int num;
    std::cout << "\nPopulate set<int>. Enter -1 to stop:\n";
    while (true) {
        std::cout << "Enter integer: ";
        std::cin >> num;
        if (num == -1) break;
        st.insert(num);
    }

    std::cout << "\nOriginal set: ";
    std::for_each(st.begin(), st.end(), Print());

    // Modifying Sequence Algorithms
    // Note: std::set elements are immutable, so modifying algorithms are limited
    // Example: Inserting a new element
    std::cout << "\nInserting 100 into set.\n";
    st.insert(100);
    std::cout << "After insertion: ";
    std::for_each(st.begin(), st.end(), Print());

    // Non-Modifying Sequence Algorithms
    bool contains50 = std::find(st.begin(), st.end(), 50) != st.end();
    std::cout << "\nSet contains 50: " << (contains50 ? "Yes" : "No");

    // Sorting Algorithms
    // std::set is always sorted, but we can demonstrate sorting algorithms on a copy
    std::vector<int> temp(st.begin(), st.end());
    std::shuffle(temp.begin(), temp.end(), std::default_random_engine(42));
    std::cout << "\nShuffled copy of set: ";
    std::for_each(temp.begin(), temp.end(), Print());

    std::sort(temp.begin(), temp.end(), std::greater<int>());
    std::cout << "\nAfter sorting shuffled copy in descending order: ";
    std::for_each(temp.begin(), temp.end(), Print());

    // Numerical Algorithms
    int total = std::accumulate(st.begin(), st.end(), 0); // Numerical algorithm
    std::cout << "\nSum of set elements: " << total;

    // Function Objects in Algorithms
    std::for_each(st.begin(), st.end(), Print());
    std::cout << "\n";
}

// Map Demonstration
void demoMap() {
    std::map<std::string, int> mp;
    std::string key;
    int value;
    std::cout << "\nPopulate map<string, int>. Enter 'stop' as key to stop:\n";
    while (true) {
        std::cout << "Enter key (string): ";
        std::cin >> key;
        if (key == "stop") break;
        std::cout << "Enter value (int): ";
        std::cin >> value;
        mp[key] = value;
    }

    std::cout << "\nOriginal map:\n";
    for (const auto &kv : mp) {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    // Modifying Sequence Algorithms
    // Example: Increment each value by 10
    std::for_each(mp.begin(), mp.end(), [&](std::pair<const std::string, int> &kv) {
        kv.second += 10;
    });
    std::cout << "\nAfter incrementing each value by 10:\n";
    for (const auto &kv : mp) {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    // Non-Modifying Sequence Algorithms
    bool hasKey = mp.find("example") != mp.end();
    std::cout << "\nMap contains key 'example': " << (hasKey ? "Yes" : "No");

    // Sorting Algorithms
    // std::map is ordered by keys, but we can sort by values using a vector
    std::vector<std::pair<std::string, int>> vec(mp.begin(), mp.end());
    std::sort(vec.begin(), vec.end(), [](const std::pair<std::string, int> &a,
                                       const std::pair<std::string, int> &b) -> bool {
        return a.second < b.second;
    });
    std::cout << "\nMap sorted by values:\n";
    for (const auto &kv : vec) {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    // Numerical Algorithms
    int total = std::accumulate(mp.begin(), mp.end(), 0, 
        [](int sum, const std::pair<std::string, int> &kv) -> int {
            return sum + kv.second;
        });
    std::cout << "\nTotal of all values: " << total;

    // Function Objects in Algorithms
    std::for_each(mp.begin(), mp.end(), [&](const std::pair<std::string, int> &kv) {
        std::cout << kv.first << " : " << kv.second << "\n";
    });
}

// Queue Demonstration
void demoQueue() {
    std::queue<int> q;
    int num;
    std::cout << "\nPopulate queue<int>. Enter -1 to stop:\n";
    while (true) {
        std::cout << "Enter integer: ";
        std::cin >> num;
        if (num == -1) break;
        q.push(num);
    }

    std::cout << "\nOriginal queue: ";
    std::queue<int> temp = q;
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }

    // Modifying Sequence Algorithms
    // Example: Multiply each element by 5
    std::queue<int> modified;
    while (!q.empty()) {
        modified.push(q.front() * 5);
        q.pop();
    }
    q = modified;
    std::cout << "\nAfter multiplying each element by 5: ";
    temp = q;
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }

    // Non-Modifying Sequence Algorithms
    bool hasTen = false;
    temp = q;
    while (!temp.empty()) {
        if (temp.front() == 10) {
            hasTen = true;
            break;
        }
        temp.pop();
    }
    std::cout << "\nQueue contains 10: " << (hasTen ? "Yes" : "No");

    // Sorting Algorithms
    // Queues do not support random access, so sorting requires transferring to a container
    std::vector<int> vec;
    while (!q.empty()) {
        vec.push_back(q.front());
        q.pop();
    }
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    std::cout << "\nAfter sorting in descending order: ";
    for (const auto &x : vec) {
        std::cout << x << " ";
        q.push(x);
    }

    // Numerical Algorithms
    int sum = std::accumulate(vec.begin(), vec.end(), 0); // Numerical algorithm
    std::cout << "\nSum of queue elements: " << sum;

    // Function Objects in Algorithms
    std::cout << "\nQueue elements:\n";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";
}

// Stack Demonstration
void demoStack() {
    std::stack<int> st;
    int num;
    std::cout << "\nPopulate stack<int>. Enter -1 to stop:\n";
    while (true) {
        std::cout << "Enter integer: ";
        std::cin >> num;
        if (num == -1) break;
        st.push(num);
    }

    std::cout << "\nOriginal stack (top to bottom): ";
    std::stack<int> temp = st;
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }

    // Modifying Sequence Algorithms
    // Example: Add 20 to each element
    std::stack<int> modified;
    while (!st.empty()) {
        modified.push(st.top() + 20);
        st.pop();
    }
    st = modified;
    std::cout << "\nAfter adding 20 to each element: ";
    temp = st;
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }

    // Non-Modifying Sequence Algorithms
    bool hasThirty = false;
    temp = st;
    while (!temp.empty()) {
        if (temp.top() == 30) {
            hasThirty = true;
            break;
        }
        temp.pop();
    }
    std::cout << "\nStack contains 30: " << (hasThirty ? "Yes" : "No");

    // Sorting Algorithms
    // Stacks do not support sorting directly; transfer to a vector
    std::vector<int> vec;
    while (!st.empty()) {
        vec.push_back(st.top());
        st.pop();
    }
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    std::cout << "\nAfter sorting in descending order: ";
    for (const auto &x : vec) {
        std::cout << x << " ";
        st.push(x);
    }

    // Numerical Algorithms
    int sum = std::accumulate(vec.begin(), vec.end(), 0); // Numerical algorithm
    std::cout << "\nSum of stack elements: " << sum;

    // Function Objects in Algorithms
    std::cout << "\nStack elements (top to bottom): ";
    while (!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << "\n";
}

// Priority Queue Demonstration
void demoPriorityQueue() {
    std::priority_queue<int> pq;
    int num;
    std::cout << "\nPopulate priority_queue<int>. Enter -1 to stop:\n";
    while (true) {
        std::cout << "Enter integer: ";
        std::cin >> num;
        if (num == -1) break;
        pq.push(num);
    }

    std::cout << "\nOriginal priority queue (sorted by priority): ";
    std::priority_queue<int> temp = pq;
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }

    // Modifying Sequence Algorithms
    // Example: Subtract 5 from each element
    std::priority_queue<int> modified;
    while (!pq.empty()) {
        modified.push(pq.top() - 5);
        pq.pop();
    }
    pq = modified;
    std::cout << "\nAfter subtracting 5 from each element: ";
    temp = pq;
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }

    // Non-Modifying Sequence Algorithms
    bool hasTen = false;
    temp = pq;
    while (!temp.empty()) {
        if (temp.top() == 10) {
            hasTen = true;
            break;
        }
        temp.pop();
    }
    std::cout << "\nPriority queue contains 10: " << (hasTen ? "Yes" : "No");

    // Sorting Algorithms
    // Priority queues are inherently sorted, but demonstrate by transferring to a vector
    std::vector<int> vec;
    while (!pq.empty()) {
        vec.push_back(pq.top());
        pq.pop();
    }
    std::stable_sort(vec.begin(), vec.end(), std::greater<int>());
    std::cout << "\nAfter stable sort in descending order: ";
    for (const auto &x : vec) {
        std::cout << x << " ";
        pq.push(x);
    }

    // Numerical Algorithms
    int maxVal = pq.empty() ? 0 : pq.top(); // Numerical algorithm
    std::cout << "\nMaximum element in priority queue: " << maxVal;

    // Function Objects in Algorithms
    std::cout << "\nPriority queue elements:\n";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";
}