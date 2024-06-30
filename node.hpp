#include <iostream>
#include <vector>
#ifndef NODE_HPP
#define NODE_HPP


using namespace std;


template<typename T> class Node {
    private:
        T value;
        int maxChild;
        vector<Node<T>*> children;
    public:
        // Constructor to initialize the node with a value
        explicit Node(T val, vector<Node<T>*> k = {},int maxC = 2) : value(val), children(k), maxChild(maxC) {
        }

        T get_value(){
            return value;
        }

        vector<Node<T>*>& getChildren(){
            return children;
        }

        void addChild(Node<T>* node){
            //if(children.size() < maxChild){
                children.push_back(node);
            // }
            //  else {
            //     cerr << "Node cannot have more than " << maxChild << " children." << std::endl;
            // }
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