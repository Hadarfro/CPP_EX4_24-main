#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "tree.hpp"


// Function to create a sample tree
template <typename T>
Tree<T> createSampleTree() {
    Node<double> root_node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(&root_node);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    
    return tree;
}

template <typename T>
void drawTree(sf::RenderWindow& window, Node<T>* node, sf::Font& font, sf::Vector2f position, float levelSpacing, float siblingSpacing) {
    if (!node){ 
        return;
    }

    // Draw node circle
    sf::CircleShape circle(50.f);
    circle.setOutlineThickness(2.f);
    circle.setOutlineColor(sf::Color::Black);
    circle.setFillColor(sf::Color::White);
    circle.setPosition(position.x - circle.getRadius(), position.y - circle.getRadius());
    window.draw(circle);

    // Draw node value as text
    sf::Text text(to_string(node->get_value()), font, 20);
    text.setFillColor(sf::Color::Black);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.f);
    text.setPosition(position);
    window.draw(text);

    // Draw edges to children and position children nodes
    vector<Node<T>*> children = node->getChildren();//problem!!!!!!!!!!!!!!!!!!!!
    if (!children.empty()) {
        sf::Vector2f childPosition = position;
        childPosition.y += levelSpacing;
        childPosition.x -= siblingSpacing * (children.size() - 1) / 2.f;

        for (auto* child : children) {
            sf::Vertex line[] = {
                sf::Vertex(position),
                sf::Vertex(childPosition)
            };
            window.draw(line, 2, sf::Lines);

            // Recursively draw child nodes
            drawTree(window, child, font, childPosition, levelSpacing, siblingSpacing);

            // Update position for the next child
            childPosition.x += siblingSpacing;
        }
    }
}


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization with SFML");
    
    // Load font
    sf::Font font;
    if (!font.loadFromFile("/home/hadarfro/Downloads/Roboto/Roboto-Black.ttf")) {
        cerr << "Failed to load font 'arial.ttf'" << endl;
        return -1;
    }

    // Create a sample tree
    Tree<double> root = createSampleTree<double>();

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        sf::Vector2u windowSize = window.getSize();
        sf::Vector2f rootPosition(windowSize.x / 2.f, 100.f);
        drawTree(window,root.getRoot() , font, rootPosition,(float)100.f,(float)50.f);
        // Draw the tree starting from the root
        //drawTree(window, root.getRoot(), font);

        window.display();
    }

    // Clean up allocated memory
    // This is simplified and for demonstration purposes only
    // delete root.->children[0]->children[0];
    // delete root->children[0]->children[1];
    // delete root->children[1]->children[0];
    // delete root->children[1];
    // delete root->children[0];
    // delete root;

    return 0;
}
