#include <iostream>
#include <vector>


template <typename T>
class Tree {
public:
    explicit Tree(int k = 2) : maxChildren(k), root(nullptr) {}

    void add_root(const T& value) {
        root = Node<T>*(value, maxChildren);
    }

    void add_sub_node(const T& parent_value, const T& child_value) {
        Node<T>* parent = find_node(root.get(), parent_value);
        if (!parent) throw std::runtime_error("Parent node not found");
        for (auto& child : parent->children) {
            if (!child) {
                child = Node<T>*(child_value, maxChildren);
                return;
            }
        }
        throw std::runtime_error("Parent has the maximum number of children");
    }

    // Define iterators and traversal methods here...

private:
    int maxChildren;
    Node<T>* root;

    Node<T>* find_node(Node<T>* node, const T& value) {
        if (!node) return nullptr;
        if (node->value == value) return node;
        for (auto& child : node->children) {
            Node<T>* found = find_node(child.get(), value);
            if (found) return found;
        }
        return nullptr;
    }
};
