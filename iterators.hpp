#include <iostream>
#include <vector>
#include <stack>
#include <queue>


using namespace std;
template <typename T,int N>
class PreOrderIterator {
    public:
        PreOrderIterator(Tree<T>* root) {
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
            Tree<T>* node = stack.top();
            stack.pop();
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                if (*it) stack.push(it->get());
            }
            return *this;
        }s

    private:
        stack<Tree<T>*> stack;
};

template <typename T>
class InOrderIterator {
public:
    InOrderIterator(Tree<T>* root) {
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
            if (!current->children.empty()) {
                pushLeft(current->children[1].get());
            }
        }
        return *this;
    }

private:
    std::stack<Node<T>*> nodes;

    void pushLeft(Node<T>* node) {
        while (node) {
            nodes.push(node);
            if (!node->children.empty()) {
                node = node->children[0].get();
            } else {
                break;
            }
        }
    }
};

template <typename T,int N>
class PostOrderIterator {
    public:
        PostOrderIterator(Tree<T>* root) {
            findNextLeaf(root);
        }

        bool operator!=(const PostOrderIterator& other) const {
            return !(*this == other);
        }

        bool operator==(const PostOrderIterator& other) const {
            return nodes == other.nodes;
        }

        Node<T>& operator*() const {
            return *nodes.top();
        }

        PostOrderIterator& operator++() {
            if (!nodes.empty()) {
                Node<T>* current = nodes.top();
                nodes.pop();
                if (!nodes.empty()) {
                    Node<T>* top = nodes.top();
                    if (!top->children.empty() && top->children.back().get() == current) {
                        nodes.pop();
                        findNextLeaf(top);
                    }
                }
            }
            return *this;
        }

    private:
        std::stack<Node<T>*> nodes;

        void findNextLeaf(Node<T>* node) {
            while (node) {
                nodes.push(node);
                if (!node->children.empty()) {
                    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                        if (*it) {
                            node = it->get();
                            break;
                        }
                    }
                } else {
                    break;
                }
            }
        }
};

template <typename T,int N>
class BFSIterator {
    public:
        BFSIterator(Node<T>* root) {
            if (root) {
                nodes.push(root);
            }
        }

        bool operator!=(const BFSIterator& other) const {
            return !(*this == other);
        }

        bool operator==(const BFSIterator& other) const {
            return nodes == other.nodes;
        }

        Node<T>& operator*() const {
            return *nodes.front();
        }

        BFSIterator& operator++() {
            if (!nodes.empty()) {
                Node<T>* current = nodes.front();
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
        queue<Node<T>*> nodes;
};

