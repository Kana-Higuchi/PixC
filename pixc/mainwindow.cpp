#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "opencv/cv.h"       //cv.hを読み込む
#include "opencv/highgui.h"  //highgui.hを読み込む
#include <QLabel>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <QImage>
#include <QGraphicsPixmapItem>
#include <QClipboard>
#include <QMimeData>
#include "scene.h"
#include "view.h"
#include <QLabel>
#include <QLayout>



const int OffsetIncrement = 5;
const QString ShowGrid("ShowGrid");
const QString MostRecentFile("MostRecentFile");
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),gridGroup(0), addOffset(OffsetIncrement),
    pasteOffset(OffsetIncrement)
{
    ui->setupUi(this);
    setAcceptDrops(true);

    //ui->listWidgetはCustumListです。
    ui->listWidget->addItem(new QListWidgetItem("kasa_06.png"));
    ui->listWidget->addItem(new QListWidgetItem("kasa_h_03.png"));
    ui->listWidget->addItem(new QListWidgetItem("kasa_m_07.png"));
    ui->listWidget->addItem(new QListWidgetItem("kasa_migi_03.png"));
    ui->listWidget->addItem(new QListWidgetItem("kasa_y_03.png"));
    ui->listWidget->setIconSize(QSize(32,32));//アイコンサイズ３２×３２にセット

    QListWidgetItem *qitem;//QListWidgetにセットされている各アイテムの受け皿となる

    for(int i = 0; i < ui->listWidget->count(); i++)
    {
        qitem = ui->listWidget->item(i);//i行目のアイテム取り出し

        switch(i){
        case 0:qitem->setIcon(QIcon(":pictgrams/picts/kasa_06.png"));break;//アイコンセット
        case 1:qitem->setIcon(QIcon(":pictgrams/picts/kasa_h_03.png"));break;//アイコンセット
        case 2:qitem->setIcon(QIcon(":pictgrams/picts/kasa_m_07.png"));break;//アイコンセット
        case 3:qitem->setIcon(QIcon(":pictgrams/picts/kasa_migi_03.png"));break;//アイコンセット
        case 4:qitem->setIcon(QIcon(":pictgrams/picts/kasa_y_03.png"));break;//アイコンセット
        default:qitem->setIcon(QIcon(":pictgrams/picts/a.jpg"));break;//アイコンセット

        }

    }

    //printer = new QPrinter(QPrinter::HighResolution);

    createSceneAndView();


    /*
    createActions();
    createMenusAndToolBars();
    createDockWidgets();
    createConnections();
    QSettings settings;
    viewShowGridAction->setChecked(
            settings.value(ShowGrid, true).toBool());
    QString filename = settings.value(MostRecentFile).toString();
    if (filename.isEmpty() || filename == tr("Unnamed"))
        QTimer::singleShot(0, this, SLOT(fileNew()));
    else {
        setWindowFilePath(filename);
        QTimer::singleShot(0, this, SLOT(loadFile()));
    }
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::createSceneAndView()
{
    scene = new Scene(this);//QGraphicsSceneオブジェクト生成
    scene->setSceneRect(0,0, 560, 560); //  シーン矩形部分o
    scene->addWidget(ui->textlabel);

    view = new View(ui->centralWidget);//QGraphicsViewオブジェクト生成
    view->setScene(scene);//ビューにシーンを配置
    view->setGeometry(280,120,570,570);
    view->setAttribute(Qt::WA_TranslucentBackground, true);

    //    view->setBackgroundBrush(QBrush(Qt::white));
    //addToolBar(view->getToolBar(this));
    //scene->addRect(0, 0, 630,470, QPen(Qt::red), QBrush(Qt::white));   //シーン矩形部分に矩形を配置する

    //    view->setBackgroundBrush(QBrush(Qt::gray));//背景をグレイにする
    //    setCentralWidget(view);//ビューをセントラルウィジェットに設定
    //    view->show();
}

/*
void MainWindow::copyItems(const QList<QGraphicsItem*> &items)
{
    QByteArray copiedItems;
    QDataStream out(&copiedItems, QIODevice::WriteOnly);
    writeItems(out, items);
    QMimeData *mimeData = new QMimeData;
    mimeData->setData(MimeType, copiedItems);
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setMimeData(mimeData);
}
*/
CvFont font;
IplImage *img = NULL;
IplImage *gray = NULL;
IplImage *bin = NULL;
int pos =128;
int posx=200;
int posy=100;
void on_trackbar1 (int val);
void on_trackbar2 (int val);



//void MainWindow::on_pushButton_clicked()
//{
//    QString fileName =
//        QFileDialog::getOpenFileName
//            (this, tr("Open Image"), ".",
//             tr("JPEG (*.jpg *.jpeg)\n"
//                "PNG (*.png)\n"
//                "BMP (*.bmp)"));

//    IplImage *img =  cvLoadImage(fileName.toLocal8Bit());
//    if( img == NULL ){
//        fprintf(stderr, "no such file or directory\n");
//        exit(-1);
//    }

//    cvNamedWindow("Image",CV_WINDOW_AUTOSIZE);

//    cvShowImage("Image",img);

//    char key;
//    key =static_cast<char>(cvWaitKey(0));
//    if(key == 's')
//    {
//        fileName =
//               QFileDialog::getSaveFileName
//                    (this, tr("Open Image"), ".",
//                     tr("JPEG (*.jpg *.jpeg)\n"
//                        "PNG (*.png)\n"
//                        "BMP (*.bmp)"));

//        cvSaveImage(fileName.toLocal8Bit(),img);
//            /*
//    cvSaveImage( "/Users/minemuradaiki/Pictures/out.png", img); //保存
//        std::cout << "Save Image.\n";
//        */
//    }
//    cvReleaseImage(&img);
//    cvDestroyWindow("Image");
//}

//void MainWindow::on_pushButton_2_clicked()
//{
//    QString fileName =
//        QFileDialog::getOpenFileName
//            (this, tr("Open Image"), ".",
//             tr("JPEG (*.jpg *.jpeg)\n"
//                "PNG (*.png)\n"
//                "BMP (*.bmp)"));
//    IplImage *img =  cvLoadImage(fileName.toLocal8Bit());
//    IplImage *resized = cvCreateImage(cvSize(img->width/2, img->height/2), IPL_DEPTH_8U, 3);

//    if( img == NULL ){
//        fprintf(stderr, "no such file or directory\n");
//        exit(-1);
//    }

//    cvResize(img, resized, CV_INTER_CUBIC);

//    cvNamedWindow("Image",CV_WINDOW_AUTOSIZE);
//    cvShowImage("Image",resized);



//    char key;
//    key =static_cast<char>(cvWaitKey(0));
//    if(key == 's')
//    {
//        fileName =
//               QFileDialog::getSaveFileName
//                    (this, tr("Open Image"), ".",
//                     tr("JPEG (*.jpg *.jpeg)\n"
//                        "PNG (*.png)\n"
//                        "BMP (*.bmp)"));

//        cvSaveImage(fileName.toLocal8Bit(),resized);
//    }

//    cvReleaseImage(&img);
//    cvReleaseImage(&resized);
//    cvDestroyWindow("Image");

//}

//void MainWindow::on_pushButton_3_clicked()
//{
//    QString fileName =
//        QFileDialog::getOpenFileName
//            (this, tr("Open Image"), ".",
//             tr("JPEG (*.jpg *.jpeg)\n"
//                "PNG (*.png)\n"
//                "BMP (*.bmp)"));
//    IplImage *img =  cvLoadImage(fileName.toLocal8Bit());
//    IplImage *gray = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);

//    if( img == NULL ){
//        fprintf(stderr, "no such file or directory\n");
//        exit(-1);
//    }

//    cvCvtColor(img, gray, CV_RGB2GRAY);

//    cvNamedWindow("Image",CV_WINDOW_AUTOSIZE);
//    cvShowImage("Image",gray);

//    char key;
//    key =static_cast<char>(cvWaitKey(0));
//    if(key == 's')
//    {
//        fileName =
//               QFileDialog::getSaveFileName
//                    (this, tr("Open Image"), ".",
//                     tr("JPEG (*.jpg *.jpeg)\n"
//                        "PNG (*.png)\n"
//                        "BMP (*.bmp)"));

//        cvSaveImage(fileName.toLocal8Bit(),gray);
//    }

//    cvReleaseImage(&img);
//    cvReleaseImage(&gray);
//    cvDestroyWindow("Image");
//}

//void MainWindow::on_pushButton_4_clicked()
//{
//    QString fileName =
//        QFileDialog::getOpenFileName
//            (this, tr("Open Image"), ".",
//             tr("JPEG (*.jpg *.jpeg)\n"
//                "PNG (*.png)\n"
//                "BMP (*.bmp)"));
//    img =  cvLoadImage(fileName.toLocal8Bit());
//    if( img == NULL ){
//        fprintf(stderr, "no such file or directory\n");
//        exit(-1);
//    }
//    cvNamedWindow("Image",CV_WINDOW_AUTOSIZE);
//    cvCreateTrackbar("Trackbar1","Image",0,255,on_trackbar1);
//    cvCreateTrackbar("Trackbar2","Image",0,255,on_trackbar2);
//    on_trackbar1(0);
//    on_trackbar2(0);
//        char key;
//        key =static_cast<char>(cvWaitKey(0));
//        if(key == 's')
//        {
//            fileName =
//                   QFileDialog::getSaveFileName
//                        (this, tr("Open Image"), ".",
//                         tr("JPEG (*.jpg *.jpeg)\n"
//                            "PNG (*.png)\n"
//                            "BMP (*.bmp)"));

//            cvSaveImage(fileName.toLocal8Bit(),bin);
//        }

//    cvReleaseImage(&img);
//    cvReleaseImage(&bin);
//    cvDestroyWindow("Image");
//}


void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{

    e->acceptProposedAction();
}

/* コOrangeールバック関数 */
void on_trackbar1(int val) {
    gray = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
    bin = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
    cvCvtColor(img, gray, CV_RGB2GRAY);
    cvThreshold(gray, bin,cvGetTrackbarPos ("Trackbar1", "Image"),cvGetTrackbarPos ("Trackbar2", "Image"), CV_THRESH_BINARY);
    cvShowImage("Image",bin);
}

void on_trackbar2(int val) {
    cvThreshold(gray, bin,cvGetTrackbarPos ("Trackbar1", "Image"),cvGetTrackbarPos ("Trackbar2", "Image"), CV_THRESH_BINARY);
    cvShowImage("Image",bin);
}

void MainWindow::on_action_Copy_triggered()
{
    /*
    QList<QGraphicsItem*> items = scene->selectedItems();
    QClipboard *clipboard = QApplication::clipboard();
    QMimeData *mimeData = new QMimeData;
    clipboard->setMimeData(mimeData);
*/
    //アプリケーションのグローバルクリップボードのポインタを返す。
    QList<QGraphicsItem*> items = scene->selectedItems();
    QListIterator<QGraphicsItem*> i(items);
    while (i.hasNext()) {
        QScopedPointer<QGraphicsItem> item(i.next());
        scene->removeItem(item.data());
    }
    //QByteArray copiedItems;
    //QDataStream out(&copiedItems, QIODevice::WriteOnly);
    //writeItems(out, items);
    //QMimeData *mimeData = new QMimeData;
    //mimeData->setData(MimeType,copiedItems);
    /*
    QClipboard *clipboard = QApplication::clipboard();
    QMimeData *mimeData = new QMimeData();
    QByteArray data((const QUrl *)&item);
    mimeData->setData("CFSTR_DOUBLE", data);
    clipboard->setMimeData(mimeData);
    */
    /*
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->clear();
    QMimeData *mimeData = new QMimeData();
    QByteArray data(*item);
    mimeData->setData("CFSTR_DOUBLE", data);
    clipboard->setMimeData(mimeData);
    */

}
void MainWindow::on_action_Delete_triggered(){
    QList<QGraphicsItem*> items = scene->selectedItems();
    QListIterator<QGraphicsItem*> i(items);
    while (i.hasNext()) {
        QScopedPointer<QGraphicsItem> item(i.next());
        scene->removeItem(item.data());
    }
}
void MainWindow::on_action_Open_triggered(){
    QString fileName =
            QFileDialog::getOpenFileName
            (this, tr("Open Image"), ".",
             tr("JPEG (*.jpg *.jpeg)\n"
                "PNG (*.png)\n"
                "BMP (*.bmp)"));
    QGraphicsPixmapItem *a = scene->addPixmap(QPixmap(fileName));
    a->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);//画像オブジェクトを動作、選択できるようにする
    //IplImage *img =  cvLoadImage(fileName.toLocal8Bit());

}
void MainWindow::writeItems(QDataStream &out,
                            const QList<QGraphicsItem*> &items)
{
    foreach (QGraphicsItem *item, items) {
        if (item == gridGroup || item->group() == gridGroup)
            continue;
        qint32 type = static_cast<qint32>(item->type());
        out << type;
    }
}

