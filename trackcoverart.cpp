#include "trackcoverart.h"

// *********************************************
//
//  Инициализация пустого объекта обложки трека
//
// *********************************************

TrackCoverArt::TrackCoverArt()
{
    m_coverArt = QImage();
}

// ***********************************************
//
//  Инициализация объекта обложки трека значением
//
// ***********************************************

TrackCoverArt::TrackCoverArt(QImage trackCoverArt)
{
    m_coverArt = trackCoverArt;
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

bool TrackCoverArt::setCoverArt(const QImage trackCoverArt)
{
    m_coverArt = trackCoverArt;
    return true;
}
