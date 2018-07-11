#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint|Qt::Dialog);
    SetWindowLongA(HWND(winId()),-20,0x80000);
    SetLayeredWindowAttributes(HWND(winId()),65280,255,1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
