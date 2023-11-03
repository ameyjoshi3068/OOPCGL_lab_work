#include "polygonfilling.h"
#include "ui_polygonfilling.h"
#include <QTime>
#include <iostream>
#include <QColorDialog>
#include "QMouseEvent"
#include <cmath>

PolygonFilling::PolygonFilling(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PolygonFilling)
{
    ui->setupUi(this);
    QImage img(500,600,QImage::Format_RGB888);
    ui->imgLabel->setPixmap(QPixmap :: fromImage(img));
}
QImage img(500,600,QImage::Format_RGB888);
const QRgb fillColor= QColor(255,255,255).rgba();

void PolygonFilling::DDALine(int x1,int x2, int y1, int y2){
     int dx, dy, length;
      float x,y,xi,yi;
      dx = x2 - x1;
      dy = y2 - y1;
      length = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
      xi = (float)dx/length;
      yi = (float)dy/length;
      x = x1;
      y = y1;
      img.setPixel(x,y,fillColor);
      int i = 1;
      while(i <= length)
        {
          x = x + xi;
          y = y + yi;
          img.setPixel(x,y,fillColor);
          i++;
      }

}

PolygonFilling::~PolygonFilling()
{
    delete ui;
}

void PolygonFilling::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        xVals[count]=event->x();
        yVals[count]=event->y();
        if(!clicked){
            clicked=true;
        }
        else{
            DDALine(xVals[count-1],xVals[count],yVals[count-1],yVals[count]);
        }
        count++;
    }
    else if (event->button() == Qt::RightButton) {
        if(clicked){
            DDALine(xVals[count-1],xVals[0],yVals[count-1],yVals[0]);
        }
    }
    ui->imgLabel->setPixmap(QPixmap :: fromImage(img));
}

void PolygonFilling::delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}


void PolygonFilling::on_fillPolygon_clicked()
{
    int ymax = 0;
    int ymin = 100000000;
    xVals[count] = xVals[0];
    yVals[count] = yVals[0];
    for( int i=0;i<count-1;i++)
    {
        if(yVals[i]>ymax)
            ymax=yVals[i];
        if(yVals[i]<ymin)
            ymin=yVals[i];
    }
    for(int i=0;i<count;i++)
    {

        dx=xVals[i+1]-xVals[i];
        dy=yVals[i+1]-yVals[i];
        if(dx==0.0){slope[i]=1.0;}
        if(dy==0.0){slope[i]=0.0;}
        if(dx!=0.0 and dy!=0.0)
        {
            slope[i]=float(dx/dy);
        }
    }
    for(int y=0;y<500;y++)
    {
        int index=0;
        for(int i=0;i<count;i++)
        {
            if((y>=yVals[i] and y<yVals[i+1])or(y>=yVals[i+1] and y<yVals[i]))
            {
                x[index]=xVals[i]+slope[i]*(y-yVals[i]);
                index++;
            }
        }
        for(int i=0;i<index-1;i++)
        {
            for(int k=0;k<index-1-i;k++)
            {
                if(x[k]>x[k+1])
                {
                    temp=x[k];
                    x[k]=x[k+1];
                    x[k+1]=temp;
                }
            }
        }
        for(int j=0;j<index;j+=2)
        {
            DDALine(x[j],x[j+1],y,y);
            delay(4);
            ui->imgLabel->setPixmap(QPixmap :: fromImage(img));
        }
    }
}

void PolygonFilling::on_pushButton_clicked()
{
    fillColor = QColorDialog::getColor().rgb();
}

