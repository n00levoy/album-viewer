#ifndef TRACKCOVERART_H
#define TRACKCOVERART_H

#include <QImage>

// *********************************************************
//
//  Класс-хранилище фотографии для обложки или исполнителя.
//
// *********************************************************

class MusicImage
{
public:
    // ***************************
    //  Создание пустого объекта.
    // ***************************

    MusicImage();

    // **********************************
    //  Создание объекта с изображением.
    // **********************************

    MusicImage(const QImage  image,
               const QString imageFormat);

    // *****************
    //  Методы доступа.
    // *****************

    QImage getImage() const;
    void   setImage(const QImage image);

    QString getImageFormat() const;
    void    setImageFormat(const QString trackCoverFormat);

private:
    QImage  m_image;       // Изображение (обложка или фотография)
    QString m_imageFormat; // Формат изображения
};

#endif // TRACKCOVERART_H
