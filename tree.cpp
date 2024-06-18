#include <iostream>
#include <vector>
#include "tree.hpp"
#include "node.hpp"

using namespace std;

template <typename T, int N >
void Tree<T,N>::add_sub_node(Node<T,N>& parent_node, Node<T,N>& child_node) {
    // Check if child node has the same arity as parent
    if (parent->children.size() > N) {
        throw std::runtime_error("Parent node arity mismatch");
    }
    Node <T,N>* parent = find_node(root.get(), parent_value);
    if (!parent){ 
        throw std::runtime_error("Parent node not found");
    }
    for (auto& child : parent->children) {
        if (!child) {
            child = Node<T,N>*(child_value, maxChildren);
            return;
        }
    }
    throw std::runtime_error("Parent has the maximum number of children");
}

template <typename T,int N >
Node<T,N>* Tree<T,N>::find_node(Node<T,N>* node, const T& value) {
    if (!node) return nullptr;
    if (node->value == value) return node;
    for (auto& child : node->children) {
        Node<T>* found = find_node(child.get(), value);
        if (found) return found;
    }
    return nullptr;
}
