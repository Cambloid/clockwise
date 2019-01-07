#include "UI/NodeGraph/NodeGraph.h"
#include "ui_NodeGraph.h"

NodeGraph::NodeGraph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NodeGraph)
{
    ui->setupUi(this);
}

NodeGraph::~NodeGraph()
{
    delete ui;
}
