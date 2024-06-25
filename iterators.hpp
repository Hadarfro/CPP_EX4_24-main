#ifndef ITERATORS_HPP
#define ITERATORS_HPP
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

template <typename T, int N>
class Tree;

using namespace std;

template <typename T,int N> class PreOrderIterator {
    public:
        explicit PreOrderIterator(Tree<T,N>* root) {
            if(root){ 
                stack.push(root->getRoot());
            }
        }

        bool operator!=(const PreOrderIterator& other) const {
            return !stack.empty();
        }

        const T& operator*() const {
            return stack.top()->value;
        }

        PreOrderIterator& operator++() {
            if (stack.empty()) {
                return *this;
            }

            Node<T, N>* node = stack.top();
            stack.pop();

            // Iterate over children and push non-null children to the stack
            for (size_t i = 0; i < node->children.size(); ++i) {
                if (node->getChildren().at(i) != nullptr) {
                    stack.push(node->getChildren()[i]);
                }
            }

            return *this;
        }

        Node<T, N>* operator->() const {
            return stack.top();
        }

    private:
        stack<Node<T,N>*> stack;
};


template <typename T,int N> class InOrderIterator {
    public:
        explicit InOrderIterator(Tree<T,N>* root) {
            pushLeft(root);
        }

        bool operator!=(const InOrderIterator& other) const {
            return !(*this == other);
        }

        bool operator==(const InOrderIterator& other) const {
            return nodes == other.nodes;
        }

        Node<T,N>& operator*() const {
            return *nodes.top();
        }

        InOrderIterator& operator++() {
            if (!nodes.empty()) {
                Node<T>* current = nodes.top();
                nodes.pop();
                if (!current->children.empty()) {
                    pushLeft(current->children[1].get());
                }
            }
            return *this;
        }

        // Node<T, N>* operator->() const {
        //     return stack.top();
        // }

    private:
        stack<Node<T,N>*> nodes;

        void pushLeft(Node<T,N>* node) {
            while (node) {
                nodes.push(node);
                if (!node->children.empty()) {
                    node = node->children[0].get();
                } 
                else {
                    break;
                }
            }
        }
};


template <typename T,int N> class PostOrderIterator {
    public:
        explicit PostOrderIterator(Tree<T,N>* root) {
            findNextLeaf(root);
        }

        bool operator!=(const PostOrderIterator& other) const {
            return !(*this == other);
        }

        bool operator==(const PostOrderIterator& other) const {
            return nodes == other.nodes;
        }

        Node<T,N>& operator*() const {
            return *nodes.top();
        }

        PostOrderIterator& operator++() {
            if (!nodes.empty()) {
                Node<T,N>* current = nodes.top();
                nodes.pop();
                if (!nodes.empty()) {
                    Node<T,N>* top = nodes.top();
                    if (!top->getChildren().empty() && top->children.back().get() == current) {
                        nodes.pop();
                        //findNextLeaf(top);
                    }
                }
            }
            return *this;
        }

    private:
        stack<Node<T,N>*> nodes;

        // void findNextLeaf(Node<T,N>* node) {
        //     while (node) {
        //         nodes.push(node);
        //         if (!node->children.empty()) {
        //             for (auto i = 0; i != node->getChildren().size(); ++i) {
        //                 if (node->getChildren().size() < N) {
        //                     node = it->get();
        //                     break;
        //                 }
        //             }
        //         } 
        //         else {
        //             break;
        //         }
        //     }
        // }
};


template <typename T,int N> class BFSIterator {
    public:
        explicit BFSIterator(Node<T,N>* root) {
            if (root) {
                nodes.push(root);
            }
        }

        BFSIterator& operator++() {
            if (!nodes.empty()) {
                Node<T,N>* current = nodes.front();
                nodes.pop();
                for (auto& child : current->children) {
                    if (child) {
                        nodes.push(child.get());
                    }
                }
            }
            return *this;
        }

    private:
        queue<Node<T,N>*> nodes;
};


template <typename T,int N> class HeapIterator {
    public:
        explicit HeapIterator(vector<T>::HeapIterator it = {}) : current(it) {}

        T& operator*() {
            return *current;
        }

        HeapIterator& operator++() {
            ++current;
            return *this;
        }

        bool operator!=(const HeapIterator& other) const {
            return current != other.current;
        }

    private:
        vector<T>::iterator current;
};

    // HeapIterator begin() {
    //     return HeapIterator(heap.begin());
    // }

    // HeapIterator end() {
    //     return HeapIterator(heap.end());
    // }


#endif // ITERATORS_HPP
