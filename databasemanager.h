#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtCore>
#include <QSqlDatabase>

#include "trackinfo.h"
#include "artist.h"

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

    bool insertFileInfo  (const TrackFileInfo &fileInfo);
    bool insertMetaData  (const TrackMetaData &metaData);
    bool insertTagData   (const TrackTagData  &tagData);
    bool insertTrackStats();

    int  insertArtist     (const Artist artist);
    bool insertArtistStats();
    int  insertArtistPhoto(const MusicImage artistPhoto);

    int  insertAlbum      (const QString album);

    int findArtist(const QString artistName);
    int findAlbum (const QString album, const QString artist);


    QSqlDatabase* m_database;
};

#endif // DATABASEMANAGER_H
