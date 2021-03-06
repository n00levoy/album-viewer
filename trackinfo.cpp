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
    m_coverArt = MusicImage();
}

// *********************************************************
//
//  Инициализация объекта полным набором информации о треке
//
// *********************************************************

TrackInfo::TrackInfo(const TrackFileInfo trackFileInfo, // Информация о файле
                     const TrackMetaData trackMetaData, // Мета-данные
                     const TrackTagData  trackTagData,  // ID3v2 тег-данные
                     const MusicImage    trackCoverArt  // Обложка альбома
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

TrackTagData TrackInfo::getTagData() const
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

TrackMetaData TrackInfo::getMetaData() const
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


MusicImage TrackInfo::getCoverArt() const
{
    return m_coverArt;
}

void TrackInfo::setCoverArt(const MusicImage newCoverArt)
{
    m_coverArt = newCoverArt;
}

// ******************************************
//
//  Управление объектом "Информация о файле"
//
// ******************************************

TrackFileInfo TrackInfo::getFileInfo() const
{
    return m_fileInfo;
}

void TrackInfo::setFileInfo(const TrackFileInfo newFileInfo)
{
    m_fileInfo = newFileInfo;
}
