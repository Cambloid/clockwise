#include <QApplication>

#include "MainWindow/mainwindow.h"
#include <iostream>
#include <string>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
