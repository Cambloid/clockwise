#include <QApplication>

//#include "UI/MainWindow/MainWindow.h"
//#include "UI/NodeGraph/NodeGraph.h"
#include "UI/VideoViewport/VideoViewport.h"
#include <iostream>
#include <string>


int main(int argc, char *argv[])
{
	
    QApplication a(argc, argv);
    VideoViewport w;
    w.show();

    return a.exec();
}