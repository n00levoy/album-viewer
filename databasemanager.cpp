#include "databasemanager.h"

#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QTableView>

// ********************************************************************
//
//  Конструктор объекта управления базой данных
//  Соединение с базой данных и подготовка программы для работы с ней.
//
// ********************************************************************

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

// *****************************************************
//
//  Деструктор объекта управления базой данных
//  Освобождение памяти указателя на объект управления.
//
// *****************************************************

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
//  - ArtistPhoto;
//  - Album;
//  - AlbumStats;
//  - CoverArt.
//
// *******************************************************************

bool DatabaseManager::prepareTables()
{
    QSqlQuery query(*m_database);

    // **************************************************
    //  Создание таблицы Tracks для хранения информации
    //  о всех добавляемых в библиотеку треках: названия
    //  трека, исполнителя, альбома, номера трека, даты
    //  добавления и даты удаления.
    // **************************************************

    QString tracksTableCreationQuery = "CREATE TABLE IF NOT EXISTS Tracks ("
                                        "TrackID     INTEGER PRIMARY KEY, "  // Номер трека (ключ)
                                        "Name        TEXT, "                 // Название трека
                                        "Artist      TEXT, "                 // Имя исполнителя
                                        "Album       TEXT, "                 // Название альбома
                                        "TrackNumber INTEGER, "              // Номер трека
                                        "AddDate     DATE, "                 // Дата добавления
                                        "DeleteDate  DATE"                   // Дата удаления
                                        ")";
    bool tracksCreationResult = query.exec(tracksTableCreationQuery);
    if(!tracksCreationResult)
        return false;

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
    //  Создание таблицы ArtistPhoto для хранения информации
    //  о фотографии исполнителя: пути к файлу фотографии,
    //  размера файла, формата изображения и размера изображения.
    // ***********************************************************

    QString artistPhotoTableCreationQuery = "CREATE TABLE IF NOT EXISTS ArtistPhoto ("
                                            "PhotoID     INTEGER PRIMARY KEY, "         // Номер фотографии (ключ)
                                            "FilePath    TEXT, "                        // Путь к файлу
                                            "FileSize    INTEGER, "                     // Размер файла
                                            "Format      TEXT, "                        // Формат изображения
                                            "ImageHeight INTEGER, "                     // Высота изображения
                                            "ImageWidth  INTEGER"                       // Ширина изображения
                                            ")";
    bool artistPhotoCreationResult = query.exec(artistPhotoTableCreationQuery);
    if(!artistPhotoCreationResult)
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

// *******************************************************************
//
//  Подготовка директорий на диске для работы с базой данных
//  (проверка существования директориq и их создание при отсутствии).
//
// *******************************************************************

bool DatabaseManager::prepareFolders()
{
    QDir currentDirectory = QDir::current();
    QDir dataDir(currentDirectory.absolutePath() + "/data");
    bool dataDirExists = dataDir.exists();

    if(!dataDirExists)
        dataDirExists = currentDirectory.mkdir("data");

    if(dataDirExists)
    {
        QDir photosDir(dataDir.absolutePath() + "/photos");
        bool photosDirExists = photosDir.exists();

        if(!photosDirExists)
            photosDirExists = dataDir.mkdir("photos");

        QDir coversDir(dataDir.absolutePath() + "/covers");
        bool coversDirExists = coversDir.exists();

        if(!coversDirExists)
            coversDirExists = dataDir.mkdir("covers");

        if(coversDirExists && photosDirExists)
            return true;
    }
    return false;
}

// *******************************************************************
//
//  Добавление трека в библиотеку с заполнением всех необходимых
//  таблиц (создание исполнителей, альбомов, сохранение изображений).
//
// *******************************************************************

bool DatabaseManager::addTrack(const TrackInfo &trackInfo)
{
    insertFileInfo(trackInfo.getFileInfo());
    insertMetaData(trackInfo.getMetaData());
    insertTagData (trackInfo.getTagData());
    insertTrackStats();

    QTableView *view = new QTableView;
    view->setAttribute(Qt::WA_DeleteOnClose);
    QSqlQueryModel* model = new QSqlQueryModel(view);
    model->setQuery("SELECT * FROM Artist");
    view->setModel(model);
    view->show();

    return true;
}

// *******************************************************
//
//  Добавление файловой информации о треке в базу данных.
//
// *******************************************************

int DatabaseManager::insertFileInfo(const TrackFileInfo &fileInfo)
{
    QSqlQuery query(*m_database);

    auto filePath = fileInfo.getFilePath();
    auto fileSize = fileInfo.getSizeInBytes();
    QString fileInfoInsertQuery = "INSERT INTO FileInfo (FilePath, FileSize) VALUES ('%1', %2)";
    fileInfoInsertQuery = fileInfoInsertQuery.arg(filePath)
                                             .arg(fileSize);
    bool result = query.exec(fileInfoInsertQuery);

    if(result)
        return query.lastInsertId().toInt();

    return result;
}

// *********************************************
//
//  Добавление мета-данных трека в базу данных.
//
// *********************************************

int DatabaseManager::insertMetaData(const TrackMetaData &metaData)
{
    QSqlQuery query(*m_database);

    auto duration    = metaData.getDuration();
    auto bitrate     = metaData.getBitrate();
    auto sampleRate  = metaData.getSampleRate();
    auto channelsNum = metaData.getChannelsNum();
    QString metaDataInsertQuery = "INSERT INTO MetaData (Duration, Bitrate, SampleRate, ChannelsNum) VALUES (%1, %2, %3, %4)";
    metaDataInsertQuery = metaDataInsertQuery.arg(duration)
                                             .arg(bitrate)
                                             .arg(sampleRate)
                                             .arg(channelsNum);
    bool result = query.exec(metaDataInsertQuery);

    if(result)
        return query.lastInsertId().toInt();

    return result;
}

// ********************************************
//
//  Добавление статистики трека в базу данных.
//
// ********************************************

int DatabaseManager::insertTrackStats()
{
    QSqlQuery query(*m_database);

    QString trackStatsInsertQuery = "INSERT INTO TrackStats (Count, Like, FirstTimePlayed, LastTimePlayed) VALUES (%1, %2, %3, %4)";
    trackStatsInsertQuery = trackStatsInsertQuery.arg(0)
                                                 .arg(0)
                                                 .arg(0)
                                                 .arg(0);
    bool result = query.exec(trackStatsInsertQuery);

    if(result)
        return query.lastInsertId().toInt();

    return result;
}

// ********************************************
//
//  Добавление тег-данных трека в базу данных.
//
// ********************************************

int DatabaseManager::insertTagData(const TrackTagData &tagData)
{
    QSqlQuery query(*m_database);

    auto title       = tagData.getTitle();
    auto artistName  = tagData.getArtist();
    auto album       = tagData.getAlbumName();
    auto trackNumber = tagData.getTrackNumber();
    auto year        = tagData.getYear();
    auto genre       = tagData.getGenre();
    auto albumArtist = tagData.getAlbumArtist();
    auto composer    = tagData.getComposer();
    auto discNumber  = tagData.getDiscNumber();

    int artistID = findArtist(artistName);
    if(!artistID)
    {
        Artist artist(artistName);
        artistID = insertArtist(artist);
    }

    int albumArtistID = findArtist(albumArtist);
    if(!albumArtistID)
    {
        Artist artist(albumArtist);
        albumArtistID = insertArtist(artist);
    }

    int albumID = findAlbum(album, artistName);
    if(albumID)
        albumID = insertAlbum(album);

    QString tagDataInsertQuery = "INSERT INTO TagData (Title, ArtistID, AlbumID, TrackNumber, Composer, DiscNumber) "
                                 "VALUES ('%1', %2, %3, %4, '%5', %6)";
    tagDataInsertQuery = tagDataInsertQuery.arg(title)
                                           .arg(artistID)
                                           .arg(albumID)
                                           .arg(trackNumber)
                                           .arg(composer)
                                           .arg(discNumber);
    bool result = query.exec(tagDataInsertQuery);

    if(result)
        return query.lastInsertId().toInt();

    return result;
}

// **********************************
//
//  Поиск исполнителя в базе данных.
//
// **********************************

int DatabaseManager::findArtist(const QString artistName)
{
    QSqlQuery query(*m_database);

    QString queryText = "SELECT * FROM Artist Where Name = '%1'";
    queryText = queryText.arg(artistName);
    bool queryResult = query.exec(queryText);
    if(!queryResult)
        return 0;

    int artistIDFieldNumber = query.record().indexOf("ArtistID");
    int artistID = 0;
    while(query.next())
        artistID = query.value(artistIDFieldNumber).toInt();

    return artistID;
}

// **********************************************
//
//  Добавление нового исполнителя в базу данных.
//
// **********************************************

int DatabaseManager::insertArtist(const Artist artist)
{
    QSqlQuery query(*m_database);

    auto       artistName  = artist.getName();
    auto       biography   = artist.getBiography();
    auto       genre       = artist.getGenre();
    MusicImage photo       = artist.getPhoto();

    int photoID = insertArtistPhoto(photo, artistName);

    QString artistInsertQuery = "INSERT INTO Artist (Name, Bio, Genre, PhotoID) "
                                "VALUES ('%1', '%2', '%3', %4)";
    artistInsertQuery = artistInsertQuery.arg(artistName)
                                         .arg(biography)
                                         .arg(genre)
                                         .arg(photoID);
    bool result = query.exec(artistInsertQuery);

    if(result)
        return query.lastInsertId().toInt();

    return result;
}

// **************************************************
//
//  Добавление статистики исполнителя в базу данных.
//
// **************************************************

int DatabaseManager::insertArtistStats()
{
    QSqlQuery query(*m_database);

    QString artistStatsInsertQuery = "INSERT INTO ArtistStats (Count, FirstTimePlayed, LastTimePlayed) VALUES (%1, %2, %3)";
    artistStatsInsertQuery = artistStatsInsertQuery.arg(0)
                                                   .arg(0)
                                                   .arg(0);
    bool result = query.exec(artistStatsInsertQuery);

    if(result)
        return query.lastInsertId().toInt();

    return result;
}

// **************************************************
//
//  Добавление фотографии исполнителя в базу данных.
//
// **************************************************

int DatabaseManager::insertArtistPhoto(const MusicImage artistPhoto, const QString artistName)
{
    QSqlQuery query(*m_database);

    QString   filePath = QString();
    qlonglong fileSize = 0;
    QString   format   = QString();
    int       height   = 0;
    int       width    = 0;

    if(!artistPhoto.getImage().isNull())
    {
        QImage  photo       = artistPhoto.getImage();
        QString photoFormat = artistPhoto.getImageFormat();

        QString photoFileName = "/data/photos/";
        photoFileName += artistName;
        photoFileName += ".";
        photoFileName += photoFormat.toLower();

        bool saveResult = photo.save(photoFileName, photoFormat.toStdString().c_str());

        if(saveResult)
        {
            filePath = photoFileName;
            fileSize = artistPhoto.getSize();
            format   = photoFormat;
            height   = artistPhoto.getHeight();
            width    = artistPhoto.getWidth();
        }
    }

    QString artistPhotoInsertQuery = "INSERT INTO ArtistPhoto (FilePath, FileSize, Format, ImageHeight, ImageWidth) "
                                     "VALUES (%1, %2, %3, %4, %5)";
    artistPhotoInsertQuery = artistPhotoInsertQuery.arg(filePath)
                                                   .arg(fileSize)
                                                   .arg(format)
                                                   .arg(height)
                                                   .arg(width);
    bool result = query.exec(artistPhotoInsertQuery);

    if(result)
        return query.lastInsertId().toInt();

    return result;
}

// ******************************
//
//  Поиск альбома в базе данных.
//
// ******************************

int DatabaseManager::findAlbum(const QString album, const QString artist)
{
    QSqlQuery query(*m_database);

    return 0;
}

// ***********************************
//
//  Добавление альбома в базу данных.
//
// ***********************************

int DatabaseManager::insertAlbum(const QString album)
{
    QSqlQuery query(*m_database);

    bool result = query.exec("xD");

    if(result)
        return query.lastInsertId().toInt();

    return 0;
}
