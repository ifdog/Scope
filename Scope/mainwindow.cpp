#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Windows.h>
#include "QShortcut"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S),this,SLOT(close()));
    setWindowFlags(Qt::WindowStaysOnTopHint|Qt::Dialog);
    SetWindowLongA(HWND(winId()),-20,0x80000);
    SetLayeredWindowAttributes(HWND(winId()),65280,255,1);
    ui->lb_content->setStyleSheet("QLabel {background:#00FF00}");
}

MainWindow::~MainWindow()
{
    delete ui;
}
