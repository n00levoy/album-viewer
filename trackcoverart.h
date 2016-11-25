#ifndef TRACKCOVERART_H
#define TRACKCOVERART_H

#include <QImage>

// *******************************************
//
//  Класс-хранилище обложки альбома для трека
//
// *******************************************

class TrackCoverArt
{
public:
    // **************************
    //  Создание пустого объекта
    // **************************

    TrackCoverArt();

    // *****************************
    //  Создание объекта с обложкой
    // *****************************

    TrackCoverArt(const QImage  trackCoverArt,
                  const QString trackCoverFormat);

    // ****************
    //  Методы доступа
    // ****************

    const QImage getCoverArt();
    void         setCoverArt(const QImage trackCoverArt);

    const QString getCoverFormat();
    void          setCoverFormat(const QString trackCoverFormat);

private:
    QImage  m_coverArt;    // Обложка альбома
    QString m_imageFormat; // Формат изображения
};

#endif // TRACKCOVERART_H
