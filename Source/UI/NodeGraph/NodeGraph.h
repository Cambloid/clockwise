#pragma once

#include <QDockWidget>
#include <QVBoxLayout>

#include <nodes/internal/NodeData.hpp>
#include <nodes/internal/FlowScene.hpp>
#include <nodes/internal/FlowView.hpp>
#include <nodes/internal/ConnectionStyle.hpp>
#include <nodes/internal/TypeConverter.hpp>
#include <nodes/internal/DataModelRegistry.hpp>

#include "Nodes/NumberSourceDataModel.h"


class NodeGraph : public QDockWidget
{
    Q_OBJECT

public:
    explicit NodeGraph(QWidget *parent = nullptr);
    ~NodeGraph();

private: // Methods
	std::shared_ptr<QtNodes::DataModelRegistry> registerNodes();
	void setConnectionStyle();


private:
	QWidget *mainWidget;

};
