#include "musicimage.h"

// *******************************************
//
//  Инициализация пустого объекта изображения
//
// *******************************************

MusicImage::MusicImage()
{
    m_image       = QImage();
    m_imageFormat = QString();
}

// *********************************************
//
//  Инициализация объекта изображения значением
//
// *********************************************

MusicImage::MusicImage(const QImage  image,
                       const QString imageFormat)
{
    m_image       = image;
    m_imageFormat = imageFormat;
}

// ***************************************************************
//
//  Получение изображения и установка нового изображения в объект
//
// ***************************************************************

QImage MusicImage::getImage() const
{
    return m_image;
}

void MusicImage::setImage(const QImage image)
{
    m_image = image;
}

// ************************************
//
//  Доступ к полю "Формат изображения"
//
// ************************************

QString MusicImage::getImageFormat() const
{
    return m_imageFormat;
}

void MusicImage::setImageFormat(const QString imageFormat)
{
    m_imageFormat = imageFormat;
}
