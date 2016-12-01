#include "artist.h"

Artist::Artist()
{
    m_name      = QString();
    m_biography = QString();
    m_genre     = QString();
    m_photo     = ArtistPhoto();
}

Artist::Artist(const QString     artistName,
               const QString     artistBiography = QString(),
               const QString     artistGenre     = QString(),
               const ArtistPhoto artistPhoto     = ArtistPhoto())
{
    m_name      = artistName;
    m_biography = artistBiography;
    m_genre     = artistGenre;
    m_photo     = artistPhoto;
}
