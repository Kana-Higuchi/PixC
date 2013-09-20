#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "opencv/cv.h"       //cv.hを読み込む
#include "opencv/highgui.h"  //highgui.hを読み込む
#include <QLabel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    QLabel label("<img src='/Users/minemuradaiki/Desktop/a.jpg' />");
    label.show();
    //ui->listWidgetはCustumListです。
    ui->listWidget->addItem(new QListWidgetItem("Oak"));
    ui->listWidget->addItem(new QListWidgetItem("Banana"));
    ui->listWidget->addItem(new QListWidgetItem("Apple"));
    ui->listWidget->addItem(new QListWidgetItem("Orange"));
    ui->listWidget->addItem(new QListWidgetItem("Grapes"));
    ui->listWidget->addItem(new QListWidgetItem("Jayesh"));

    ui->listWidget->setIconSize(QSize(32,32));//アイコンサイズ３２×３２にセット

    QListWidgetItem *qitem;//QListWidgetにセットされている各アイテムの受け皿となる

    for(int i = 0; i < ui->listWidget->count(); i++)
    {
        qitem = ui->listWidget->item(i);//i行目のアイテム取り出し
        qitem->setIcon(QIcon("/Users/minemuradaiki/Desktop/a.jpg"));//アイコンセット
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

CvFont font;
IplImage *img = NULL;
IplImage *gray = NULL;
IplImage *bin = NULL;
int pos =128;
int posx=0;
int posy=0;
void on_trackbar1 (int val);
void on_trackbar2 (int val);

void MainWindow::paintEvent(QPaintEvent *)//←重要！ペイントイベント
{
    QImage image(this->size(), QImage::Format_ARGB32_Premultiplied);//空イメージ

    QPainter imagePainter(&image);//空イメージを引数に
    imagePainter.setRenderHint(QPainter::Antialiasing, true);
    imagePainter.drawImage(50,50,QImage("/Users/minemuradaiki/Desktop/a.jpg"));/*空イメージに画像を描画*/

    QPainter widgetPainter(this);//ウィジット用のQPainter
    widgetPainter.drawImage(posx, posy, image);//ウィジットに先ほど描いたイメージ描画
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName =
        QFileDialog::getOpenFileName
            (this, tr("Open Image"), ".",
             tr("JPEG (*.jpg *.jpeg)\n"
                "PNG (*.png)\n"
                "BMP (*.bmp)"));

    IplImage *img =  cvLoadImage(fileName.toLocal8Bit());
    if( img == NULL ){
        fprintf(stderr, "no such file or directory\n");
        exit(-1);
    }

    cvNamedWindow("Image",CV_WINDOW_AUTOSIZE);

    cvShowImage("Image",img);

    char key;
    key =static_cast<char>(cvWaitKey(0));
    if(key == 's')
    {
        fileName =
               QFileDialog::getSaveFileName
                    (this, tr("Open Image"), ".",
                     tr("JPEG (*.jpg *.jpeg)\n"
                        "PNG (*.png)\n"
                        "BMP (*.bmp)"));

        cvSaveImage(fileName.toLocal8Bit(),img);
            /*
    cvSaveImage( "/Users/minemuradaiki/Pictures/out.png", img); //保存
        std::cout << "Save Image.\n";
        */
    }
    cvReleaseImage(&img);
    cvDestroyWindow("Image");
}

void MainWindow::on_pushButton_2_clicked()
{
    QString fileName =
        QFileDialog::getOpenFileName
            (this, tr("Open Image"), ".",
             tr("JPEG (*.jpg *.jpeg)\n"
                "PNG (*.png)\n"
                "BMP (*.bmp)"));
    IplImage *img =  cvLoadImage(fileName.toLocal8Bit());
    IplImage *resized = cvCreateImage(cvSize(img->width/2, img->height/2), IPL_DEPTH_8U, 3);

    if( img == NULL ){
        fprintf(stderr, "no such file or directory\n");
        exit(-1);
    }

    cvResize(img, resized, CV_INTER_CUBIC);

    cvNamedWindow("Image",CV_WINDOW_AUTOSIZE);
    cvShowImage("Image",resized);



    char key;
    key =static_cast<char>(cvWaitKey(0));
    if(key == 's')
    {
        fileName =
               QFileDialog::getSaveFileName
                    (this, tr("Open Image"), ".",
                     tr("JPEG (*.jpg *.jpeg)\n"
                        "PNG (*.png)\n"
                        "BMP (*.bmp)"));

        cvSaveImage(fileName.toLocal8Bit(),resized);
    }

    cvReleaseImage(&img);
    cvReleaseImage(&resized);
    cvDestroyWindow("Image");

}

void MainWindow::on_pushButton_3_clicked()
{
    QString fileName =
        QFileDialog::getOpenFileName
            (this, tr("Open Image"), ".",
             tr("JPEG (*.jpg *.jpeg)\n"
                "PNG (*.png)\n"
                "BMP (*.bmp)"));
    IplImage *img =  cvLoadImage(fileName.toLocal8Bit());
    IplImage *gray = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);

    if( img == NULL ){
        fprintf(stderr, "no such file or directory\n");
        exit(-1);
    }

    cvCvtColor(img, gray, CV_RGB2GRAY);

    cvNamedWindow("Image",CV_WINDOW_AUTOSIZE);
    cvShowImage("Image",gray);

    char key;
    key =static_cast<char>(cvWaitKey(0));
    if(key == 's')
    {
        fileName =
               QFileDialog::getSaveFileName
                    (this, tr("Open Image"), ".",
                     tr("JPEG (*.jpg *.jpeg)\n"
                        "PNG (*.png)\n"
                        "BMP (*.bmp)"));

        cvSaveImage(fileName.toLocal8Bit(),gray);
    }

    cvReleaseImage(&img);
    cvReleaseImage(&gray);
    cvDestroyWindow("Image");
}

void MainWindow::on_pushButton_4_clicked()
{
    QString fileName =
        QFileDialog::getOpenFileName
            (this, tr("Open Image"), ".",
             tr("JPEG (*.jpg *.jpeg)\n"
                "PNG (*.png)\n"
                "BMP (*.bmp)"));
    img =  cvLoadImage(fileName.toLocal8Bit());
    if( img == NULL ){
        fprintf(stderr, "no such file or directory\n");
        exit(-1);
    }
    cvNamedWindow("Image",CV_WINDOW_AUTOSIZE);
    cvCreateTrackbar("Trackbar1","Image",0,255,on_trackbar1);
    cvCreateTrackbar("Trackbar2","Image",0,255,on_trackbar2);
    on_trackbar1(0);
    on_trackbar2(0);
        char key;
        key =static_cast<char>(cvWaitKey(0));
        if(key == 's')
        {
            fileName =
                   QFileDialog::getSaveFileName
                        (this, tr("Open Image"), ".",
                         tr("JPEG (*.jpg *.jpeg)\n"
                            "PNG (*.png)\n"
                            "BMP (*.bmp)"));

            cvSaveImage(fileName.toLocal8Bit(),bin);
        }

    cvReleaseImage(&img);
    cvReleaseImage(&bin);
    cvDestroyWindow("Image");
}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    startPos = e->pos();
    posx=startPos.x();
    posy=startPos.y();
    update();
}

void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{

        //視覚的にドロップを受付られることを
        //表示し、ドラッグ＆ドロップを受け付ける
        //これがないと受付られない。
        e->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *e)
{
    //dragEnterEventの後にくるイベント
    //ドロップの際の動作を記述する
    startPos = e->pos();
    posx=startPos.x();
    posy=startPos.y();
    update();
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
