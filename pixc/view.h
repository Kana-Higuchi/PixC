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

//    -----ver.Novelist-----
//    void dropEvent( QDropEvent *e)
//    {
//        QPointF p = e->pos();
//        if(e->mimeData()->text()=="kasa_06.png"){
//            QGraphicsPixmapItem *kasa_06 = scene()->addPixmap(QPixmap( "/Users/minemuradaiki/pixc/kasa_06.png"));//シーンに画像を配置
//            kasa_06->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
//            kasa_06->setPos(p);
//        }
//        else if(e->mimeData()->text()=="kasa_h_03.png"){
//            QGraphicsPixmapItem *kasa_h_03 = scene()->addPixmap(QPixmap( "/Users/minemuradaiki/pixc/kasa_h_03.png" ));
//            kasa_h_03->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
//            kasa_h_03->setPos(p);
//        }
//        else if(e->mimeData()->text()=="kasa_m_07.png"){
//            QGraphicsPixmapItem *kasa_m_07 = scene()->addPixmap(QPixmap( "/Users/minemuradaiki/pixc/kasa_m_07.png"));
//            kasa_m_07->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
//            kasa_m_07->setPos(p);
//        }
//        else if(e->mimeData()->text()=="kasa_migi_03.png"){
//            QGraphicsPixmapItem *kasa_migi_03 = scene()->addPixmap(QPixmap( "/Users/minemuradaiki/pixc/kasa_migi_03.png" ));
//            kasa_migi_03->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
//            kasa_migi_03->setPos(p);
//        }
//        else if(e->mimeData()->text()=="kasa_y_03.png"){
//            QGraphicsPixmapItem *kasa_y_03 = scene()->addPixmap(QPixmap( "/Users/minemuradaiki/pixc/kasa_y_03.png" ));
//            kasa_y_03->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
//            kasa_y_03->setPos(p);
//        }
//    }
//    --------------------


//    -----ver.Kana.H------

    void dropEvent( QDropEvent *e)
    {
        QPointF p = e->pos();
        if(e->mimeData()->text()=="kasa_06.png"){
            QGraphicsPixmapItem *kasa_06 = scene()->addPixmap(QPixmap( "/Users/Kana/work/PixC/pixc/kasa_06.png"));//シーンに画像を配置
            kasa_06->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
            kasa_06->setPos(p);
        }
        else if(e->mimeData()->text()=="kasa_h_03.png"){
            QGraphicsPixmapItem *kasa_h_03 = scene()->addPixmap(QPixmap( "/Users/Kana/work/PixC/pixc/kasa_h_03.png" ));
            kasa_h_03->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
            kasa_h_03->setPos(p);
        }
        else if(e->mimeData()->text()=="kasa_m_07.png"){
            QGraphicsPixmapItem *kasa_m_07 = scene()->addPixmap(QPixmap( "/Users/Kana/work/PixC/pixc/kasa_m_07.png"));
            kasa_m_07->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
            kasa_m_07->setPos(p);
        }
        else if(e->mimeData()->text()=="kasa_migi_03.png"){
            QGraphicsPixmapItem *kasa_migi_03 = scene()->addPixmap(QPixmap( "/Users/Kana/work/PixC/pixc/kasa_migi_03.png" ));
            kasa_migi_03->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
            kasa_migi_03->setPos(p);
        }
        else if(e->mimeData()->text()=="kasa_y_03.png"){
            QGraphicsPixmapItem *kasa_y_03 = scene()->addPixmap(QPixmap( "/Users/Kana/work/PixC/pixc/kasa_y_03.png" ));
            kasa_y_03->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
            kasa_y_03->setPos(p);
        }
    }

//    ---------------------

    void dragMoveEvent( QDragMoveEvent *e ) {}
    void dragLeaveEvent( QDragLeaveEvent * e ) {}

};

#endif // VIEW_H
