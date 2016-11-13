#ifndef TRACKINFO_H
#define TRACKINFO_H

#include <QString>
#include <QImage>

#include "tracktagdata.h"
#include "trackmetadata.h"
#include "trackcoverart.h"

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

    TrackInfo(const QString       trackFilePath,                    // Путь к файлу
              const TrackMetaData trackMetaData = TrackMetaData(),  // Мета-данные
              const TrackTagData  trackTagData  = TrackTagData(),   // ID3v2 тег-данные
              const TrackCoverArt trackCoverArt = TrackCoverArt()   // Обложка альбома
             );

    // ****************
    //  Методы доступа
    // ****************

    const TrackTagData getTagData();
    void               setTagData(const TrackTagData newTagData);

    const TrackMetaData getMetaData();
    void                setMetaData(const TrackMetaData newMetaData);

    const TrackCoverArt getCoverArt();
    void                setCoverArt(const TrackCoverArt newCoverArt);

    const QString getFilePath();
    void          setFilePath(const QString newFilePath);

private:
    TrackMetaData m_metaData;   // Мета-данные аудиофайла (размер, длительность, битрейт, частота сэмплов, количество каналов)
    TrackTagData  m_tagData;    // ID3v2 тег-данные
    TrackCoverArt m_coverArt;   // Обложка альбома

    QString m_filePath;         // Путь к файлу
};

#endif // TRACKINFO_H
