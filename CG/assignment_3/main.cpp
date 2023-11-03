#include "lineclipping.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LineClipping w;
    w.show();
    return a.exec();
}
