#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdlib.h>
#include <time.h>
#include <QTime>
#include <QKeyEvent>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_startPB_clicked();

    void on_goPB_clicked();

private:
    Ui::MainWindow *ui;
    bool end=false;
    int productsArray[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    void realizarPC();
    void delay(const int &mSeconds);
    void putProduct(const int &pos, const int &img);
    void removeProduct(const int &pos);
};
#endif // MAINWINDOW_H
