#ifndef ATCPSERVER_H
#define ATCPSERVER_H

#include <QObject>
#include <QString>
#include <QTcpServer>

class ATcpServer : public QObject
{
    Q_OBJECT

public:
    explicit ATcpServer(QString path,int port,QObject *parent = nullptr);
    void Start();
    void Stop();

signals:

public slots:
    void Accept();
    void Recv();
private:
    QString Path;
    int Port;
    QTcpServer *Server;
};

#endif // ATCPSERVER_H
