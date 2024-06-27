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
        explicit PreOrderIterator(Node<T,N>* root) {
            if(root){ 
                stack.push(root);
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
            for (size_t i = node->getChildren().size(); i > 0; --i) {
                Node<T, N>* n = node->getChildren().at(i - 1);
                if (n != nullptr) { // Check if the child is non-null before pushing
                    stack.push(n);
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
        explicit InOrderIterator(Node<T,N>* root) {
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
                Node<T,N>* current = nodes.top();
                nodes.pop();
                if (!current->getChildren().empty()) {
                    pushLeft(current->getChildren()[1]);
                }
            }
            return *this;
        }

        Node<T, N>* operator->() const {
            return nodes.top();
        }

    private:
        stack<Node<T,N>*> nodes;

        void pushLeft(Node<T,N>* node) {
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


template <typename T,int N> class PostOrderIterator {
    public:
        explicit PostOrderIterator(Node<T,N>* root) {
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

        Node<T, N>* operator->() const {
            return nodes.top();
        }

        Node<T,N>& operator*() const {
            return *nodes.top();
        }

        PostOrderIterator& operator++(){
            if (!nodes.empty()){
                Node<T,N>* current = nodes.top();
                nodes.pop();
                if (!nodes.empty()) {
                    Node<T,N>* top = nodes.top();
                    if (!top->getChildren().empty() && top->getChildren().back() == current) {
                        nodes.pop();
                        findNextLeaf(top);
                    }
                }
            }
            return *this;
        }

    private:
        stack<Node<T,N>*> nodes;

        void findNextLeaf(Node<T,N>* node) {
            size_t j = 0;
            while(node){
                nodes.push(node);
                if (!node->getChildren().empty()){
                    for (size_t i = j; i < node->getChildren().size(); i++) {
                        node = node->getChildren().at(i);
                        break;
                    }
                    j++;
                } 
                else {
                    break;
                }
            }
        }
};


template <typename T,int N> class BFSIterator {
    public:
        explicit BFSIterator(Node<T,N>* root) {
            if (root) {
                nodes.push(root);
            }
        }

        Node<T, N>* operator->() const {
            return nodes.front();
        }

         Node<T,N>& operator*() const {
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
                Node<T,N>* current = nodes.front();
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
        queue<Node<T,N>*> nodes;
};


// template <typename T,int N> class HeapIterator {
//     public:
//         explicit HeapIterator(vector<T>::HeapIterator it = {}) : current(it) {}

//         T& operator*() {
//             return *current;
//         }

//         HeapIterator& operator++() {
//             ++current;
//             return *this;
//         }

//         bool operator!=(const HeapIterator& other) const {
//             return current != other.current;
//         }

//     private:
//         vector<T>::iterator current;
// };

    // HeapIterator begin() {
    //     return HeapIterator(heap.begin());
    // }

    // HeapIterator end() {
    //     return HeapIterator(heap.end());
    // }


#endif // ITERATORS_HPP
