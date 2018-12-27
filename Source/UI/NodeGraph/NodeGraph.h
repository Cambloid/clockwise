#pragma once

#include <QMainWindow>

namespace Ui {
    class NodeGraph;
}

class NodeGraph : public QMainWindow
{
    Q_OBJECT

public:
    explicit NodeGraph(QWidget *parent = nullptr);
    ~NodeGraph();

private:
    Ui::NodeGraph *ui;
};
