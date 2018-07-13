#include "amessage.h"

AMessage::AMessage(QObject *parent) : QObject(parent)
{
}

AMessage::AMessage(QByteArray *bytes, QObject *parent()):QObject(parent()),Bytes(bytes)
{
}
