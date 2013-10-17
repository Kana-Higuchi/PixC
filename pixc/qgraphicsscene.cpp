#include "qgraphicsscene.h"

QGraphicsScene::QGraphicsScene()
{
}
void QGraphicsScene::mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{
    if( mouseEvent->button() == Qt::LeftButton ) {
        m_mousePos = mouseEvent->scenePos();
        m_rectItem = addRect(QRectF(m_mousePos, m_mousePos));
    }
}
