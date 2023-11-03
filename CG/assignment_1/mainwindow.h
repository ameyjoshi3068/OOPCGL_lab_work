#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void lineByDDA(int x0,int xf, int y0, int yf);
    void plotPoint(int x,int y,int h,int k);
    void plotThirdLine(int h,int k, int r);
    void bresenhamCircle(int h,int k,int r);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
