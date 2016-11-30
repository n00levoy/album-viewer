#include "databasemanager.h"

#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

DatabaseManager::DatabaseManager()
{
    m_database = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    m_database->setUserName("user");
    m_database->setHostName("localpc");
    m_database->setPassword("password");

    prepareFolders();

    QString databaseName = "data/";
    databaseName += "music";
    databaseName += ".sqlite";

    m_database->setDatabaseName(databaseName);

    if (!m_database->open())
        qDebug() << "Cannot open DB: " << m_database->lastError();
    else
        prepareTables();
}

// ****************************************************
//
//  Деструктор объекта управления базой данных
//  Освобождение памяти указателя на объект управления
//
// ****************************************************

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

    // ***************************************************
    //  Создание таблицы FileInfo для хранения информации
    //  о файле: пути к файлу и размера файла.
    // ***************************************************

    QString fileInfoTableCreationQuery = "CREATE TABLE IF NOT EXISTS FileInfo ("
                                         "TrackID  INTEGER PRIMARY KEY, "        // Номер трека (ключ)
                                         "FilePath TEXT    NOT NULL, "           // Путь к файлу
                                         "FileSize INTEGER NOT NULL"             // Размер файла (в байтах)
                                         ")";
    bool fileInfoCreationResult = query.exec(fileInfoTableCreationQuery);
    if(!fileInfoCreationResult)
        return false;

    // ***************************************************
    //  Создание таблицы MetaData для хранения информации
    //  о мета-данных трека: длительности, битрейта,
    //  частоты сэмплов и количества каналов.
    // ***************************************************

    QString metaDataTableCreationQuery = "CREATE TABLE IF NOT EXISTS MetaData ("
                                         "TrackID     INTEGER PRIMARY KEY, "     // Номер трека (ключ)
                                         "Duration    INTEGER, "                 // Длительность (в секундах)
                                         "Bitrate     INTEGER, "                 // Битрейт (kbps)
                                         "SampleRate  INTEGER, "                 // Частота сэмплов (hz)
                                         "ChannelsNum INTEGER"                   // Количество каналов
                                         ")";
    bool metaDataCreationResult = query.exec(metaDataTableCreationQuery);
    if(!metaDataCreationResult)
        return false;

    // **********************************************************
    //  Создание таблицы TagData для хранения информации
    //  о ID3-данных трека: названия трека, номера исполнителя,
    //  номера альбома, номера трека, композитора и номера диска.
    // **********************************************************

    QString tagDataTableCreationQuery = "CREATE TABLE IF NOT EXISTS TagData ("
                                        "TrackID     INTEGER PRIMARY KEY, "    // Номер трека (ключ)
                                        "Title       TEXT, "                   // Название трека
                                        "ArtistID    INTEGER, "                // Номер исполнителя (внешний ключ)
                                        "AlbumID     INTEGER, "                // Номер альбома     (внешний ключ)
                                        "TrackNumber INTEGER, "                // Номер трека
                                        "Composer    TEXT, "                   // Композитор
                                        "DiscNumber  INTEGER"                  // Номер диска
                                        ")";
    bool tagDataCreationResult = query.exec(tagDataTableCreationQuery);
    if(!tagDataCreationResult)
        return false;

    // ****************************************************************
    //  Создание таблицы TrackStats для хранения информации
    //  о статистике воспроизведений трека: числа прослушиваний,
    //  является ли трек понравившимся, времени первого прослушивания,
    //  времени последнего прослушивания.
    // ****************************************************************

    QString trackStatsTableCreationQuery = "CREATE TABLE IF NOT EXISTS TrackStats ("
                                           "TrackID         INTEGER PRIMARY KEY, "   // Номер трека (ключ)
                                           "Count           INTEGER, "               // Количество прослушиваний
                                           "Like            BOOL, "                  // Является ли трек понравившимся (стоит ли "лайк")
                                           "FirstTimePlayed DATETIME, "              // Дата-время первого прослушивания
                                           "LastTimePlayed  DATETIME"                // Дата-время последнего прослушивания
                                           ")";
    bool trackStatsCreationResult = query.exec(trackStatsTableCreationQuery);
    if(!trackStatsCreationResult)
        return false;

    // **********************************************************
    //  Создание таблицы ListenHistory для хранения информации о
    //  истории прослушиваний: номера прослушанного трека и
    //  даты-времени прослушивания.
    // **********************************************************

    QString listenHistoryTableCreationQuery = "CREATE TABLE IF NOT EXISTS ListenHistory ("
                                              "PlayID   INTEGER PRIMARY KEY, "             // Номер прослушивания (ключ)
                                              "TrackID  INTEGER, "                         // Номер трека (внешний ключ)
                                              "DateTime DATETIME"                          // Дата-время прослушивания
                                              ")";
    bool listenHistoryCreationResult = query.exec(listenHistoryTableCreationQuery);
    if(!listenHistoryCreationResult)
        return false;

    // ****************************************************
    //  Создание таблицы Artist для хранения информации об
    //  исполнителе: имени исполнителя, биографии, жанра,
    //  в котором он исполняет, и номера фотографии.
    // ****************************************************

    QString artistTableCreationQuery = "CREATE TABLE IF NOT EXISTS Artist ("
                                       "ArtistID INTEGER PRIMARY KEY, "      // Номер исполнителя (ключ)
                                       "Name     TEXT, "                     // Имя исполнителя
                                       "Bio      TEXT, "                     // Биография
                                       "Genre    TEXT, "                     // Основной жанр (стиль)
                                       "PhotoID  INTEGER"                    // Номер фотографии (внешний ключ)
                                       ")";
    bool artistCreationResult = query.exec(artistTableCreationQuery);
    if(!artistCreationResult)
        return false;

    // ******************************************************
    //  Создание таблицы ArtistStats для хранения информации
    //  о статистике исполнителя: количества прослушиваний,
    //  времени первого прослушивания, времени последнего
    //  прослушивания.
    // ******************************************************

    QString artistStatsTableCreationQuery = "CREATE TABLE IF NOT EXISTS ArtistStats ("
                                            "ArtistID        INTEGER PRIMARY KEY, "    // Номер исполнителя (ключ)
                                            "Count           INTEGER, "                // Количество прослушиваний
                                            "FirstTimePlayed DATETIME, "               // Дата-время первого прослушивания
                                            "LastTimePlayed  DATETIME"                 // Дата-время последнего прослушивания
                                            ")";
    bool artistStatsCreationResult = query.exec(artistStatsTableCreationQuery);
    if(!artistStatsCreationResult)
        return false;

    // ***********************************************************
    //  Создание таблицы Photos для хранения информации
    //  о фотографии исполнителя: пути к файлу фотографии,
    //  размера файла, формата изображения и размера изображения.
    // ***********************************************************

    QString photosTableCreationQuery = "CREATE TABLE IF NOT EXISTS Photos ("
                                       "PhotoID     INTEGER PRIMARY KEY, "   // Номер фотографии (ключ)
                                       "FilePath    TEXT, "                  // Путь к файлу
                                       "FileSize    INTEGER, "               // Размер файла
                                       "Format      TEXT, "                  // Формат изображения
                                       "ImageHeight INTEGER, "               // Высота изображения
                                       "ImageWidth  INTEGER"                 // Ширина изображения
                                       ")";
    bool photosCreationResult = query.exec(photosTableCreationQuery);
    if(!photosCreationResult)
        return false;

    // ************************************************************
    //  Создание таблицы Album для хранения информации об альбоме:
    //  номера исполнителя, длительности, года выпуска, жанра
    //  (стиля), количества треков в альбоме, количества дисков и
    //  номера обложки.
    // ************************************************************

    QString albumTableCreationQuery = "CREATE TABLE IF NOT EXISTS Album ("
                                      "AlbumID      INTEGER PRIMARY KEY, " // Номер альбома (ключ)
                                      "ArtistID     INTEGER, "             // Номер исполнителя альбома (внешний ключ)
                                      "Duration     INTEGER, "             // Длительность альбома
                                      "Year         INTEGER, "             // Год выпуска альбома
                                      "Genre        TEXT, "                // Жанр (стиль) альбома
                                      "TracksNumber INTEGER, "             // Количество треков на альбоме
                                      "DiscsNumber  INTEGER, "             // Количество дисков
                                      "CoverID      INTEGER"               // Номер обложки альбома
                                      ")";
    bool albumCreationResult = query.exec(albumTableCreationQuery);
    if(!albumCreationResult)
        return false;

    // **********************************************************
    //  Создание таблицы AlbumStats для хранения информации о
    //  статистике альбома: количества прослушиваний, времени
    //  первого прослушивания, времени последнего прослушивания.
    // **********************************************************

    QString albumStatsTableCreationQuery = "CREATE TABLE IF NOT EXISTS AlbumStats ("
                                           "AlbumID         INTEGER PRIMARY KEY, "   // Номер альбома (ключ)
                                           "Count           INTEGER, "               // Количество прослушиваний
                                           "FirstTimePlayed DATETIME, "              // Дата-время первого прослушивания
                                           "LastTimePlayed  DATETIME"                // Дата-время последнего прослушивания
                                           ")";
    bool albumStatsCreationResult = query.exec(albumStatsTableCreationQuery);
    if(!albumStatsCreationResult)
        return false;

    // **********************************************************
    //  Создание таблицы CoverArt для хранения информации об
    //  обложке альбома: пути к файлу фотографии, размера файла,
    //  формата изображения и размера изображения.
    // **********************************************************

    QString coverArtTableCreationQuery = "CREATE TABLE IF NOT EXISTS CoverArt ("
                                         "AlbumID     INTEGER PRIMARY KEY, "     // Номер альбома (ключ)
                                         "FilePath    TEXT, "                    // Путь к файлу
                                         "FileSize    INTEGER, "                 // Размер файла
                                         "Format      TEXT, "                    // Формат изображения
                                         "ImageHeight INTEGER, "                 // Высота изображения
                                         "ImageWidth  INTEGER"                   // Ширина изображения
                                         ")";
    bool coverArtCreationResult = query.exec(coverArtTableCreationQuery);
    if(!coverArtCreationResult)
        return false;

    return true;
}

