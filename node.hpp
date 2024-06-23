#include <iostream>
#include <vector>
#ifndef NODE_HPP
#define NODE_HPP

using namespace std;


template<typename T,int N = 2> class Node {
    private:
        T value;
        int maxChild;
        vector<Node> children;
    public:
        // Constructor to initialize the node with a value
        Node(const T& val, vector<Node> k = {}) : value(val), children(k), maxChild(N) {
            children.resize(2);
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

#endif // NODE_HPP