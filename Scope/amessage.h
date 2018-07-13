#ifndef AMESSAGE_H
#define AMESSAGE_H

#include <QObject>
#include <QByteArray>

// HEAD VERSION LENGTH   DATA TAIL
// CA   000A    00100000 XXXX 35

class AMessage : public QObject
{
    Q_OBJECT
public:
    explicit AMessage(QObject *parent = nullptr);
    explicit AMessage(QByteArray * bytes, QObject *parent() = nullptr);
    void SetVersion();
    void SetData();

    int GetVersion();
    QByteArray GetData();

    bool IsInCorrectFormat();


signals:

public slots:

private:
    QByteArray *Bytes;

};

#endif // AMESSAGE_H
