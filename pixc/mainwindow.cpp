#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "opencv/cv.h"       //cv.hを読み込む
#include "opencv/highgui.h"  //highgui.hを読み込む
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

void on_trackbar1 (int val);
void on_trackbar2 (int val);

void MainWindow::paintEvent(QPaintEvent *)//←重要！ペイントイベント
{
    QImage image(this->size(), QImage::Format_ARGB32_Premultiplied);//空イメージ

    QPainter imagePainter(&image);//空イメージを引数に
    imagePainter.setRenderHint(QPainter::Antialiasing, true);
    imagePainter.drawImage(50,50,QImage("/Users/minemuradaiki/Desktop/a.jpg"));/*空イメージに画像を描画*/

    QPainter widgetPainter(this);//ウィジット用のQPainter
    widgetPainter.drawImage(0, 150, image);//ウィジットに先ほど描いたイメージ描画
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

/* コールバック関数 */
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
