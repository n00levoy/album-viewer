#include "tracktagdata.h"

// ******************************************
//
//  Инициализация пустого объекта тэг-данных
//
// ******************************************

TrackTagData::TrackTagData()
{
    m_title       = QString();
    m_artist      = QString();
    m_albumName   = QString();
    m_genre       = QString();
    m_albumArtist = QString();
    m_composer    = QString();

    m_trackNumber = 0;
    m_year        = 0;
    m_discNumber  = 0;
}

// **************************************************************
//
//  Инициализация объекта тэг-данных с полным набором информации
//
// **************************************************************

TrackTagData::TrackTagData(const QString trackTitle,       // Название трека
                           const int     trackNumber,      // Номер трека
                           const QString trackArtist,      // Исполнитель
                           const QString trackAlbum,       // Альбом
                           const int     trackYear,        // Год
                           const QString trackGenre,       // Жанр
                           const QString trackAlbumArtist, // Исполнитель альбома
                           const QString trackComposer,    // Композитор
                           const int     trackDiscNumber   // Номер диска
                          )
{
    m_title       = trackTitle;
    m_artist      = trackArtist;
    m_albumName   = trackAlbum;
    m_genre       = trackGenre;
    m_albumArtist = trackAlbumArtist;
    m_composer    = trackComposer;

    if(trackNumber > 0)
        m_trackNumber = trackNumber;
    else
        m_trackNumber = 0;

    if(trackYear > 0)
        m_year = trackYear;
    else
        m_year = 0;

    if(trackNumber > 0)
        m_discNumber = trackDiscNumber;
    else
        m_discNumber = 0;
}

// *************************************
//
//  Доступ к полю "Исполнитель альбома"
//
// *************************************

QString TrackTagData::getAlbumArtist() const
{
    return m_albumArtist;
}

void TrackTagData::setAlbumArtist(const QString trackAlbumArtist)
{
    m_albumArtist = trackAlbumArtist;
}

// ************************
//
//  Доступ к полю "Альбом"
//
// ************************

QString TrackTagData::getAlbumName() const
{
    return m_albumName;
}

void TrackTagData::setAlbumName(const QString trackAlbumName)
{
    m_albumName = trackAlbumName;
}

// *****************************
//
//  Доступ к полю "Исполнитель"
//
// *****************************

QString TrackTagData::getArtist() const
{
    return m_artist;
}

void TrackTagData::setArtist(const QString trackArtist)
{
    m_artist = trackArtist;
}

// **************************
//
//  Доступ к полю "Название"
//
// **************************

QString TrackTagData::getTitle() const
{
    return m_title;
}

void TrackTagData::setTitle(const QString trackTitle)
{
    m_title = trackTitle;
}

// **********************
//
//  Доступ к полю "Жанр"
//
// **********************

QString TrackTagData::getGenre() const
{
    return m_genre;
}

void TrackTagData::setGenre(const QString trackGenre)
{
    m_genre = trackGenre;
}

// ****************************
//
//  Доступ к полю "Композитор"
//
// ****************************

QString TrackTagData::getComposer() const
{
    return m_composer;
}

void TrackTagData::setComposer(const QString trackComposer)
{
    m_composer = trackComposer;
}

// ***********************
//
//  Доступ к полю "Номер"
//
// ***********************

int TrackTagData::getTrackNumber() const
{
    return m_trackNumber;
}

void TrackTagData::setTrackNumber(const int trackNumber)
{
    if(trackNumber > 0)
        m_trackNumber = trackNumber;
    else
        m_trackNumber = 0;
}

// *********************
//
//  Доступ к полю "Год"
//
// *********************

int TrackTagData::getYear() const
{
    return m_year;
}

void TrackTagData::setYear(const int trackYear)
{
    m_year = trackYear;
}

// *****************************
//
//  Доступ к полю "Номер диска"
//
// *****************************

int TrackTagData::getDiscNumber() const
{
    return m_discNumber;
}

void TrackTagData::setDiscNumber(const int trackDiscNumber)
{
    if(trackDiscNumber > 0)
        m_discNumber = trackDiscNumber;
    else
        m_discNumber = 0;
}
