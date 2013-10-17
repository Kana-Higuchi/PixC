#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
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
#include<QUrl>
#include <QFileDialog>
namespace Ui {
class MainWindow;
}
class Scene : public QGraphicsScene
{
    //Q_OBJECT
public:
    explicit Scene(QWidget *parent);//コンストラクタ
    QPointF m_mousePos;
    QGraphicsRectItem *m_rectItem;
protected:

    //void mousePressEvent ( QGraphicsSceneMouseEvent *e);
    //void mouseReleaseEvent ( QGraphicsSceneMouseEvent *e);
    //void mouseMoveEvent ( QGraphicsSceneMouseEvent *e);
    void dragEnterEvent(QDragEnterEvent  *e );
void mouseMoveEvent(QMouseEvent *e);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent * e ) {}
    void dropEvent(QDropEvent *e );

};

#endif // SCENE_H
