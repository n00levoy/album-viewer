#include "trackinfo.h"

// **************************************************
//
//  Инициализация пустого объекта информации о треке
//
// **************************************************

TrackInfo::TrackInfo()
{
    m_fileInfo = TrackFileInfo();
    m_metaData = TrackMetaData();
    m_tagData  = TrackTagData();
    m_coverArt = TrackCoverArt();
}

// *********************************************************
//
//  Инициализация объекта полным набором информации о треке
//
// *********************************************************

TrackInfo::TrackInfo(const TrackFileInfo trackFileInfo, // Информация о файле
                     const TrackMetaData trackMetaData, // Мета-данные
                     const TrackTagData  trackTagData,  // ID3v2 тег-данные
                     const TrackCoverArt trackCoverArt  // Обложка альбома
                    )
{
    m_fileInfo = trackFileInfo;
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

// ***************************************
//
//  Управление полем "Информация о файле"
//
// ***************************************

const TrackFileInfo TrackInfo::getFileInfo()
{
    return m_fileInfo;
}

void TrackInfo::setFileInfo(const TrackFileInfo newFileInfo)
{
    m_fileInfo = newFileInfo;
}
