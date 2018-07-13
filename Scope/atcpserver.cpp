#include "atcpserver.h"
#include <QTcpSocket>

ATcpServer::ATcpServer(QString path, int port, QObject *parent) : QObject(parent),Path(path),Port(port)
{
    Server = new QTcpServer(this);
}

void ATcpServer::Start(){
    connect(Server,SIGNAL(newConnection()),this,SLOT(Accept()));
    QHostAddress address(Path);
    Server->listen(address,Port);
}

void ATcpServer::Stop(){
    Server->close();
}

void ATcpServer::Accept(){
    QTcpSocket *con = Server->nextPendingConnection();
    connect(con,SIGNAL(readyRead()),this,SLOT(Recv()));
}

void ATcpServer::Recv(){
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    QByteArray bytes = socket->readAll();
    socket->write(bytes);
}
