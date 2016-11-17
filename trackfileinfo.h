#ifndef TRACKFILEINFO_H
#define TRACKFILEINFO_H

#include <QtCore>

// *************************************************************
//
//  Класс-хранилище информации о файле, содержащем аудио-данные
//
// *************************************************************

class TrackFileInfo
{
public:
    // **************************
    //  Создание пустого объекта
    // **************************

    TrackFileInfo();

    // **********************************************
    //  Создание объекта с полным набором информации
    // **********************************************

    TrackFileInfo(const QString   trackFilePath,      // Размер файла в байтах
                  const qlonglong trackSizeInBytes    // Путь к файлу (абсолютное имя файла)
                 );

    // ****************
    //  Методы доступа
    // ****************

    qlonglong getSizeInBytes();
    void      setSizeInBytes(const qlonglong trackSizeInBytes);

    const QString getFilePath();
    void          setFilePath(const QString trackFilePath);

private:
    qlonglong m_sizeInBytes; // Размер файла в байтах
    QString   m_filePath;    // Путь к файлу (абсолютное имя файла)
};

#endif // TRACKFILEINFO_H
