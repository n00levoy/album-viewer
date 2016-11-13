#include "trackinfo.h"

// **************************************************
//
//  Инициализация пустого объекта информации о треке
//
// **************************************************

TrackInfo::TrackInfo()
{
    m_filePath = QString();

    m_metaData = TrackMetaData();
    m_tagData  = TrackTagData();
    m_coverArt = TrackCoverArt();
}

// *********************************************************
//
//  Инициализация объекта полным набором информации о треке
//
// *********************************************************

TrackInfo::TrackInfo(const QString       trackFilePath, // Путь к файлу
                     const TrackMetaData trackMetaData, // Мета-данные
                     const TrackTagData  trackTagData,  // ID3v2 тег-данные
                     const TrackCoverArt trackCoverArt  // Обложка альбома
                    )
{
    m_filePath = trackFilePath;

    m_metaData = trackMetaData;
    m_tagData  = trackTagData;
    m_coverArt = trackCoverArt;
}

// **********************************
//
//  Управление объектом "Тег-данные"
//
// **********************************

const TrackTagData TrackInfo::getTagData()
{
    return m_tagData;
}

void TrackInfo::setTagData(const TrackTagData newTagData)
{
    m_tagData = newTagData;
}

// ***********************************
//
//  Управление объектом "Мета-данные"
//
// ***********************************

const TrackMetaData TrackInfo::getMetaData()
{
    return m_metaData;
}

void TrackInfo::setMetaData(const TrackMetaData newMetaData)
{
    m_metaData = newMetaData;
}

// ***************************************
//
//  Управление объектом "Обложка альбома"
//
// ***************************************


const TrackCoverArt TrackInfo::getCoverArt()
{
    return m_coverArt;
}

void TrackInfo::setCoverArt(const TrackCoverArt newCoverArt)
{
    m_coverArt = newCoverArt;
}

// *********************************
//
//  Управление полем "Путь к файлу"
//
// *********************************

const QString TrackInfo::getFilePath()
{
    return m_filePath;
}

void TrackInfo::setFilePath(const QString newFilePath)
{
    m_filePath = newFilePath;
}

