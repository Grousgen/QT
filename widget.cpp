#include "widget.h"
#include "ui_widget.h"
#include "qtimer.h"
#include "qdatetime.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timerUpdate();
    QTimer *timer = new QTimer(this);
    //add a timer
    connect(timer,&QTimer::timeout,this,&Widget::timerUpdate);
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerUpdate(void)
{
    QDateTime time= QDateTime::currentDateTime();
    QString str = time.toString("hh:mm:ss");
    ui->label->setText(str);
}
void Widget::timerUpdate2(void)
{
    count +=1;
    ui->label_count->setText(QString::number(count));
}

void Widget::on_pushButton_clicked()
{
    QTimer *timer2 =new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(timerUpdate2()));
    timer2->start(1000);
}