// ******************************************************************
//
//  Подготовка директорий на диске для работы с базой данных
//  (проверка существования директории и её создание при отсутствии)
//
// ******************************************************************

bool DatabaseManager::addTrack(const TrackInfo &trackInfo)
{
    QSqlQuery query(*m_database);

    TrackFileInfo fileInfo = trackInfo.getFileInfo();
    auto filePath = fileInfo.getFilePath();
    auto fileSize = fileInfo.getSizeInBytes();
    QString fileInfoInsertQuery = "INSERT INTO FileInfo (FilePath, FileSize) VALUES ('%1', %2)";
    fileInfoInsertQuery = fileInfoInsertQuery.arg(filePath)
                                             .arg(fileSize);
    query.exec(fileInfoInsertQuery);

    TrackMetaData metaData = trackInfo.getMetaData();
    auto duration    = metaData.getDuration();
    auto bitrate     = metaData.getBitrate();
    auto sampleRate  = metaData.getSampleRate();
    auto channelsNum = metaData.getChannelsNum();
    QString metaDataInsertQuery = "INSERT INTO MetaData (Duration, Bitrate, SampleRate, ChannelsNum) VALUES (%1, %2, %3, %4)";
    metaDataInsertQuery = metaDataInsertQuery.arg(duration)
                                             .arg(bitrate)
                                             .arg(sampleRate)
                                             .arg(channelsNum);
    query.exec(metaDataInsertQuery);

//    QTableView *view = new QTableView;
//    view->setAttribute(Qt::WA_DeleteOnClose);
//    QSqlQueryModel* model = new QSqlQueryModel(view);
//    model->setQuery("SELECT * FROM FileInfo");
//    view->setModel(model);
//    view->show();

    return true;
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
