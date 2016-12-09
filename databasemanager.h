#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtCore>
#include <QSqlDatabase>

#include "trackinfo.h"
#include "artist.h"
#include "album.h"

// *********************************************
//
//  Класс-менеджер для управления базой данных.
//
// *********************************************

class DatabaseManager : public QObject
{
public:
    // *************************************
    //  Создание пустого объекта-менеджера.
    // *************************************

    DatabaseManager();

    ~DatabaseManager();

    bool addTrack(const TrackInfo &trackInfo);

private:
    bool prepareTables();
    bool prepareFolders();

    int insertFileInfo  (const TrackFileInfo fileInfo);
    int insertMetaData  (const TrackMetaData metaData);
    int insertTagData   (const TrackInfo trackInfo);
    int insertTrackStats();

    int insertArtist     (const Artist artist);
    int insertArtistStats();
    int insertArtistPhoto(const MusicImage artistPhoto, const QString artistName);

    int insertAlbum     (const Album album);
    int insertAlbumStats();
    int insertCoverArt  (const MusicImage coverArt, const QString artistName, const QString albumName);

    int findArtist(const QString artistName);
    int findAlbum (const QString albumName, const QString artistName);


    QSqlDatabase* m_database;
};

#endif // DATABASEMANAGER_H
