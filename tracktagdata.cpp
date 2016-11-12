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
    m_year        = QString();
    m_genre       = QString();
    m_albumArtist = QString();
    m_composer    = QString();

    m_trackNumber = 0;
    m_discNumber  = 0;
}

// **************************************************************
//
//  Инициализация объекта тэг-данных с полным набором информации
//
// **************************************************************

TrackTagData::TrackTagData(const QString trackTitle,       // Название трека
                           int           trackNumber,      // Номер трека
                           const QString trackArtist,      // Исполнитель
                           const QString trackAlbum,       // Альбом
                           const QString trackYear,        // Год
                           const QString trackGenre,       // Жанр
                           const QString trackAlbumArtist, // Исполнитель альбома
                           const QString trackComposer,    // Композитор
                           int           trackDiscNumber   // Номер диска
                          )
{
    m_title       = trackTitle;
    m_artist      = trackArtist;
    m_albumName   = trackAlbum;
    m_year        = trackYear;
    m_genre       = trackGenre;
    m_albumArtist = trackAlbumArtist;
    m_composer    = trackComposer;

    if(trackNumber > 0)
        m_trackNumber = trackNumber;
    else
        m_trackNumber = 0;

    if(trackNumber > 0)
        m_discNumber = trackDiscNumber;
    else
        m_discNumber = 0;
}

// ****************************************
//
//  Управление полем "Исполнитель альбома"
//
// ****************************************

const QString TrackTagData::getAlbumArtist()
{
    return m_albumArtist;
}

bool TrackTagData::setAlbumArtist(const QString trackAlbumArtist)
{
    if(m_albumArtist != trackAlbumArtist)
    {
        m_albumArtist = trackAlbumArtist;
        return true;
    }
    else
        return false;
}

// ***************************
//
//  Управление полем "Альбом"
//
// ***************************

const QString TrackTagData::getAlbumName()
{
    return m_albumName;
}

bool TrackTagData::setAlbumName(const QString trackAlbumName)
{
    if(m_albumName != trackAlbumName)
    {
        m_albumName = trackAlbumName;
        return true;
    }
    else
        return false;
}

// ********************************
//
//  Управление полем "Исполнитель"
//
// ********************************

const QString TrackTagData::getArtist()
{
    return m_artist;
}

bool TrackTagData::setArtist(const QString trackArtist)
{
    if(m_artist != trackArtist)
    {
        m_artist = trackArtist;
        return true;
    }
    else
        return false;
}

// *****************************
//
//  Управление полем "Название"
//
// *****************************

const QString TrackTagData::getTitle()
{
    return m_title;
}

bool TrackTagData::setTitle(const QString trackTitle)
{
    if(m_title != trackTitle)
    {
        m_title = trackTitle;
        return true;
    }
    else
        return false;
}

// ************************
//
//  Управление полем "Год"
//
// ************************

const QString TrackTagData::getYear()
{
    return m_year;
}

bool TrackTagData::setYear(const QString trackYear)
{
    if(m_year != trackYear)
    {
        m_year = trackYear;
        return true;
    }
    else
        return false;
}

// *************************
//
//  Управление полем "Жанр"
//
// *************************

const QString TrackTagData::getGenre()
{
    return m_genre;
}

bool TrackTagData::setGenre(const QString trackGenre)
{
    if(m_genre != trackGenre)
    {
        m_genre = trackGenre;
        return true;
    }
    else
        return false;
}

// *************************
//
//  Управление полем "Композитор"
//
// *************************

const QString TrackTagData::getComposer()
{
    return m_composer;
}

bool TrackTagData::setComposer(const QString trackComposer)
{
    if(m_composer != trackComposer)
    {
        m_composer = trackComposer;
        return true;
    }
    else
        return false;
}

// **************************
//
//  Управление полем "Номер"
//
// **************************

int TrackTagData::getTrackNumber()
{
    return m_trackNumber;
}

bool TrackTagData::setTrackNumber(const int trackNumber)
{
    if(m_trackNumber != trackNumber && trackNumber > 0)
    {
        m_trackNumber = trackNumber;
        return true;
    }
    else
        return false;
}

// ********************************
//
//  Управление полем "Номер диска"
//
// ********************************

int TrackTagData::getDiscNumber()
{
    return m_discNumber;
}

bool TrackTagData::setDiscNumber(const int trackDiscNumber)
{
    if(m_discNumber != trackDiscNumber && trackDiscNumber > 0)
    {
        m_discNumber = trackDiscNumber;
        return true;
    }
    else
        return false;
}
