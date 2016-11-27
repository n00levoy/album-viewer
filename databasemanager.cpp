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

// ******************************************************************
//
//  Создание и подготовка таблиц в базе данных для дальнейшей работы
//
// ******************************************************************

bool DatabaseManager::prepareTables()
{
    QSqlQuery query(*m_database);

    // ***************************************************
    //  Создание таблицы FileInfo для хранения информации
    //  о файле: пути к файлу и размера файла
    // ***************************************************

    QString FileInfoTableCreationQuery = "CREATE TABLE IF NOT EXISTS FileInfo ("
                                         "TrackID  INTEGER PRIMARY KEY, "           // Номер трека (ключ)
                                         "FilePath TEXT, "                          // Путь к файлу
                                         "FileSize INTEGER"                         // Размер файла (в байтах)
                                         ")";
    query.exec(FileInfoTableCreationQuery);

    // ***************************************************
    //  Создание таблицы MetaData для хранения информации
    //  о мета-данных трека: длительности, битрейта,
    //  частоты сэмплов и количества каналов
    // ***************************************************

    QString MetaDataTableCreationQuery = "CREATE TABLE IF NOT EXISTS MetaData ("
                                         "TrackID     INTEGER PRIMARY KEY, "        // Номер трека (ключ)
                                         "Duration    INTEGER, "                    // Длительность (в секундах)
                                         "Bitrate     INTEGER, "                    // Битрейт (kbps)
                                         "SampleRate  INTEGER, "                    // Частота сэмплов (hz)
                                         "ChannelsNum INTEGER"                      // Количество каналов
                                         ")";
    query.exec(MetaDataTableCreationQuery);

    // **********************************************************
    //  Создание таблицы TagData для хранения информации
    //  о ID3-данных трека: названия трека, номера исполнителя,
    //  номера альбома, номера трека, композитора и номера диска
    // **********************************************************

    QString TagDataTableCreationQuery = "CREATE TABLE IF NOT EXISTS TagData ("
                                        "TrackID     INTEGER PRIMARY KEY, "         // Номер трека (ключ)
                                        "Title       TEXT, "                        // Название трека
                                        "ArtistID    INTEGER, "                     // Номер исполнителя (внешний ключ)
                                        "AlbumID     INTEGER, "                     // Номер альбома     (внешний ключ)
                                        "TrackNumber INTEGER, "                     // Номер трека
                                        "Composer    TEXT, "                        // Композитор
                                        "DiscNumber  INTEGER"                       // Номер диска
                                        ")";
    query.exec(TagDataTableCreationQuery);
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
