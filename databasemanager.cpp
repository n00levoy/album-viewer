#include "databasemanager.h"

#include <QSqlError>
#include <QSqlQuery>

DatabaseManager::DatabaseManager()
{
    m_database = nullptr;
}

DatabaseManager::DatabaseManager(int databaseType)
{
    if(databaseType)
    {
        m_database = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
        m_database->setUserName("user");
        m_database->setHostName("localpc");
        m_database->setPassword("password");

        prepareFolders();

        QString databaseName = "data/";
        switch(databaseType)
        {
        case DATABASE_MUSIC:
        {
            databaseName += "music";
            break;
        }
        default:
            break;
        }
        databaseName += ".sqlite";

        m_database->setDatabaseName(databaseName);

        if (!m_database->open())
            qDebug() << "Cannot open DB: " << m_database->lastError();
        else
            prepareTables();
    }
    else
        m_database = nullptr;
}

DatabaseManager::~DatabaseManager()
{
    if(m_database)
        delete m_database;
}

// *******************************************************************
//
//  Создание и подготовка таблиц в базе данных для дальнейшей работы:
//  - Tracks;
//  - FileInfo;
//  - MetaData;
//  - TagData;
//  - TrackStats;
//  - ListenHistory;
//  - Artist;
//  - ArtistStats;
//  - Photos;
//  - Album;
//  - AlbumStats;
//  - CoverArt.
//
// *******************************************************************

