#include "artist.h"

// *******************************************
//
//  Инициализация пустого объекта исполнителя
//
// *******************************************

Artist::Artist()
{
    m_name      = QString();
    m_biography = QString();
    m_genre     = QString();
    m_photo     = MusicImage();
}

// *********************************************
//
//  Инициализация объекта исполнителя значением
//
// *********************************************

Artist::Artist(const QString    artistName,
               const QString    artistBiography,
               const QString    artistGenre,
               const MusicImage artistPhoto)
{
    m_name      = artistName;
    m_biography = artistBiography;
    m_genre     = artistGenre;
    m_photo     = artistPhoto;
}

// **********************************
//
//  Доступ к полю "Имя исполнителя".
//
// **********************************

QString Artist::getName() const
{
    return m_name;
}

void Artist::setName(const QString artistName)
{
    m_name = artistName;
}

// ****************************************
//
//  Доступ к полю "Биография исполнителя".
//
// ****************************************

QString Artist::getBiography() const
{
    return m_biography;
}

void Artist::setBiography(const QString artistBiography)
{
    m_biography = artistBiography;
}

// ***********************************
//
//  Доступ к полю "Жанр исполнителя".
//
// ***********************************

QString Artist::getGenre() const
{
    return m_genre;
}

void Artist::setGenre(const QString artistGenre)
{
    m_genre = artistGenre;
}

// ***********************************************
//
//  Управление объектом "Фотография исполнителя".
//
// ***********************************************

MusicImage Artist::getPhoto() const
{
    return m_photo;
}

void Artist::setPhoto(const MusicImage artistPhoto)
{
    m_photo = artistPhoto;
}
