#ifndef ALBUM_H
#define ALBUM_H

#include <QtCore>
#include "musicimage.h"

// ********************************************
//
//  Класс-контейнер для информации об альбоме.
//
// ********************************************

class Album
{
public:
    // ***************************
    //  Создание пустого объекта.
    // ***************************

    Album();

    // *****************************************
    //  Создание объекта альбома с информацией.
    // *****************************************

    Album(const QString    albumName,                  // Название альбома
          const QString    artistName,                 // Исполнитель альбома
          const qlonglong  duration     = 0,           // Длительность альбома
          const int        year         = 0,           // Год альбома
          const QString    genre        = QString(),   // Жанр альбома
          const int        tracksNumber = 0,           // Количество треков на альбоме
          const int        discsNumber  = 0,           // Количество дисков в альбоме
          const MusicImage coverArt     = MusicImage() // Обложка альбома
         );

    // *****************
    //  Методы доступа.
    // *****************

    QString getAlbumName() const;
    void    setAlbumName(const QString albumName);

    QString getArtistName() const;
    void    setArtistName(const QString artistName);

    qlonglong getDuration() const;
    void      setDuration(const qlonglong duration);

    int  getYear() const;
    void setYear(const int year);

    QString getGenre() const;
    void    setGenre(const QString genre);

    int  getTracksNumber() const;
    void setTracksNumber(const int tracksNumber);

    int  getDiscsNumber() const;
    void setDiscsNumber(const int discsNumber);

    MusicImage getCoverArt() const;
    void       setCoverArt(const MusicImage coverArt);

private:
    QString    m_albumName;    // Название альбома
    QString    m_artistName;   // Исполнитель альбома
    qlonglong  m_duration;     // Длительность альбома
    int        m_year;         // Год альбома
    QString    m_genre;        // Жанр альбома
    int        m_tracksNumber; // Количество треков на альбоме
    int        m_discsNumber;  // Количество дисков в альбоме
    MusicImage m_coverArt;     // Обложка альбома
};

#endif // ALBUM_H
