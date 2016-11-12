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

    TrackCoverArt(QImage trackCoverArt);

    // ****************
    //  Методы доступа
    // ****************

    const QImage getCoverArt();
    bool         setCoverArt(const QImage trackCoverArt);

private:
    QImage m_coverArt;  // Обложка альбома
};

#endif // TRACKCOVERART_H
