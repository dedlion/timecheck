#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTimer"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startstop_clicked();
    void timer_res();

private:
    Ui::MainWindow *ui;
    QTimer timer;
};

#endif // MAINWINDOW_H
