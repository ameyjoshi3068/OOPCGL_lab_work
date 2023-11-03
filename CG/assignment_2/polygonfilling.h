#ifndef POLYGONFILLING_H
#define POLYGONFILLING_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PolygonFilling; }
QT_END_NAMESPACE

class PolygonFilling : public QMainWindow
{
    Q_OBJECT

public:
    PolygonFilling(QWidget *parent = nullptr);
    ~PolygonFilling();

    void mousePressEvent(QMouseEvent *event);
    void DDALine(int x0,int xf, int y0, int yf);

private slots:
    void on_fillPolygon_clicked();

    void on_pushButton_clicked();

    void delay(int millisecondsToWait);


private:
    Ui::PolygonFilling *ui;
    bool clicked=false;
    int temp,i,j;
    int xVals[100],yVals[100],count=0;
    QRgb fillColor;
    float slope[20],dx,dy,x[20];
};
#endif // POLYGONFILLING_H
