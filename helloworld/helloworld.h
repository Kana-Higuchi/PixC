#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include <QWidget>

namespace Ui {
class HelloWorld;
}

class HelloWorld : public QWidget
{
    Q_OBJECT
    
public:
    explicit HelloWorld(QWidget *parent = 0);
    ~HelloWorld();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::HelloWorld *ui;
};

#endif // HELLOWORLD_H
