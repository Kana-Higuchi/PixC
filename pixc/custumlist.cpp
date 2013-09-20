#include "custumlist.h"
CustumList::CustumList(QWidget *parent) :
        QListWidget(parent)//コンストラクタ
{
    //ドラッグ＆ドロップを受け付ける
    //trueで許可。
    setAcceptDrops(true);
}

void CustumList::mousePressEvent(QMouseEvent *e)
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

void CustumList::mouseMoveEvent(QMouseEvent *e)
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

void CustumList::startDrag()
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

void CustumList::dragEnterEvent(QDragEnterEvent *e)
{
    CustumList *source =
            qobject_cast<CustumList *>(e->source());

    //自分意外からのドラック＆ドロップなら
    if (source && source != this)
    {
        e->setDropAction(Qt::MoveAction);
        e->accept();
    }
}

void CustumList::dragMoveEvent(QDragMoveEvent *e)
{
    CustumList *source =
            qobject_cast<CustumList *>(e->source());

    //自分意外からのドラック＆ドロップなら
    if (source && source != this)
    {
        e->setDropAction(Qt::MoveAction);
        e->accept();
    }
}

void CustumList::dropEvent(QDropEvent *e)
{
    CustumList *source =
            qobject_cast<CustumList *>(e->source());

    //自分意外からのドラック＆ドロップなら
    if (source && source != this)
    {
        //自分のアイテムへドロップされたものを追加
        addItem(e->mimeData()->text());
        e->setDropAction(Qt::MoveAction);
        e->accept();
    }
}
