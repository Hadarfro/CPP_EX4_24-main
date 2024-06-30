#include <iostream>
#include <vector>
#include "tree.hpp"
#include "node.hpp"

using namespace std;

template <typename T>
Node<T>* Tree<T>::find_node(Node<T>* node, T value) {
    if (!node){
     return nullptr;
    }
    if (node->value == value){
        return node;
    }
    for (auto& child : node->getChildren()) {
        Node<T>* found = find_node(child.get(), value);
        if (found){
            return found;
        } 
    }
    return nullptr;
}
