#include "ContainerDemo.h"

#include <iostream>
#include <string>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm> // for sort, etc.

using namespace std;

//----------------- Sequence Containers -----------------//

void demoArray() {
    array<string, 5> arr;
    cout << "\nPopulate array<string, 5> with up to 5 items:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Enter item #" << (i + 1) << ": ";
        cin >> arr[i];
    }
    cout << "\nContents of array:\n";
    for (const auto &item : arr) {
        cout << item << " ";
    }
    cout << "\n";
    swap(arr[0], arr[4]);
    cout << "After swapping first and last elements:\n";
    for (const auto &item : arr) {
        cout << item << " ";
    }
    cout << "\n";
}

void demoDeque() {
    deque<int> d;
    cout << "\nPopulate deque<int> with some integer values. Enter -1 to stop:\n";
    while (true) {
        cout << "Enter an integer: ";
        int val = 0;
        cin >> val;
        if (!cin.fail() && val != -1) {
            d.push_back(val);
        } else {
            break;
        }
    }
    if (!d.empty()) {
        cout << "\nAdding 999 to the front...\n";
        d.push_front(999);
        cout << "Removing the last element...\n";
        d.pop_back();
    }
    deque<int> temp = d;
    sort(temp.begin(), temp.end());
    cout << "\nSorted copy of deque:\n";
    for (auto &x : temp) {
        cout << x << " ";
    }
    cout << "\n";
    cout << "Actual contents in deque:\n";
    for (auto &x : d) {
        cout << x << " ";
    }
    cout << "\n";
}

void demoForwardList() {
    forward_list<string> fl;
    cout << "\nPopulate forward_list<string>. Enter 'stop' to stop:\n";
    while (true) {
        cout << "Enter a string: ";
        string s;
        cin >> s;
        if (s == "stop") {
            break;
        }
        fl.push_front(s);
    }
    fl.reverse();
    fl.sort();
    cout << "\nAfter reverse and sort, forward_list contents:\n";
    for (auto &item : fl) {
        cout << item << " ";
    }
    cout << "\n";
}

void demoList() {
    list<int> lst;
    cout << "\nPopulate list<int> with some integers. Enter -1 to stop:\n";
    while (true) {
        cout << "Enter an integer: ";
        int val = 0;
        cin >> val;
        if (!cin.fail() && val != -1) {
            lst.push_back(val);
        } else {
            break;
        }
    }
    lst.sort();
    lst.unique();
    cout << "\nlist<int> after sort and unique:\n";
    for (auto &x : lst) {
        cout << x << " ";
    }
    cout << "\n";
}

void demoVector() {
    vector<string> vec;
    cout << "\nPopulate vector<string>. Enter 'stop' to stop:\n";
    while (true) {
        cout << "Enter a string: ";
        string s;
        cin >> s;
        if (s == "stop") {
            break;
        }
        vec.push_back(s);
    }
    sort(vec.begin(), vec.end());
    auto it = unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());
    cout << "\nvector<string> after sort and removing duplicates:\n";
    for (auto &x : vec) {
        cout << x << " ";
    }
    cout << "\n";
}

//----------------- Ordered Associative Containers -----------------//

void demoSet() {
    set<int> st;
    cout << "\nPopulate set<int>. Enter -1 to stop:\n";
    while (true) {
        cout << "Enter an integer: ";
        int val;
        cin >> val;
        if (!cin.fail() && val != -1) {
            st.insert(val);
        } else {
            break;
        }
    }
    cout << "\nset<int> contents (sorted automatically):\n";
    for (auto &x : st) {
        cout << x << " ";
    }
    cout << "\n";
    cout << "Enter an integer to erase from set: ";
    int toErase;
    cin >> toErase;
    st.erase(toErase);
    cout << "After erase:\n";
    for (auto &x : st) {
        cout << x << " ";
    }
    cout << "\n";
}

void demoMultiset() {
    multiset<string> ms;
    cout << "\nPopulate multiset<string>. Enter 'stop' to stop:\n";
    while (true) {
        cout << "Enter a string: ";
        string s;
        cin >> s;
        if (s == "stop") {
            break;
        }
        ms.insert(s);
    }
    cout << "\nmultiset<string> contents:\n";
    for (auto &x : ms) {
        cout << x << " ";
    }
    cout << "\n";
    cout << "Enter a string to count in multiset: ";
    string target;
    cin >> target;
    cout << "Count of '" << target << "' = " << ms.count(target) << "\n";
}

void demoMap() {
    map<string, int> mp;
    cout << "\nPopulate map<string,int>. Enter 'stop' as key to stop.\n";
    while (true) {
        cout << "Enter key (string): ";
        string key;
        cin >> key;
        if (key == "stop") {
            break;
        }
        cout << "Enter value (int): ";
        int val;
        cin >> val;
        mp[key] = val;
    }
    cout << "\nmap<string,int> contents:\n";
    for (auto &kv : mp) {
        cout << kv.first << " -> " << kv.second << "\n";
    }
    cout << "\nEnter key to find in map: ";
    string look;
    cin >> look;
    auto it = mp.find(look);
    if (it != mp.end()) {
        cout << "Found key '" << look << "' with value " << it->second << "\n";
    } else {
        cout << "Key '" << look << "' not found.\n";
    }
}

