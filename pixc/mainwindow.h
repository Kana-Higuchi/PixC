#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include "custumview.h"
#include <qpainter.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mouseMoveEvent(QMouseEvent *e);//マウスカーソルを移動したら呼ばれる
    void dragEnterEvent(QDragEnterEvent *e);//----ここ重要！
    void dropEvent(QDropEvent *e);//----ここ重要！

protected:
    void paintEvent(QPaintEvent *);//←ここ重要！ペイントイベント
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QPoint startPos;
};

#endif // MAINWINDOW_H
