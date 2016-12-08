#ifndef ARTIST_H
#define ARTIST_H

#include <QtCore>

#include "musicimage.h"

// ************************************************
//
//  Класс-контейнер для информации об исполнителе.
//
// ************************************************

class Artist
{
public:
    // ***************************
    //  Создание пустого объекта.
    // ***************************

    Artist();

    // *********************************************
    //  Создание объекта исполнителя с информацией.
    // *********************************************

    Artist(const QString    artistName,
           const QString    artistBiography = QString(),
           const QString    artistGenre     = QString(),
           const MusicImage artistPhoto     = MusicImage());

    // *****************
    //  Методы доступа.
    // *****************

    QString getName() const;
    void    setName(const QString artistName);

    QString getBiography() const;
    void    setBiography(const QString artistBiography);

    QString getGenre() const;
    void    setGenre(const QString artistGenre);

    MusicImage getPhoto() const;
    void       setPhoto(const MusicImage artistPhoto);

private:
    QString    m_name;      // Имя (название) исполнителя
    QString    m_biography; // Биография исполнителя
    QString    m_genre;     // Основной жанр исполнителя
    MusicImage m_photo;     // Фотография исполнителя
};

#endif // ARTIST_H