void demoMultimap() {
    multimap<int, string> mm;
    cout << "\nPopulate multimap<int,string>. Enter negative key to stop.\n";
    while (true) {
        cout << "Enter key (int): ";
        int key;
        cin >> key;
        if (key < 0) {
            break;
        }
        cout << "Enter value (string): ";
        string val;
        cin >> val;
        mm.insert({key, val});
    }
    cout << "\nmultimap<int,string> contents:\n";
    for (auto &p : mm) {
        cout << p.first << " -> " << p.second << "\n";
    }
    cout << "\nEnter key to see range in multimap: ";
    int k;
    cin >> k;
    auto range = mm.equal_range(k);
    cout << "Entries with key " << k << ":\n";
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << " -> " << it->second << "\n";
    }
}

//----------------- Unordered Associative Containers -----------------//

void demoUnorderedSet() {
    unordered_set<int> uset;
    cout << "\nPopulate unordered_set<int>. Enter -1 to stop:\n";
    while (true) {
        cout << "Enter an integer: ";
        int val;
        cin >> val;
        if (!cin.fail() && val != -1) {
            uset.insert(val);
        } else {
            break;
        }
    }
    cout << "\nunordered_set<int> contents:\n";
    for (auto &x : uset) {
        cout << x << " ";
    }
    cout << "\n";
    cout << "Rehashing to bucket_count=23.\n";
    uset.rehash(23);
    cout << "Bucket count now: " << uset.bucket_count() << "\n";
}

void demoUnorderedMultiset() {
    unordered_multiset<string> ums;
    cout << "\nPopulate unordered_multiset<string>. Enter 'stop' to stop:\n";
    while (true) {
        cout << "Enter a string: ";
        string s;
        cin >> s;
        if (s == "stop") {
            break;
        }
        ums.insert(s);
    }
    cout << "\nunordered_multiset<string> contents:\n";
    for (auto &x : ums) {
        cout << x << " ";
    }
    cout << "\n";
    cout << "Enter a string to count: ";
    string t;
    cin >> t;
    cout << "Count of '" << t << "': " << ums.count(t) << "\n";
}

void demoUnorderedMap() {
    unordered_map<string, int> um;
    cout << "\nPopulate unordered_map<string,int>. Enter 'stop' as key to stop.\n";
    while (true) {
        cout << "Enter key (string): ";
        string key;
        cin >> key;
        if (key == "stop") {
            break;
        }
        cout << "Enter value (int): ";
        int val;
        cin >> val;
        um[key] = val;
    }
    cout << "\nunordered_map<string,int> contents:\n";
    for (auto &kv : um) {
        cout << kv.first << " -> " << kv.second << "\n";
    }
    cout << "\nCurrent number of buckets: " << um.bucket_count() << "\n";
}

void demoUnorderedMultimap() {
    unordered_multimap<int, string> umm;
    cout << "\nPopulate unordered_multimap<int,string>. Enter negative key to stop.\n";
    while (true) {
        cout << "Enter key (int): ";
        int key;
        cin >> key;
        if (key < 0) {
            break;
        }
        cout << "Enter value (string): ";
        string val;
        cin >> val;
        umm.insert({key, val});
    }
    cout << "\nunordered_multimap<int,string> contents:\n";
    for (auto &p : umm) {
        cout << p.first << " -> " << p.second << "\n";
    }
    cout << "\nEnter key to see how many entries exist: ";
    int look;
    cin >> look;
    cout << "Count of key " << look << ": " << umm.count(look) << "\n";
}

//----------------- Container Adapters -----------------//

void demoStack() {
    stack<int> st;
    cout << "\nPopulate stack<int>. Enter -1 to stop:\n";
    while (true) {
        cout << "Enter an integer: ";
        int val;
        cin >> val;
        if (!cin.fail() && val != -1) {
            st.push(val);
        } else {
            break;
        }
    }
    cout << "\nStack top elements pop demonstration:\n";
    while (!st.empty()) {
        cout << "Top: " << st.top() << " -> popping it...\n";
        st.pop();
    }
}

void demoQueue() {
    queue<string> q;
    cout << "\nPopulate queue<string>. Enter 'stop' to stop:\n";
    while (true) {
        cout << "Enter a string: ";
        string s;
        cin >> s;
        if (s == "stop") {
            break;
        }
        q.push(s);
    }
    cout << "\nQueue front/pop demonstration:\n";
    while (!q.empty()) {
        cout << "Front: " << q.front() 
             << "  (queue size: " << q.size() << ") -> popping it...\n";
        q.pop();
    }
}

void demoPriorityQueue() {
    priority_queue<int> pq;
    cout << "\nPopulate priority_queue<int>. Enter -1 to stop:\n";
    while (true) {
        cout << "Enter an integer: ";
        int val;
        cin >> val;
        if (!cin.fail() && val != -1) {
            pq.push(val);
        } else {
            break;
        }
    }
    cout << "\npriority_queue<int> pop demonstration:\n";
    while (!pq.empty()) {
        cout << "Top: " << pq.top() << " -> popping...\n";
        pq.pop();
    }
}