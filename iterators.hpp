#ifndef ITERATORS_HPP
#define ITERATORS_HPP
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <iterator>
#include <memory>
#include <algorithm>

template <typename T>
class Tree;

using namespace std;

template <typename T> class PreOrderIterator {
    public:
        explicit PreOrderIterator(Node<T>* root) {
            if(root){ 
                stack.push(root);
            }
        }

        bool operator!=(const PreOrderIterator& other) const {
            return !stack.empty();
        }

        PreOrderIterator& operator++() {
            if (stack.empty()) {
                return *this;
            }
            
            Node<T>* node = stack.top();
            stack.pop();
            // Iterate over children and push non-null children to the stack
            for (size_t i = node->getChildren().size(); i > 0; --i) {
                Node<T>* n = node->getChildren().at(i - 1);
                if (n != nullptr) { // Check if the child is non-null before pushing
                    stack.push(n);
                }
            }
            return *this;
        }

        Node<T>* operator->() const {
            return stack.top();
        }

    private:
        stack<Node<T>*> stack;
};


template <typename T> class InOrderIterator {
    public:
        explicit InOrderIterator(Node<T>* root) {
            pushLeft(root);
        }

        bool operator!=(const InOrderIterator& other) const {
            return !(*this == other);
        }

        bool operator==(const InOrderIterator& other) const {
            return nodes == other.nodes;
        }

        Node<T>& operator*() const {
            return *nodes.top();
        }

        InOrderIterator& operator++() {
            if (!nodes.empty()) {
                Node<T>* current = nodes.top();
                nodes.pop();
                if (!current->getChildren().empty()) {
                    pushLeft(current->getChildren()[1]);
                }
            }
            return *this;
        }

        Node<T>* operator->() const {
            return nodes.top();
        }

    private:
        stack<Node<T>*> nodes;

        void pushLeft(Node<T>* node) {
            while (node) {
                nodes.push(node);
                if (!node->getChildren().empty()) {
                    node = node->getChildren()[0];
                } 
                else {
                    break;
                }
            }
        }
};


template <typename T> class PostOrderIterator {
    public:
        explicit PostOrderIterator(Node<T>* root) {
            if (root) {
                findNextLeaf(root);
            }
        }

        bool operator!=(const PostOrderIterator& other) const {
            return !(*this == other);
        }

        bool operator==(const PostOrderIterator& other) const {
            return nodes == other.nodes;
        }

        Node<T>* operator->() const {
            return nodes.top();
        }

        Node<T>& operator*() const {
            return *nodes.top();
        }

        PostOrderIterator& operator++(){
            if (!nodes.empty()) {
                Node<T>* current = nodes.top();
                nodes.pop();
                if (!nodes.empty()) {
                    Node<T>* parent = nodes.top();
                    if (!parent->getChildren().empty() && parent->getChildren().back() == current) {
                        nodes.pop();
                        findNextLeaf(parent);
                    }
                }
            }
            return *this;
        }

    private:
        stack<Node<T>*> nodes;

        void findNextLeaf(Node<T>* node) {
            while (node) {
                nodes.push(node);
                if (!node->getChildren().empty()) {
                    // Push all children onto the stack in reverse order
                    vector<Node<T>*> children = node->getChildren();
                    for (size_t i = 0;i < node->getChildren().size();i++) {
                        if (node->getChildren().at(i)) {
                            nodes.push(node->getChildren().at(i));
                        }
                    }
                    node = children.front(); // move to the first child
                } 
                else {
                    break;
                }
            }
        }
};


template <typename T> class BFSIterator {
    public:
        explicit BFSIterator(Node<T>* root) {
            if (root) {
                nodes.push(root);
            }
        }

        Node<T>* operator->() const {
            return nodes.front();
        }

         Node<T>& operator*() const {
            return *nodes.front();
        }

        bool operator!=(const BFSIterator& other) const {
            return !(*this == other);
        }

        bool operator==(const BFSIterator& other) const {
            return nodes == other.nodes;
        }

        BFSIterator& operator++() {
            if (!nodes.empty()) {
                Node<T>* current = nodes.front();
                nodes.pop();
                for (auto& child : current->getChildren()) {
                    if (child) {
                        nodes.push(child);
                    }
                }
            }
            return *this;
        }

    private:
        queue<Node<T>*> nodes;
};

// template <typename T>
// class DFSIterator {
//     public:
//         explicit DFSIterator(Node<T>* root) {
//             if (root) {
//                 nodes.push(root);
//             }
//         }

//         Node<T>* operator->() const {
//             return nodes.top();
//         }

//         Node<T>& operator*() const {
//             return *nodes.top();
//         }

//         bool operator!=(const DFSIterator& other) const {
//             return !(*this == other);
//         }

//         bool operator==(const DFSIterator& other) const {
//             return nodes == other.nodes;
//         }

//         DFSIterator& operator++() {
//             if (!nodes.empty()) {
//                 Node<T>* current = nodes.top();
//                 nodes.pop();
//                 for (const auto& it = current->getChildren().rbegin(); it != current->getChildren().rend(); ++it) {
//                     if (*it) {
//                         nodes.push(*it);
//                     }
//                 }
//             }
//             return *this;
//         }

//     private:
//         stack<Node<T>*> nodes;
// };


// template <typename T>
// void myHeap(){
//     if (!root) {
//         return;
//     }
//     queue<Node<T>*> queue;
//     queue.push(root);
//     while(!queue.empty()){
//         auto node = queue.front();
//         queue.pop();
//         heapify(node);
//         for(auto child : node->children){
//             queue.push(child);
//         }
//     }
//}

#endif // ITERATORS_HPP
