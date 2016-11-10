#ifndef TRACKINFO_H
#define TRACKINFO_H

#include <QString>
#include <QImage>

class TrackInfo
{
public:
    TrackInfo();

    const QString getAlbumArtist();
    bool          setAlbumArtist(const QString trackAlbumArtist);

    const QString getAlbumName();
    bool          setAlbumName(const QString trackAlbumName);

    const QString getArtist();
    bool          setArtist(const QString trackArtist);

    const QString getTitle();
    bool          setTitle(const QString trackTitle);

    const QString getYear();
    bool          setYear(const QString trackYear);

    const QString getGenre();
    bool          setGenre(const QString trackGenre);

    int  getTrackNumber();
    bool setTrackNumber(const int trackNumber);

    int  getDiscNumber();
    bool setDiscNumber(const int trackDiscNumber);

    const QImage getCoverArt();
    bool         setCoverArt(const QImage trackCoverArt);

private:
    QString m_albumArtist;
    QString m_albumName;
    QString m_artist;
    QString m_title;
    QString m_year;
    QString m_genre;

    int m_trackNumber;
    int m_discNumber;

    QImage m_coverArt;

};

#endif // TRACKINFO_H
