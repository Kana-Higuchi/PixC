#ifndef QGRAPHICSSCENE_H
#define QGRAPHICSSCENE_H
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include "qgraphicsscene.h"
#include <qpainter.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include<QRect>
//#include <opencv2/opencv.hpp>
#include<QClipboard>
class QGraphicsScene : public QGraphicsScene
{
public:
    QGraphicsScene();
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

#endif // QGRAPHICSSCENE_H
