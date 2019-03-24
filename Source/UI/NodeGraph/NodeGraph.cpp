#include "UI/NodeGraph/NodeGraph.h"



NodeGraph::NodeGraph(QWidget *parent) : QDockWidget(parent)
{

	this->setConnectionStyle();

	this->mainWidget = new QWidget(this);
	this->setWidget(this->mainWidget);

	QVBoxLayout *vBox = new QVBoxLayout(this->mainWidget);

	auto scene = new QtNodes::FlowScene(this->registerNodes(), this->mainWidget);
	vBox->addWidget(new QtNodes::FlowView(scene));
	vBox->setContentsMargins(0, 0, 0, 0);
	vBox->setSpacing(0);

}

NodeGraph::~NodeGraph()
{

}

std::shared_ptr<QtNodes::DataModelRegistry> NodeGraph::registerNodes()
{
	auto ret = std::make_shared<QtNodes::DataModelRegistry>();
	ret->registerModel<NumberSourceDataModel>("Sources");

	return ret;
}

void NodeGraph::setConnectionStyle()
{
	QtNodes::ConnectionStyle::setConnectionStyle(
		R"(
  {
    "ConnectionStyle": {
      "ConstructionColor": "gray",
      "NormalColor": "black",
      "SelectedColor": "gray",
      "SelectedHaloColor": "deepskyblue",
      "HoveredColor": "deepskyblue",

      "LineWidth": 3.0,
      "ConstructionLineWidth": 2.0,
      "PointDiameter": 10.0,

      "UseDataDefinedColors": true
    }
  }
  )");

}
