/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"

using namespace std;

int main()
{
    Node<double,2> root_node(1.1);
    Tree<double,2> tree; // Binary tree that contains doubles.
    tree.add_root(&root_node); // problem!!!!
    Node<double,2> n1(1.2);
    Node<double,2> n2(1.3);
    Node<double,2> n3(1.4);
    Node<double,2> n4(1.5);
    Node<double,2> n5(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
   
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    cout << "pre order:" << endl; 

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    cout << "post order:" << endl;

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;
    cout << "in order:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;
    cout << "BFS:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;
    cout << "regular:" << endl;
    for (auto node : tree){
        cout << node.get_value() << "  ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;
    //cout << tree; // Should print the graph using GUI.

    // Tree<double,3> three_ary_tree; // 3-ary tree.
    // three_ary_tree.add_root(&root_node);
    // three_ary_tree.add_sub_node(root_node, n1);
    // three_ary_tree.add_sub_node(root_node, n2);
    // three_ary_tree.add_sub_node(root_node, n3);
    // three_ary_tree.add_sub_node(n1, n4);
    // three_ary_tree.add_sub_node(n2, n5);

     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
    return 1;
}
