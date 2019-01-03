#pragma once

#include <QMainWindow>
#include <QVulkanWindow>

namespace Ui {
class VideoViewport;
}

class VideoViewport : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoViewport(QWidget *parent = nullptr);
    ~VideoViewport();

private:
    Ui::VideoViewport *ui;
};
