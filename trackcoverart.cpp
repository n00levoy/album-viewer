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

const QImage TrackCoverArt::getCoverArt()
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

const QString TrackCoverArt::setCoverFormat(const QString trackCoverFormat)
{
    m_imageFormat = trackCoverFormat;
}

void TrackCoverArt::getCoverFormat()
{
    return m_imageFormat;
}
