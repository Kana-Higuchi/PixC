#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <qpainter.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include<QRect>
#include <QLabel>
//#include <opencv2/opencv.hpp>
#include<QClipboard>

class Scene;
class View;
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
//    void on_pushButton_clicked();
//    void on_pushButton_2_clicked();
//    void on_pushButton_3_clicked();
//    void on_pushButton_4_clicked();

    void on_action_Copy_triggered();
    void on_action_Delete_triggered();
    void on_action_Open_triggered();
    void on_action_Print_triggered();

    void on_text_insert_button_clicked();

    void on_center_text_button_clicked();

    void on_right_text_button_clicked();

    void on_left_text_button_clicked();

    void on_textsize_slider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QPoint startPos;
    QLabel *test;
    QGraphicsProxyWidget *proxy;
    void createSceneAndView();
    void writeItems(QDataStream &out,
                    const QList<QGraphicsItem*> &items);
    Scene *scene;
    View *view;
    QGraphicsItemGroup *gridGroup;
    QPoint previousPoint;
    int addOffset;
    int pasteOffset;

};

#endif // MAINWINDOW_H
