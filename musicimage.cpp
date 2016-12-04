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
    setImage      (image);
    setImageFormat(imageFormat);
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
    m_image  = image;
    m_width  = image.width();
    m_height = image.height();

    m_imageSize = image.byteCount();
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
    if(imageFormat == "PNG" || imageFormat == "JPEG")
        m_imageFormat = imageFormat;
    else
    {
        if(imageFormat.contains("png"))
        {
            m_imageFormat = "PNG";
            return;
        }

        if(imageFormat.contains("jpg") || imageFormat.contains("jpeg"))
        {
            m_imageFormat = "JPEG";
            return;
        }

        m_imageFormat = "UNKNOWN";
    }
}

qlonglong MusicImage::getSize() const
{
    return m_imageSize;
}

int MusicImage::getHeight() const
{
    return m_height;
}

int MusicImage::getWidth() const
{
    return m_width;
}
