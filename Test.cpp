#include "doctest.hpp"
#include "tree.hpp"
#include "node.hpp"
#include "iterators.hpp"


/*
 * Author: Hadar Froimowich.
 * ID: 213118458
 * Email: hadarfro12@gmail.com
 */

using namespace std;
using namespace doctest;


TEST_CASE("Test PreOrderIterator") {
    Node<int> root(1);
    Node<int> node1(2);
    Node<int> node2(3);
    Node<int> node3(4);
    Node<int> node4(5);
    Node<int> node5(6);

    Tree<int> tree(3);
    tree.add_root(&root);
    tree.add_sub_node(root, node1);
    tree.add_sub_node(root, node2);
    tree.add_sub_node(node1, node3);
    tree.add_sub_node(node1, node4);
    tree.add_sub_node(node2, node5);

    SUBCASE("Pre-order Traversal") {
        vector<int> values;
        for (auto it = PreOrderIterator<int>(&root); it != PreOrderIterator<int>(nullptr); ++it) {
            values.push_back(it->get_value());
        }
        vector<int> expected = {1, 2, 4, 5, 3, 6};
        CHECK(values == expected);
    }
}

TEST_CASE("Test InOrderIterator") {
    Node<int> root(1);
    Node<int> node1(2);
    Node<int> node2(3);
    Node<int> node3(4);
    Node<int> node4(5);
    Node<int> node5(6);

    Tree<int> tree(3);
    tree.add_root(&root);
    tree.add_sub_node(root, node1);
    tree.add_sub_node(root, node2);
    tree.add_sub_node(node1, node3);
    tree.add_sub_node(node1, node4);
    tree.add_sub_node(node2, node5);

    SUBCASE("In-order Traversal") {
        vector<int> values;
        for (auto it = InOrderIterator<int>(&root); it != InOrderIterator<int>(nullptr); ++it) {
            values.push_back(it->get_value());
        }
        vector<int> expected = {4, 2, 5, 1, 3, 6};
        CHECK(values == expected);
    }
}

TEST_CASE("Test PostOrderIterator") {
    Node<int> root(1);
    Node<int> node1(2);
    Node<int> node2(3);
    Node<int> node3(4);
    Node<int> node4(5);
    Node<int> node5(6);

    Tree<int> tree(3);
    tree.add_root(&root);
    tree.add_sub_node(root, node1);
    tree.add_sub_node(root, node2);
    tree.add_sub_node(node1, node3);
    tree.add_sub_node(node1, node4);
    tree.add_sub_node(node2, node5);

    SUBCASE("Post-order Traversal") {
        vector<int> values;
        for (auto it = PostOrderIterator<int>(&root); it != PostOrderIterator<int>(nullptr); ++it) {
            values.push_back(it->get_value());
        }
        vector<int> expected = {4, 5, 2, 6, 3, 1};
        CHECK(values == expected);
    }
}

TEST_CASE("Test BFSIterator") {
    Node<int> root(1);
    Node<int> node1(2);
    Node<int> node2(3);
    Node<int> node3(4);
    Node<int> node4(5);
    Node<int> node5(6);

    Tree<int> tree(3);
    tree.add_root(&root);
    tree.add_sub_node(root, node1);
    tree.add_sub_node(root, node2);
    tree.add_sub_node(node1, node3);
    tree.add_sub_node(node1, node4);
    tree.add_sub_node(node2, node5);

    SUBCASE("Breadth-first Traversal") {
        vector<int> values;
        for (auto it = BFSIterator<int>(&root); it != BFSIterator<int>(nullptr); ++it) {
            values.push_back(it->get_value());
        }
        vector<int> expected = {1, 2, 3, 4, 5, 6};
        CHECK(values == expected);
    }
}

// TEST_CASE("Test DFSIterator") {
//     Node<int> root(1);
//     Node<int> node1(2);
//     Node<int> node2(3);
//     Node<int> node3(4);
//     Node<int> node4(5);
//     Node<int> node5(6);

//     Tree<int> tree(3);
//     tree.add_root(&root);
//     tree.add_sub_node(root, node1);
//     tree.add_sub_node(root, node2);
//     tree.add_sub_node(node1, node3);
//     tree.add_sub_node(node1, node4);
//     tree.add_sub_node(node2, node5);

//     SUBCASE("Depth-first Traversal") {
//         vector<int> values;
//         for (auto it = DFSIterator<int>(&root); it != DFSIterator<int>(nullptr); ++it) {
//             values.push_back(it->get_value());
//         }
//         vector<int> expected = {1, 2, 4, 5, 3, 6};
//         CHECK(values == expected);
//     }
// }


