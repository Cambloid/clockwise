#pragma once

#include <QDockWidget>

class FootageViewer : public QDockWidget
{
    Q_OBJECT

public:
    explicit FootageViewer(QWidget *parent = nullptr);
    ~FootageViewer();

};
