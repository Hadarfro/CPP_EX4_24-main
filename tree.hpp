#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <vector>
#include <memory>
#include "node.hpp"
#include "iterators.hpp"


template <typename T,int N = 2> class Tree {
    public:
        Tree() : maxChildren(N), root(nullptr) {}

        void add_root(Node<T,N>* node) {
            root = node;
        }
        Node<T,N>* getRoot(){
            return root;
        } 
        //class BFSIterator;
        BFSIterator<T,N> begin() { return BFSIterator<T,N>(root); }
        BFSIterator<T,N> end() { return BFSIterator<T,N>(nullptr); }
        void add_sub_node(Node<T,N>& parent_node, Node<T,N>& child_node) {
            // Check if child node has the same arity as parent
            // Node<T,N>* parent = find_node(root, parent_node->get_value());
            // if (parent->getChildren().size() > N) {
            //     throw runtime_error("Parent node arity mismatch");
            //     return;
            // }
            // if (!parent){ 
            //     throw runtime_error("Parent node not found");
            //     return;
            // }
            if(parent_node.getChildren().size() < N) {
                parent_node.addChild(&child_node);
                return;
            }
            cout << "Parent has the maximum number of children" << endl;
            return;
            //throw runtime_error("Parent has the maximum number of children");
        }
        Node<T,N>* find_node(Node<T,N>* node, T value);
        PreOrderIterator<T, N> begin_pre_order() {
            return PreOrderIterator<T, N>(root);
        }
        PreOrderIterator<T, N> end_pre_order() {
            return PreOrderIterator<T, N>(nullptr);
        }
        PostOrderIterator<T, N> begin_post_order() {
            return PostOrderIterator<T, N>(root);
        }
        PostOrderIterator<T, N> end_post_order() {
            return PostOrderIterator<T, N>(nullptr);
        }
        InOrderIterator<T, N> begin_in_order() {
            return InOrderIterator<T, N>(root);
        }
        InOrderIterator<T, N> end_in_order() {
            return InOrderIterator<T, N>(nullptr);
        }
        BFSIterator<T,N> begin_bfs_scan() {
            return BFSIterator<T,N>(root);
        }
        BFSIterator<T,N> end_bfs_scan() {
            return BFSIterator<T,N>(nullptr);
        }

    private:
        int maxChildren;
        //Node<T,N>* root;
        Node<T, N>* root;
};

#endif // TREE_HPP