void MainWindow::on_action_Print_triggered()
{

}

void MainWindow::on_left_text_button_clicked()
{
    ui->textlabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
}

void MainWindow::on_center_text_button_clicked()
{
    ui->textlabel->setAlignment(Qt::AlignHCenter);
}

void MainWindow::on_right_text_button_clicked()
{
    ui->textlabel->setAlignment(Qt::AlignRight | Qt::AlignTop);
}


void MainWindow::on_textsize_slider_valueChanged(int value)
{
        QString fon = ui->fontComboBox->currentText();
        ui->textlabel->setFont(QFont(fon,value,QFont::Bold));
        QString str = ui->textEdit->toPlainText();
        ui->textlabel->setText(str);
}

void MainWindow::on_textEdit_textChanged()
{
    ui->textlabel->setAlignment(Qt::AlignHCenter);
    QString fon = ui->fontComboBox->currentText();
    int value = ui->spinBox->value();
    ui->textlabel->setFont( QFont(fon, value, QFont::Bold) );
    QString str = ui->textEdit->toPlainText();
    ui->textlabel->setText(str);
}


void MainWindow::on_fontComboBox_currentIndexChanged(const QString &arg1)
{
    int value = ui->spinBox->value();
    ui->textlabel->setFont(QFont(arg1,value, QFont::Bold) );
    QString str = ui->textEdit->toPlainText();
    ui->textlabel->setText(str);
}
