#include "custumview.h"
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

CustumView::CustumView(QWidget *parent) :
        QListWidget(parent)//コンストラクタ
{
        view = new QGraphicsView;//QGraphicsViewオブジェクト生成
        scene = new QGraphicsScene(this);//QGraphicsSceneオブジェクト生成
        scene->setSceneRect(0, 0, 320, 320); //  シーン矩形部分
        scene->addRect(0, 0, 320,320, QPen(Qt::black), QBrush(Qt::white));   //シーン矩形部分に矩形を配置する
        view->setScene(scene);//ビューにシーンを配置
        //view->setBackgroundBrush(QBrush(Qt::gray));//背景をグレイにする
        //setCentralWidget(view);//ビューをセントラルウィジェットに設定
        QGraphicsPixmapItem *kasa_06 = scene->addPixmap(QPixmap( "/Users/minemuradaiki/pixc/kasa_06.png"));//シーンに画像を配置
        QGraphicsPixmapItem *kasa_h_03 = scene->addPixmap(QPixmap( "/Users/minemuradaiki/pixc/kasa_h_03.png" ));
        QGraphicsPixmapItem *kasa_m_07 = scene->addPixmap(QPixmap( "/Users/minemuradaiki/pixc/kasa_m_07.png"));
        QGraphicsPixmapItem *kasa_migi_03 = scene->addPixmap(QPixmap( "/Users/minemuradaiki/pixc/kasa_migi_03.png" ));
        QGraphicsPixmapItem *kasa_y_03 = scene->addPixmap(QPixmap( "/Users/minemuradaiki/pixc/kasa_y_03.png" ));
        kasa_06->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
        kasa_h_03->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        kasa_m_07 ->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        kasa_migi_03 ->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        kasa_y_03 ->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}
