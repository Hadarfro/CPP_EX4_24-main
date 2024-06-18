#include <iostream>
#include <vector>

using namespace std;

template<typename T,int N = 2>
struct Node {
    T value;
    vector<T> children;

    // Constructor to initialize the node with a value
    Node(const T& val, vector<T> k = {}) : value(val), children(k) {
        children.resize(N);
    }

    // Destructor to clean up the memory allocated for children
    ~Node() {
        if (children.size > 0){
            for (auto child : children) {
                delete child;
            }
        }
    }
};