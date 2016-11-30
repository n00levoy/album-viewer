#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtCore>
#include <QSqlDatabase>

#include "trackinfo.h"

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

    QSqlDatabase* m_database;
};

#endif // DATABASEMANAGER_H
