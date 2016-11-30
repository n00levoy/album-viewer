#include "trackcoverart.h"

// *********************************************
//
//  Инициализация пустого объекта обложки трека
//
// *********************************************

TrackCoverArt::TrackCoverArt()
{
    m_coverArt    = QImage();
    m_imageFormat = QString();
}

// ***********************************************
//
//  Инициализация объекта обложки трека значением
//
// ***********************************************

TrackCoverArt::TrackCoverArt(const QImage  trackCoverArt,
                             const QString trackCoverFormat)
{
    m_coverArt    = trackCoverArt;
    m_imageFormat = trackCoverFormat;
}

// ******************************************************
//
//  Получение обложки и установка новой обложки в объект
//
// ******************************************************

QImage TrackCoverArt::getCoverArt() const
{
    return m_coverArt;
}

void TrackCoverArt::setCoverArt(const QImage trackCoverArt)
{
    m_coverArt = trackCoverArt;
}

// ***********************************************
//
//  Управление полем "Формат обложки-изображения"
//
// ***********************************************

QString TrackCoverArt::getCoverFormat() const
{
    return m_imageFormat;
}

void TrackCoverArt::setCoverFormat(const QString trackCoverFormat)
{
    m_imageFormat = trackCoverFormat;
}
