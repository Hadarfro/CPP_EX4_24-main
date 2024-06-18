#include <iostream>
#include <vector>
#include "node.hpp"
#include "iterators.hpp"

template <typename T,int N = 2>
class Tree {
    public:
        Tree(int k = 2) : maxChildren(k), root(nullptr) {}

        void add_root(Node node) {
            root = Node<T,N>*(node, maxChildren);
        }
        Node<T,N> getRoot(){
            return root[0];
        } 
        class BFSIterator;
        BFSIterator begin() { return BFSIterator(root.get()); }
        BFSIterator end() { return BFSIterator(nullptr); }
        void add_sub_node(Node<T,N>& parent_node, Node<T,N>& child_node));
        Node<T,N>* find_node(Node<T,N>* node, const T& value);
        PreOrderIterator begin_pre_order() {
            return PreOrderIterator(root.get());
        }
        PreOrderIterator end_pre_order() {
            return PreOrderIterator(nullptr);
        }
        PostOrderIterator begin_post_order() {
            return PostOrderIterator(root.get());
        }
        PostOrderIterator end_post_order() {
            return PostOrderIterator(nullptr);
        }
        InOrderIterator begin_in_order() {
            return InOrderIterator(root.get());
        }
        InOrderIterator end_in_order() {
            return InOrderIterator(nullptr);
        }
        BFSIterator begin_bfs_scan() {
            return BFSIterator(root.get());
        }
        BFSIterator end_bfs_scan() {
            return BFSIterator(nullptr);
        }
        // Define iterators and traversal methods here...

    private:
        int maxChildren;
        Node<T>* root;
};
