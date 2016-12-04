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

    qlonglong getSize()   const;
    int       getHeight() const;
    int       getWidth()  const;

private:
    QImage    m_image;       // Изображение (обложка или фотография)
    QString   m_imageFormat; // Формат изображения
    qlonglong m_imageSize;   // Размер изображения в памяти
    int       m_height;      // Высота изображения
    int       m_width;       // Ширина изображения
};

#endif // TRACKCOVERART_H
