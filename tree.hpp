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
                throw runtime_error("Tree already has a root");
            } 
            else {
                root = node;
            }
        }
        Node<T>* getRoot(){
            return root;
        } 
        void add_sub_node(Node<T>& parent_node, Node<T>& child_node) {
            if(parent_node.getChildren().size() < maxChildren) {
                parent_node.addChild(&child_node);
                return;
            }
            throw runtime_error("Parent has the maximum number of children");
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
        DFSIterator<T> begin_dfs_scan() { 
            return DFSIterator<T>(root); 
        }
        DFSIterator<T> end_dfs_scan() { 
            return DFSIterator<T>(nullptr); 
        }

        void myHeap(){
            if (!root) {
                return;
            }
            queue<Node<T>*> queue;
            queue.push(root);
            while(!queue.empty()){
                auto node = queue.front();
                queue.pop();
                heapify(node);
                for(auto child : node->getChildren()){
                    queue.push(child);
                }
            }
        }

    private:
        int maxChildren;
        Node<T>* root;
};

#endif // TREE_HPP
