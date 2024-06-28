#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <vector>
#include <memory>
#include "node.hpp"
#include "iterators.hpp"


template <typename T> class Tree {
    public:
        Tree(int k = 2) : maxChildren(k), root(nullptr) {}

        void add_root(Node<T>* node) {
             if (root) {
                cerr << "Tree already has a root." << endl;
            } 
            else {
                root = node;
            }
        }
        Node<T>* getRoot(){
            return root;
        } 
        //class BFSIterator;
        BFSIterator<T> begin() { return BFSIterator<T>(root); }
        BFSIterator<T> end() { return BFSIterator<T>(nullptr); }
        void add_sub_node(Node<T>& parent_node, Node<T>& child_node) {
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
            if(parent_node.getChildren().size() < maxChildren) {
                parent_node.addChild(&child_node);
                return;
            }
            cout << "Parent has the maximum number of children" << endl;
            return;
            //throw runtime_error("Parent has the maximum number of children");
        }
        Node<T>* find_node(Node<T>* node, T value);
        PreOrderIterator<T> begin_pre_order() {
            return PreOrderIterator<T>(root);
        }
        PreOrderIterator<T> end_pre_order() {
            return PreOrderIterator<T>(nullptr);
        }
        PostOrderIterator<T> begin_post_order() {
            return PostOrderIterator<T>(root);
        }
        PostOrderIterator<T> end_post_order() {
            return PostOrderIterator<T>(nullptr);
        }
        InOrderIterator<T> begin_in_order() {
            return InOrderIterator<T>(root);
        }
        InOrderIterator<T> end_in_order() {
            return InOrderIterator<T>(nullptr);
        }
        BFSIterator<T> begin_bfs_scan() {
            return BFSIterator<T>(root);
        }
        BFSIterator<T> end_bfs_scan() {
            return BFSIterator<T>(nullptr);
        }

    private:
        int maxChildren;
        //Node<T,N>* root;
        Node<T>* root;
};

#endif // TREE_HPP
