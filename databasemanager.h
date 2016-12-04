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

    int insertFileInfo  (const TrackFileInfo &fileInfo);
    int insertMetaData  (const TrackMetaData &metaData);
    int insertTagData   (const TrackTagData  &tagData);
    int insertTrackStats();

    int insertArtist     (const Artist artist);
    int insertArtistStats();
    int insertArtistPhoto(const MusicImage artistPhoto, const QString artistName);

    int insertAlbum(const QString album);

    int findArtist(const QString artistName);
    int findAlbum (const QString album, const QString artist);


    QSqlDatabase* m_database;
};

#endif // DATABASEMANAGER_H
