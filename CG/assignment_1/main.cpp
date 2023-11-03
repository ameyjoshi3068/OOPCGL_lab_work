#include "mainwindow.h"

#include <QApplication>

//Q. Write C++ program to draw the following pattern Use DDA line and Bresenham‘s circle algorithm. Apply the concept of encapsulation.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
