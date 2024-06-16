#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "node.hpp"
#include "tree.hpp"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

using namespace std;

template <typename T>
class TreeWidget : public QGraphicsView {
public:
    explicit TreeWidget(Tree<T>& tree) {
        QGraphicsScene* scene = new QGraphicsScene(this);
        setScene(scene);
        render_tree(tree.get_root(), scene, 0, 0, 100);
    }

private:
    void render_tree(Node<T>* node, QGraphicsScene* scene, int x, int y, int dx) {
        if (!node) return;
        QGraphicsTextItem* item = scene->addText(QString::fromStdString(std::to_string(node->value)));
        item->setPos(x, y);
        int child_x = x - dx * (node->children.size() - 1) / 2;
        for (auto& child : node->children) {
            if (child) {
                scene->addLine(x + 10, y + 10, child_x + 10, y + 50);
                render_tree(child.get(), scene, child_x, y + 50, dx / 2);
                child_x += dx;
            }
        }
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Tree<int> tree;
    tree.add_root(1);
    tree.add_sub_node(1, 2);
    tree.add_sub_node(1, 3);

    TreeWidget<int> widget(tree);
    widget.show();

    return app.exec();
}