bool DatabaseManager::prepareTables()
{
    QSqlQuery query(*m_database);

    // *************************************************
    //  Создание таблицы Tracks для хранения информации
    //  о треках в фонотеке.
    // *************************************************

    QString TracksTableCreationQuery = "CREATE TABLE IF NOT EXISTS Tracks ("
                                       "TrackID INTEGER PRIMARY KEY"        // Номер трека (ключ)
                                       ")";
    query.exec(TracksTableCreationQuery);

    // ***************************************************
    //  Создание таблицы FileInfo для хранения информации
    //  о файле: пути к файлу и размера файла.
    // ***************************************************

    QString FileInfoTableCreationQuery = "CREATE TABLE IF NOT EXISTS FileInfo ("
                                         "TrackID  INTEGER PRIMARY KEY, "        // Номер трека (ключ)
                                         "FilePath TEXT, "                       // Путь к файлу
                                         "FileSize INTEGER"                      // Размер файла (в байтах)
                                         ")";
    query.exec(FileInfoTableCreationQuery);

    // ***************************************************
    //  Создание таблицы MetaData для хранения информации
    //  о мета-данных трека: длительности, битрейта,
    //  частоты сэмплов и количества каналов.
    // ***************************************************

    QString MetaDataTableCreationQuery = "CREATE TABLE IF NOT EXISTS MetaData ("
                                         "TrackID     INTEGER PRIMARY KEY, "     // Номер трека (ключ)
                                         "Duration    INTEGER, "                 // Длительность (в секундах)
                                         "Bitrate     INTEGER, "                 // Битрейт (kbps)
                                         "SampleRate  INTEGER, "                 // Частота сэмплов (hz)
                                         "ChannelsNum INTEGER"                   // Количество каналов
                                         ")";
    query.exec(MetaDataTableCreationQuery);

    // **********************************************************
    //  Создание таблицы TagData для хранения информации
    //  о ID3-данных трека: названия трека, номера исполнителя,
    //  номера альбома, номера трека, композитора и номера диска.
    // **********************************************************

    QString TagDataTableCreationQuery = "CREATE TABLE IF NOT EXISTS TagData ("
                                        "TrackID     INTEGER PRIMARY KEY, "    // Номер трека (ключ)
                                        "Title       TEXT, "                   // Название трека
                                        "ArtistID    INTEGER, "                // Номер исполнителя (внешний ключ)
                                        "AlbumID     INTEGER, "                // Номер альбома     (внешний ключ)
                                        "TrackNumber INTEGER, "                // Номер трека
                                        "Composer    TEXT, "                   // Композитор
                                        "DiscNumber  INTEGER"                  // Номер диска
                                        ")";
    query.exec(TagDataTableCreationQuery);

    // ****************************************************************
    //  Создание таблицы TrackStats для хранения информации
    //  о статистике воспроизведений трека: числа прослушиваний,
    //  является ли трек понравившимся, времени первого прослушивания,
    //  времени последнего прослушивания.
    // ****************************************************************

    QString TrackStatsTableCreationQuery = "CREATE TABLE IF NOT EXISTS TrackStats ("
                                           "TrackID         INTEGER PRIMARY KEY, "   // Номер трека (ключ)
                                           "Count           INTEGER, "               // Количество прослушиваний
                                           "Like            BOOL, "                  // Является ли трек понравившимся (стоит ли "лайк")
                                           "FirstTimePlayed DATETIME, "              // Дата-время первого прослушивания
                                           "LastTimePlayed  DATETIME"                // Дата-время последнего прослушивания
                                           ")";
    query.exec(TrackStatsTableCreationQuery);

    // **********************************************************
    //  Создание таблицы ListenHistory для хранения информации о
    //  истории прослушиваний: номера прослушанного трека и
    //  даты-времени прослушивания.
    // **********************************************************

    QString ListenHistoryTableCreationQuery = "CREATE TABLE IF NOT EXISTS ListenHistory ("
                                              "PlayID   INTEGER PRIMARY KEY, "             // Номер прослушивания (ключ)
                                              "TrackID  INTEGER, "                         // Номер трека (внешний ключ)
                                              "DateTime DATETIME"                          // Дата-время прослушивания
                                              ")";
    query.exec(ListenHistoryTableCreationQuery);

    // ****************************************************
    //  Создание таблицы Artist для хранения информации об
    //  исполнителе: имени исполнителя, биографии, жанра,
    //  в котором он исполняет, и номера фотографии.
    // ****************************************************

    QString ArtistTableCreationQuery = "CREATE TABLE IF NOT EXISTS Artist ("
                                       "ArtistID INTEGER PRIMARY KEY, "      // Номер исполнителя (ключ)
                                       "Name     TEXT, "                     // Имя исполнителя
                                       "Bio      TEXT, "                     // Биография
                                       "Genre    TEXT, "                     // Основной жанр (стиль)
                                       "PhotoID  INTEGER"                    // Номер фотографии (внешний ключ)
                                       ")";
    query.exec(ArtistTableCreationQuery);

    // ******************************************************
    //  Создание таблицы ArtistStats для хранения информации
    //  о статистике исполнителя: количества прослушиваний,
    //  времени первого прослушивания, времени последнего
    //  прослушивания.
    // ******************************************************

    QString ArtistStatsTableCreationQuery = "CREATE TABLE IF NOT EXISTS ArtistStats ("
                                            "ArtistID        INTEGER PRIMARY KEY, "    // Номер исполнителя (ключ)
                                            "Count           INTEGER, "                // Количество прослушиваний
                                            "FirstTimePlayed DATETIME, "               // Дата-время первого прослушивания
                                            "LastTimePlayed  DATETIME"                 // Дата-время последнего прослушивания
                                            ")";
    query.exec(ArtistStatsTableCreationQuery);

    // ***********************************************************
    //  Создание таблицы Photos для хранения информации
    //  о фотографии исполнителя: пути к файлу фотографии,
    //  размера файла, формата изображения и размера изображения.
    // ***********************************************************

    QString PhotosTableCreationQuery = "CREATE TABLE IF NOT EXISTS Photos ("
                                       "PhotoID     INTEGER PRIMARY KEY, "   // Номер фотографии (ключ)
                                       "FilePath    TEXT, "                  // Путь к файлу
                                       "FileSize    INTEGER, "               // Размер файла
                                       "Format      TEXT, "                  // Формат изображения
                                       "ImageHeight INTEGER, "               // Высота изображения
                                       "ImageWidth  INTEGER"                 // Ширина изображения
                                       ")";
    query.exec(PhotosTableCreationQuery);

    // ************************************************************
    //  Создание таблицы Album для хранения информации об альбоме:
    //  номера исполнителя, длительности, года выпуска, жанра
    //  (стиля), количества треков в альбоме, количества дисков и
    //  номера обложки.
    // ************************************************************

    QString AlbumTableCreationQuery = "CREATE TABLE IF NOT EXISTS Album ("
                                      "AlbumID      INTEGER PRIMARY KEY, " // Номер альбома (ключ)
                                      "ArtistID     INTEGER, "             // Номер исполнителя альбома (внешний ключ)
                                      "Duration     INTEGER, "             // Длительность альбома
                                      "Year         INTEGER, "             // Год выпуска альбома
                                      "Genre        TEXT, "                // Жанр (стиль) альбома
                                      "TracksNumber INTEGER, "             // Количество треков на альбоме
                                      "DiscsNumber  INTEGER, "             // Количество дисков
                                      "CoverID      INTEGER"               // Номер обложки альбома
                                      ")";
    query.exec(AlbumTableCreationQuery);

    // **********************************************************
    //  Создание таблицы AlbumStats для хранения информации о
    //  статистике альбома: количества прослушиваний, времени
    //  первого прослушивания, времени последнего прослушивания.
    // **********************************************************

    QString AlbumStatsTableCreationQuery = "CREATE TABLE IF NOT EXISTS AlbumStats ("
                                           "AlbumID         INTEGER PRIMARY KEY, "   // Номер альбома (ключ)
                                           "Count           INTEGER, "               // Количество прослушиваний
                                           "FirstTimePlayed DATETIME, "              // Дата-время первого прослушивания
                                           "LastTimePlayed  DATETIME"                // Дата-время последнего прослушивания
                                           ")";
    query.exec(AlbumStatsTableCreationQuery);

    // **********************************************************
    //  Создание таблицы CoverArt для хранения информации об
    //  обложке альбома: пути к файлу фотографии, размера файла,
    //  формата изображения и размера изображения.
    // **********************************************************

    QString CoverArtTableCreationQuery = "CREATE TABLE IF NOT EXISTS CoverArt ("
                                         "AlbumID     INTEGER PRIMARY KEY, "     // Номер альбома (ключ)
                                         "FilePath    TEXT, "                    // Путь к файлу
                                         "FileSize    INTEGER, "                 // Размер файла
                                         "Format      TEXT, "                    // Формат изображения
                                         "ImageHeight INTEGER, "                 // Высота изображения
                                         "ImageWidth  INTEGER"                   // Ширина изображения
                                         ")";
    query.exec(CoverArtTableCreationQuery);
}

bool DatabaseManager::prepareFolders()
{
    QDir currentDirectory = QDir::current();
    QDir dir(currentDirectory.absolutePath() + "/data");
    if(!dir.exists())
        return currentDirectory.mkdir("data");
    else
        return true;
}
