#include "album.h"

// ****************************************
//
//  Инициализация пустого объекта альбома.
//
// ****************************************

Album::Album()
{
    m_albumName  = QString();
    m_artistName = QString();
    m_genre      = QString();

    m_tracksNumber = 0;
    m_discsNumber  = 0;
    m_duration     = 0;
    m_year         = 0;

    m_coverArt = MusicImage();
}

// ******************************************
//
//  Инициализация объекта альбома значением.
//
// ******************************************

Album::Album(const QString    albumName,    // Название альбома
             const QString    artistName,   // Исполнитель альбома
             const qlonglong  duration,     // Длительность альбома
             const int        year,         // Год альбома
             const QString    genre,        // Жанр альбома
             const int        tracksNumber, // Количество треков на альбоме
             const int        discsNumber,  // Количество дисков в альбоме
             const MusicImage coverArt      // Обложка альбома
             )
{
    m_albumName  = albumName;
    m_artistName = artistName;
    m_genre      = genre;

    setDuration(duration);
    setYear    (year);
    setTracksNumber(tracksNumber);
    setDiscsNumber (discsNumber);

    m_coverArt = coverArt;
}

// ***********************************
//
//  Доступ к полю "Название альбома".
//
// ***********************************

QString Album::getAlbumName() const
{
    return m_albumName;
}

void Album::setAlbumName(const QString albumName)
{
    m_albumName = albumName;
}

// **********************************
//
//  Доступ к полю "Имя исполнителя".
//
// **********************************

QString Album::getArtistName() const
{
    return m_artistName;
}

void Album::setArtistName(const QString artistName)
{
    m_artistName = artistName;
}

// ***************************************
//
//  Доступ к полю "Длительность альбома".
//
// ***************************************

qlonglong Album::getDuration() const
{
    return m_duration;
}

void Album::setDuration(const qlonglong duration)
{
    if(duration > 0)
        m_duration = duration;
    else
        m_duration = 0;
}

// ******************************
//
//  Доступ к полю "Год выпуска".
//
// ******************************

int Album::getYear() const
{
    return m_year;
}

void Album::setYear(const int year)
{
    if(year > 0)
        m_year = year;
    else
        m_year = 0;
}

// *******************************
//
//  Доступ к полю "Жанр альбома".
//
// *******************************

QString Album::getGenre() const
{
    return m_genre;
}

void Album::setGenre(const QString genre)
{
    m_genre = genre;
}

// ***********************************************
//
//  Доступ к полю "Количество треков на альбоме".
//
// ***********************************************

int Album::getTracksNumber() const
{
    return m_tracksNumber;
}

void Album::setTracksNumber(const int tracksNumber)
{
    if(tracksNumber > 0)
        m_tracksNumber = tracksNumber;
    else
        m_tracksNumber = 0;
}

// ********************************************
//
//  Доступ к полю "Количество дисков альбома".
//
// ********************************************

int Album::getDiscsNumber() const
{
    return m_discsNumber;
}

void Album::setDiscsNumber(const int discsNumber)
{
    if(discsNumber > 0)
        m_discsNumber = discsNumber;
    else
        m_discsNumber = 0;
}

// *************************************
//
//  Доступ к объекту "Обложка альбома".
//
// *************************************

MusicImage Album::getCoverArt() const
{
    return m_coverArt;
}

void Album::setCoverArt(const MusicImage coverArt)
{
    m_coverArt = coverArt;
}
