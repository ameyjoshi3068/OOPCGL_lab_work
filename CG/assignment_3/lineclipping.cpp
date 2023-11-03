#include "lineclipping.h"
#include "ui_lineclipping.h"

LineClipping::LineClipping(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LineClipping)
{
    ui->setupUi(this);
    window1= new QImage(300,300,QImage::Format_RGB888);
    window2= new QImage(300,300,QImage::Format_RGB888);
}

LineClipping::~LineClipping()
{
    delete window1;
    delete window2;
    delete ui;
}

void LineClipping::DDA(int x1, int y1, int x2, int y2,QImage &image)
{
    float dx,dy,length,xinc,yinc,x,y;
    dx=x2-x1;
    dy=y2-y1;
    if (abs(dx)>=abs(dy))
        length=abs(dx);
     else{
        length=abs(dy);
    }
    xinc=dx/length;
    yinc=dy/length;
    int i =0;
    x=x1;
    y=y1;
    while(i<length){
        image.setPixel(int (x),int (y),qRgb(255,255,255));
        x=x+xinc;
        y=y+yinc;
        i++;
    }
}

void LineClipping::drawWindow(int xmin, int ymin, int xmax, int ymax, QImage &image){
    DDA(xmin,ymin,xmax,ymin,image);
    DDA(xmin,ymin,xmin,ymax,image);
    DDA(xmax,ymin,xmax,ymin,image);
    DDA(xmax,ymax,xmin,ymax,image);
}

void LineClipping::on_beforeClippingBtn_clicked()
{
    x1=ui->x1Box->toPlainText().toInt();
    y1=ui->y1Box->toPlainText().toInt();
    x2=ui->x2Box->toPlainText().toInt();
    y2=ui->y2Box->toPlainText().toInt();

    drawWindow(50,50,250,250,*window1);
    drawWindow(50,50,250,250,*window2);

    ui->beforeImg->setPixmap(QPixmap::fromImage(*window1));
    ui->AfterImg->setPixmap(QPixmap::fromImage(*window2));
}
