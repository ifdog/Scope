#include "ascreen.h"
#include <QScreen>
#include <QBuffer>


AScreen::AScreen()
{

}

std::unique_ptr<QPixmap> AScreen::Fetch(const QWindow* handle,const WId& window){
    auto s = handle->screen();
    auto ptr = std::make_unique<QPixmap>(s->grabWindow(window));
    return ptr;
}

std::unique_ptr<QByteArray> AScreen::FetchBytes(const QWindow* handle,const WId& window){
    std::unique_ptr<QPixmap> bmp = Fetch(handle,window);
    std::unique_ptr<QByteArray> ptr(new QByteArray);
    QBuffer buffer(ptr.get());
    buffer.open(QIODevice::WriteOnly);
    bmp->save(&buffer,"PNG");
    return ptr;
}
