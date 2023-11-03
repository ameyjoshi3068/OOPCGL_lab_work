#include "polygonfilling.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PolygonFilling w;
    w.show();
    return a.exec();
}
