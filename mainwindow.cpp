#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cMath.h"
#include "time.h"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer.setInterval(100);
    QObject::connect(&timer,SIGNAL(timeout()),this,SLOT(timer_res()),Qt::DirectConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startstop_clicked()
{
    if (ui->startstop->text() == "Start")
    {
        ui->startstop->setText("Stop");
        timer.start();
    } else
    {
        ui->startstop->setText("Start");
        timer.stop();
    }
}

void MainWindow::timer_res()
{
    struct timespec tt;
    qint64 msec = cMath::getMsec();
    cMath::current_utc_time(&tt);

    QString str = cMath::msecToString(msec);
    int delta = tt.tv_sec*1000 - msec;
    ui->msec_label->setText(QString::number(msec)+ "  мсек");
    ui->text_label->setText(str);
    ui->delta_msec->setText(QString::number(delta) + "  мсек");

    qDebug() << QString::number(msec) << "      ||||       "  << str;
    if (qAbs(delta) > 1000) qDebug() << "Too much differnce! ";
}
