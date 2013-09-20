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
namespace Ui {
class MainWindow;
}
class CustumView : public QListWidget
{
    Q_OBJECT//マクロ

public:
    explicit CustumView(QWidget *parent = 0);//コンストラクタ
protected:

    void mousePressEvent(QMouseEvent *e);//マウス左をクリックしたら呼ばれる
    void mouseMoveEvent(QMouseEvent *e);//マウスカーソルを移動したら呼ばれる
    void dragEnterEvent(QDragEnterEvent *e);//ドラッグされたものが来たら呼ばれる
    void dragMoveEvent(QDragMoveEvent *e);//ドラッグ＆ドロップが操作されている間呼ばれる
    void dropEvent(QDropEvent *e);//ドロップの動作
    void dragLeaveEvent( QDragLeaveEvent *e ) {}

private:
    void startDrag();//自分のウィジットでドラッグを開始した場合
    QPoint startPos;//マウスの位置
};

#endif // CUSTUMVIEW_H
