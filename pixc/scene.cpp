#include "scene.h"

Scene::Scene(QWidget *parent):
        QGraphicsScene(parent)//コンストラクタ
{
}
/*
void Scene::mousePressEvent ( QGraphicsSceneMouseEvent *e)
{
    if(e->button() == Qt::LeftButton ) {
        m_mousePos = e->scenePos();
        m_rectItem = addRect(QRectF(m_mousePos, m_mousePos));
    }

    //QGraphicsPixmapItem *kasa_06 = addPixmap(QPixmap( "/Users/minemuradaiki/pixc/kasa_06.png"));//シーンに画像を配置
    //kasa_06->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
}
*/

void Scene::mouseMoveEvent(QMouseEvent *e)
{


}

/*
void Scene::mouseReleaseEvent ( QGraphicsSceneMouseEvent *e)
{
    QPointF p = e->scenePos();
    QGraphicsRectItem *item = addRect(QRectF(p, p + QPointF(64, 32)));
}
*/
void Scene::dragEnterEvent(QDragEnterEvent *e)
{

        e->acceptProposedAction();
}

void Scene::dropEvent(QDropEvent *e)
{
    /*
    //dragEnterEventの後にくるイベント
    //ドロップの際の動作を記述する
    startPos = e->pos();
    posx=startPos.x()-64;
    posy=startPos.y()-64;
    update();
    */

    // -----ver.Kana.H------

    QGraphicsPixmapItem *a = addPixmap(QPixmap("/Users/Kana/work/PixC/pixc/kasa_06.png"));

    // ---------------------


    // -----ver.Novelist-----
    //
    //    QGraphicsPixmapItem *a = addPixmap(QPixmap("/Users/minemuradaiki/pixc/kasa_06.png"));
    //
    // ---------------------
    a->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
}
