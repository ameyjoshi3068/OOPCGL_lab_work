#ifndef LINECLIPPING_H
#define LINECLIPPING_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LineClipping; }
QT_END_NAMESPACE

class LineClipping : public QMainWindow
{
    Q_OBJECT

public:
    LineClipping(QWidget *parent = nullptr);
    ~LineClipping();

private slots:
    void on_beforeClippingBtn_clicked();

private:
    Ui::LineClipping *ui;
    void DDA(int x1, int y1, int x2, int y2,
             QImage &image);
    void drawWindow(int, int, int, int,QImage &image);
    int x1=0,x2=0,y1=0,y2=0;
    QImage *window1;
    QImage *window2;
};
#endif // LINECLIPPING_H
