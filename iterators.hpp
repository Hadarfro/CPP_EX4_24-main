#include <iostream>
#include <vector>

template <typename T>
class PreOrderIterator {
public:
    explicit PreOrderIterator(TreeNode<T>* root) {
        if (root) stack.push(root);
    }

    bool operator!=(const PreOrderIterator& other) const {
        return !stack.empty();
    }

    const T& operator*() const {
        return stack.top()->value;
    }

    PreOrderIterator& operator++() {
        TreeNode<T>* node = stack.top();
        stack.pop();
        for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
            if (*it) stack.push(it->get());
        }
        return *this;
    }

private:
    std::stack<TreeNode<T>*> stack;
};
