#include <iostream>
#include <vector>
#ifndef NODE_HPP
#define NODE_HPP

using namespace std;


template<typename T,int N = 2> class Node {
    private:
        T value;
        int maxChild;
        vector<Node<T,N>> children;
    public:
        // Constructor to initialize the node with a value
        explicit Node(T val, vector<Node<T,N>> k = {}) : value(val), children(k), maxChild(N) {
            //children.resize(2);
        }

        T get_value(){
            return value;
        }

        vector<Node<T,N>> getChildren(){
            return children;
        }

        void addChild(Node<T,N> node){
            if(children.size()<maxChild){
                children.push_back(node);
            }
        }

        // Destructor to clean up the memory allocated for children
        // ~Node() {
        //     if (children.size > 0){
        //         for (auto child : children) {
        //             delete child;
        //         }
        //     }
        // }
};

#endif // NODE_HPP