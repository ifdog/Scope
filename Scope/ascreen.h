#ifndef ASCREEN_H
#define ASCREEN_H
#include <QPixmap>
#include <QWindow>
#include <memory>

class AScreen
{
public:
    AScreen();
    std::unique_ptr<QPixmap> Fetch(const QWindow*,const WId& );
    std::unique_ptr<QByteArray> FetchBytes(const QWindow*, const WId&);

};

#endif // ASCREEN_H
