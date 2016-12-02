#ifndef TRACKINFO_H
#define TRACKINFO_H

#include "trackfileinfo.h"
#include "tracktagdata.h"
#include "trackmetadata.h"
#include "musicimage.h"

// *****************************************
//
//  Класс-хранилище всей информации о треке
//
// *****************************************

class TrackInfo
{
public:
    // **************************
    //  Создание пустого объекта
    // **************************

    TrackInfo();

    // ***********************************************
    //  Создание объекта с полной информацией о треке
    // ***********************************************

    TrackInfo(const TrackFileInfo trackFileInfo,                    // Инфомарция о файле
              const TrackMetaData trackMetaData = TrackMetaData(),  // Мета-данные
              const TrackTagData  trackTagData  = TrackTagData(),   // ID3v2 тег-данные
              const MusicImage    trackCoverArt = MusicImage()   // Обложка альбома
             );

    // ****************
    //  Методы доступа
    // ****************

    TrackFileInfo getFileInfo() const;
    void          setFileInfo(const TrackFileInfo newFileInfo);

    TrackTagData getTagData() const;
    void         setTagData(const TrackTagData newTagData);

    TrackMetaData getMetaData() const;
    void          setMetaData(const TrackMetaData newMetaData);

    MusicImage getCoverArt() const;
    void       setCoverArt(const MusicImage newCoverArt);

private:
    TrackFileInfo m_fileInfo;   // Общая информация о аудиофайле (размер файла, путь к файлу)
    TrackMetaData m_metaData;   // Мета-данные аудиофайла (длительность, битрейт, частота сэмплов, количество каналов)
    TrackTagData  m_tagData;    // ID3v2 тег-данные
    MusicImage    m_coverArt;   // Обложка альбома

};

#endif // TRACKINFO_H
