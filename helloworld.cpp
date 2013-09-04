
#include "helloworld.h"
#include "ui_helloworld.h"
#include <QFileDialog>
#include "opencv/cv.h"       //cv.hを読み込む
#include "opencv/highgui.h"  //highgui.hを読み込む
HelloWorld::HelloWorld(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelloWorld)
{
    ui->setupUi(this);
}

HelloWorld::~HelloWorld()
{
    delete ui;
}

void HelloWorld::on_pushButton_clicked()
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
    cvWaitKey(0);

    cvReleaseImage(&img);
    cvDestroyWindow("Image");
}

void HelloWorld::on_pushButton_2_clicked()
{
    IplImage *img = cvLoadImage("/Users/minemuradaiki/Dropbox/KAMIpro2013/pj_03.png", CV_LOAD_IMAGE_ANYCOLOR);
    IplImage *resized = cvCreateImage(cvSize(img->width/2, img->height/2), IPL_DEPTH_8U, 3);

    if( img == NULL ){
        fprintf(stderr, "no such file or directory\n");
        exit(-1);
    }

    cvResize(img, resized, CV_INTER_CUBIC);

    cvNamedWindow("Image",CV_WINDOW_AUTOSIZE);
    cvShowImage("Image",resized);
    cvWaitKey(0);

    cvReleaseImage(&img);
    cvReleaseImage(&resized);
    cvDestroyWindow("Image");

}

void HelloWorld::on_pushButton_3_clicked()
{
    IplImage *img = cvLoadImage("/Users/minemuradaiki/Downloads/test.jpg", CV_LOAD_IMAGE_ANYCOLOR);
    IplImage *gray = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);

    if( img == NULL ){
        fprintf(stderr, "no such file or directory\n");
        exit(-1);
    }

    cvCvtColor(img, gray, CV_RGB2GRAY);

    cvNamedWindow("Image",CV_WINDOW_AUTOSIZE);
    cvShowImage("Image",gray);
    cvWaitKey(0);

    cvReleaseImage(&img);
    cvReleaseImage(&gray);
    cvDestroyWindow("Image");
}

void HelloWorld::on_pushButton_4_clicked()
{
    IplImage *img = cvLoadImage( "/Users/minemuradaiki/Downloads/test.jpg", CV_LOAD_IMAGE_ANYCOLOR);
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
    cvWaitKey(0);

    cvReleaseImage(&img);
    cvReleaseImage(&bin);
    cvDestroyWindow("Image");
}
