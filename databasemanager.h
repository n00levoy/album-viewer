#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtCore>
#include <QSqlDatabase>

// ********************************************
//
//  Класс-менеджер для управления базой данных
//
// ********************************************

class DatabaseManager : public QObject
{
public:

    // *******************************
    //  Перечисление типов баз данных
    // *******************************
    enum databases{DATABASE_ERROR,  // Ошибочный тип
                   DATABASE_MUSIC}; // База данных для музыки

public:
    // ************************************
    //  Создание пустого объекта-менеджера
    // ************************************

    DatabaseManager();

    // ************************************
    //  Создание объекта-менеджера управления БД определённого типа
    // ************************************

    DatabaseManager(int databaseType);
    ~DatabaseManager();

private:
    bool prepareTables();
    bool prepareFolders();

    QSqlDatabase* m_database;
};

#endif // DATABASEMANAGER_H
