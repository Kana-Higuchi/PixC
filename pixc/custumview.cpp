#include "custumview.h"
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

CustumView::CustumView(QWidget *parent) :
        QListWidget(parent)//コンストラクタ
{
    //ドラッグ＆ドロップを受け付ける
    //trueで許可。
    setAcceptDrops(true);

}
void CustumView::mousePressEvent(QMouseEvent *e)
{
    //マウス左ボタンをクリックしたら
    if(e->button() == Qt::LeftButton)
    {
        //そのマウスの位置を保存
        startPos = e->pos();
    }

    //デフォルトの動作へ
    QListWidget::mousePressEvent(e);
}

void CustumView::mouseMoveEvent(QMouseEvent *e)
{
    ////マウス左ボタンをクリック中なら
    if(e->buttons() & Qt::LeftButton)
    {
        //保存していたマウスの位置と現在のマウスの位置の差を求める
        //manhattanLengthは絶対値を求めるもの
        int distance = (e->pos() - startPos).manhattanLength();

        //上で求めた差分とアプリで設定してあるドラッグ＆ドロップを開始する差分
        //を比べ、それ以上ならドラッグを開始する。
        //なおstartDragDistance()はデフォルトでは4が返る
        //変更はsetStartDragDistance(int)
        if(distance >= QApplication::startDragDistance())
        {
            startDrag();
        }

        QListWidget::mouseMoveEvent(e);
    }
}

void CustumView::startDrag()
{
    //現在選択中のアイテム
    QListWidgetItem *item = currentItem();

    if (item)
    {
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(item->text());

        //ドラッグ中のアイコンのセット
        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(QPixmap("/Users/minemuradaiki/Desktop/a.jpg"));

        //ドラッグ処理の開始。
        //startはドラック＆ドロップが終わるまで処理が返らない
        if (drag->start(Qt::MoveAction) == Qt::MoveAction)
            delete item;
    }
}

void CustumView::dragEnterEvent(QDragEnterEvent *e)
{
    CustumView *source =
            qobject_cast<CustumView *>(e->source());
e->accept();
    //自分意外からのドラック＆ドロップなら
    if (source && source != this)
    {
        e->setDropAction(Qt::MoveAction);
        e->accept();
    }
}

void CustumView::dragMoveEvent(QDragMoveEvent *e)
{
    CustumView *source =
            qobject_cast<CustumView *>(e->source());

    //自分意外からのドラック＆ドロップなら
    if (source && source != this)
    {
        e->setDropAction(Qt::MoveAction);
        e->accept();
    }
}

void CustumView::dropEvent(QDropEvent *e)
{
    CustumView *source =
            qobject_cast<CustumView *>(e->source());

    QGraphicsScene scene;
    QGraphicsView view(&scene);
    QGraphicsPixmapItem item(QPixmap("/Users/minemuradaiki/Desktop/a.jpg"));
    scene.addItem(&item);
    view.show();

    //自分意外からのドラック＆ドロップなら
    if (source && source != this)
    {
        //自分のアイテムへドロップされたものを追加
        addItem(e->mimeData()->text());
        e->setDropAction(Qt::MoveAction);
        e->accept();
    }
}

