#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ascreen.h"
#include <Windows.h>
#include "QShortcut"
#include "atcpserver.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S),this,SLOT(close()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z),this,SLOT(hotkey_start()));
    setWindowFlags(Qt::WindowStaysOnTopHint|Qt::Dialog);
    SetWindowLongA(HWND(winId()),-20,0x80000);
    SetLayeredWindowAttributes(HWND(winId()),65280,255,1);
    ui->lb_content->setStyleSheet("QLabel {background:#00FF00}");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hotkey_client(){

}

void MainWindow::hotkey_server(){

}

void MainWindow::hotkey_settings(){

}

void MainWindow::hotkey_start(){
  ATcpServer *server = new ATcpServer("127.0.0.1",2333,this);
  server->Start();
}

void MainWindow::hotkey_stop(){

}


