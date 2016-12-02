#include "trackfileinfo.h"

// **************************************************************************
//
//  Инициализация пустого объекта информации о файле, содержащем аудиоданные
//
// **************************************************************************

TrackFileInfo::TrackFileInfo()
{
    m_filePath    = QString();
    m_sizeInBytes = 0;
}

// *********************************************************************************
//
//  Инициализация объекта полным набором информации о файле, содержащем аудиоданные
//
// *********************************************************************************

TrackFileInfo::TrackFileInfo(const QString trackFilePath,     // Размер файла в байтах
                             const qlonglong trackSizeInBytes // Путь к файлу (абсолютное имя файла)
                            )
{
    m_filePath = trackFilePath;

    if(trackSizeInBytes > 0)
        m_sizeInBytes = trackSizeInBytes;
    else
        m_sizeInBytes = 0;
}

// ***************************************
//
//  Доступ к полю "Размер файла в байтах"
//
// ***************************************

qlonglong TrackFileInfo::getSizeInBytes() const
{
    return m_sizeInBytes;
}

void TrackFileInfo::setSizeInBytes(const qlonglong trackSizeInBytes)
{
    if(trackSizeInBytes > 0)
        m_sizeInBytes = trackSizeInBytes;
    else
        m_sizeInBytes = 0;
}

// *****************************************************
//
//  Доступ к полю "Путь к файлу (абсолютное имя файла)"
//
// *****************************************************

QString TrackFileInfo::getFilePath() const
{
    return m_filePath;
}

void TrackFileInfo::setFilePath(const QString trackFilePath)
{
    m_filePath = trackFilePath;
}
