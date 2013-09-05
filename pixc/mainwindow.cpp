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
IplImage *img = 0;

void on_trackbar1 (int val);
void on_trackbar2 (int val);


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
    IplImage *img =  cvLoadImage(fileName.toLocal8Bit());
    IplImage *gray = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
    IplImage *bin = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);

    if( img == NULL ){
        fprintf(stderr, "no such file or directory\n");
        exit(-1);
    }

    cvCvtColor(img, gray, CV_RGB2GRAY);
    cvThreshold(gray, bin, 128, 255, CV_THRESH_BINARY);

    cvNamedWindow("Image",CV_WINDOW_AUTOSIZE);
    cvShowImage("Image",bin);

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
    char str[64];


    // トラックバー2を，トラックバー1に同期させる
  cvSetTrackbarPos ("Trackbar2", "Image", val);

  // (4)トラックバー1の値を描画する
  cvRectangle (img, cvPoint (0, 0), cvPoint (400, 50), cvScalar (0), CV_FILLED);
  snprintf (str, 64, "%d", val);
  cvPutText (img, str, cvPoint (15, 30), &font, CV_RGB (0, 200, 100));
  cvShowImage ("Image", img);

}

void on_trackbar2(int val) {
      int pos1, pos2;
      // トラックバー2の移動範囲を，トラックバー1の値±20に限定する
      pos1 = cvGetTrackbarPos ("Trackbar1", "Image");
      if (pos1 > val) pos2 = pos1 - 20 < val ? val : pos1 - 20;
      else pos2 = pos1 + 20 > val ? val : pos1 + 20;
      cvSetTrackbarPos("Trackbar2", "Image", pos2);

    }
