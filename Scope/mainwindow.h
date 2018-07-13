#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ascreen.h"
#include "atcpserver.h"

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

    void hotkey_server();
    void hotkey_client();
    void hotkey_settings();
    void hotkey_start();
    void hotkey_stop();



private:
    Ui::MainWindow *ui;
    int runmode; //0:Server,1:Client;
    AScreen *ascreen;
    ATcpServer *atcpserver;

};
#endif // MAINWINDOW_H
