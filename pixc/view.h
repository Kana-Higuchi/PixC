#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <qpainter.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include<QRect>
//#include <opencv2/opencv.hpp>
#include<QClipboard>
#include<QGraphicsSceneMouseEvent>
#include <QListWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QMouseEvent>
#include <QDialog>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QDrag>
#include "scene.h"
#include "mainwindow.h"
#include <QUrl>
class View : public QGraphicsView
{
    Q_OBJECT
 public:
     explicit View(QWidget *parent);//コンストラクタ

 protected:
     void dragEnterEvent( QDragEnterEvent *e )
     {
         e->accept();
         if(e->mimeData()->hasFormat("text/uri-list"))
         {
             //これがないと受付られない。
             e->acceptProposedAction();
         }
     }
     void dropEvent( QDropEvent * e )
     {
   QGraphicsPixmapItem *kasa_06 = scene()->addPixmap(QPixmap("/Users/minemuradaiki/Desktop/a.jpg"));//シーンに画像を配置
   kasa_06->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
     }
     void dragMoveEvent( QDragMoveEvent *e ) {}
     void dragLeaveEvent( QDragLeaveEvent * e ) {}
};

#endif // VIEW_H
