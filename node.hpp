#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Node {
    T value;
    vector<T> children;

    // Constructor to initialize the node with a value
    explicit TreeNode(const T& val, int k) : value(val), children(k) {}

    // Destructor to clean up the memory allocated for children
    ~Node() {
        for (auto child : children) {
            delete child;
        }
    }
};