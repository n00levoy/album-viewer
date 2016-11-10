#ifndef TRACKINFO_H
#define TRACKINFO_H

#include <QtCore>

class TrackInfo
{
public:
    TrackInfo();

    const QString getAlbumArtist();
          bool    setAlbumArtist(const QString albumArtist);

private:
    QString m_albumArtist;
    QString m_albumName;
    QString m_artist;
    QString m_title;
    QString m_year;
    QString m_genre;

    int m_number;
    int m_discNumber;

    QImage m_coverArt;

};

#endif // TRACKINFO_H
