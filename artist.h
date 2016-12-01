#ifndef ARTIST_H
#define ARTIST_H

#include <QtCore>

class ArtistPhoto;

class Artist
{
public:
    Artist();

    Artist(const QString     artistName,
           const QString     artistBiography = QString(),
           const QString     artistGenre     = QString(),
           const ArtistPhoto artistPhoto     = ArtistPhoto());

private:
    QString     m_name;
    QString     m_biography;
    QString     m_genre;
    ArtistPhoto m_photo;
};

#endif // ARTIST_H
