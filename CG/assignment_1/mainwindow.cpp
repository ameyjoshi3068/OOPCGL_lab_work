#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

QImage img(600,500,QImage::Format_RGB888);

void MainWindow::lineByDDA(int x0,int xf, int y0, int yf){
    double xi=x0;
    double yi=y0;
    double dx=(xf-x0);
    double dy=(yf-y0);
    double l = (std::max(dx,dy));

    double xinc = dx/l;
    double yinc=dy/l;
    QRgb value = qRgb(255,255,255);

    for (int i=0;i<int(l)+1;i++){
        img.setPixel(xi,yi,value);
        xi+=xinc;
        yi+=yinc;
    }

}

void MainWindow::plotPoint(int x,int y,int h,int k){
    QRgb value = qRgb(255,255,255);
    img.setPixel(x+h,y+k,value);
    img.setPixel(-x+h,y+k,value);
    img.setPixel(x+h,-y+k,value);
    img.setPixel(-x+h,-y+k,value);
    img.setPixel(y+h,x+k,value);
    img.setPixel(-y+h,x+k,value);
    img.setPixel(y+h,-x+k,value);
    img.setPixel(-y+h,-x+k,value);
}
void MainWindow::plotThirdLine(int h,int k, int r){
    int dx=1.7321*r;
    int x0=h-dx/2;
    int y0=k+r/2;
    QRgb value = qRgb(255,255,255);
    for (int i=0;i<dx;i++){
        img.setPixel(x0+i,y0,value);
    }
}

void MainWindow::bresenhamCircle(int h,int k,int r){
    int x=0,y=r;
    plotPoint(x,y,h,k);
    int d = 3-2*r;

    while (y>x)
    {
        if (d>=0){
            d+=4*(x-y)+10;
            x++;
            y--;
        }
        else{
            d+=4*x+6;
            x++;
        }
        plotPoint(x,y,h,k);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    img.fill(0);
    int h=300,k=250,r;
    r=ui->textEdit->toPlainText().toInt();
    h=ui->xVal->toPlainText().toInt();
    k=ui->yVal->toPlainText().toInt();
    int dy=1.7321*r;
    int dx=dy/2;

    bresenhamCircle(h,k,r);
    lineByDDA(h,h-dx,k-r,k+r/2);
    lineByDDA(h,h+dx,k-r,k+r/2);
    plotThirdLine(h,k,r);
    bresenhamCircle(h,k,r/2);


    ui->label->setPixmap(QPixmap :: fromImage(img));
}
