#ifndef CUSTUMVIEW_H
#define CUSTUMVIEW_H

#include <QListWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QMouseEvent>
#include <QDialog>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QDrag>
#include <qpainter.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include<QRect>
//#include <opencv2/opencv.hpp>

namespace Ui {
class MainWindow;
}
class CustumView : public QListWidget
{
    Q_OBJECT//マクロ

public:
    explicit CustumView(QWidget *parent = 0);//コンストラクタ
protected:
/*
    void mousePressEvent(QMouseEvent *e);//マウス左をクリックしたら呼ばれる
    void mouseMoveEvent(QMouseEvent *e);//マウスカーソルを移動したら呼ばれる
    void dragEnterEvent(QDragEnterEvent *e);//ドラッグされたものが来たら呼ばれる
    void dragMoveEvent(QDragMoveEvent *e);//ドラッグ＆ドロップが操作されている間呼ばれる
    void dropEvent(QDropEvent *e);//ドロップの動作
    void dragLeaveEvent( QDragLeaveEvent *e ) {}
*/
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsItemGroup *gridGroup;
    QPoint previousPoint;
    int addOffset;
    int pasteOffset;
};

#endif // CUSTUMVIEW_H
