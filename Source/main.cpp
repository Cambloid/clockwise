#include <QApplication>


//#include "UI/NodeGraph/NodeGraph.h"

#include "UI/MainWindow/MainWindow.h"


#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);
	printf("Debugging Window:\n");

    MainWindow w;
    w.show();

    return a.exec();
}