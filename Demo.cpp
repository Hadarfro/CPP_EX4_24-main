/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include "complex.hpp"

using namespace std;

int main(){
    Complex root_value(1.1, 2);
    Node<Complex> root_node(root_value);
    Tree<Complex> tree; // Binary tree that contains Complex numbers.
    tree.add_root(&root_node);
    
    Node<Complex> n1(Complex(1.2, 3));
    Node<Complex> n2(Complex(1.3, 5.2));
    Node<Complex> n3(Complex(1.4, 7.0));
    Node<Complex> n4(Complex(1.5, 3.9));
    Node<Complex> n5(Complex(1.6, 4.1));

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
    } // prints: 
    cout << endl;

    cout << "post order:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 
    cout << endl;
    cout << "in order:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 
    cout << endl;
    cout << "BFS:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 
    cout << endl;
    cout << "regular:" << endl;
    for (auto node : tree){
        cout << node.get_value() << "  ";
    } // same as BFS: 
    cout << endl;
    cout << endl;
    //cout << tree; // Should print the graph using GUI.

    Node<int> root(10);
    Node<int> node1(20);
    Node<int> node2(30);
    Node<int> node3(40);
    Node<int> node4(50);
    Node<int> node5(60);
    Node<int> node6(70);
    Node<int> node7(80);

    Tree<int> three_ary_tree(3); // N-ary tree with up to 3 children per node.
    three_ary_tree.add_root(&root);
    three_ary_tree.add_sub_node(root, node1);
    three_ary_tree.add_sub_node(root, node2);
    three_ary_tree.add_sub_node(root, node3);
    three_ary_tree.add_sub_node(node1, node4);
    three_ary_tree.add_sub_node(node1, node5);
    three_ary_tree.add_sub_node(node2, node6);
    three_ary_tree.add_sub_node(node3, node7);

    cout << "pre order:" << endl; 

    for (auto node = three_ary_tree.begin_pre_order(); node != three_ary_tree.end_pre_order(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    cout << "post order:" << endl;
    for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;

    cout << "in order:" << endl;
    for (auto node = three_ary_tree.begin_in_order(); node != three_ary_tree.end_in_order(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;

    cout << "BFS:" << endl;
    for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;
    
    cout << "regular:" << endl;
    for (auto node : three_ary_tree){
        cout << node.get_value() << "  ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;
    cout << endl;

    return 1;
}
