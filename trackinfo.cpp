#include "trackinfo.h"

TrackInfo::TrackInfo()
{
    m_albumArtist = QString();
    m_albumName   = QString();
    m_artist      = QString();
    m_title       = QString();
    m_year        = QString();
    m_genre       = QString();

    m_trackNumber = 0;
    m_discNumber  = 0;

    m_coverArt = QImage();
}

const QString TrackInfo::getAlbumArtist()
{
    return m_albumArtist;
}

bool TrackInfo::setAlbumArtist(const QString trackAlbumArtist)
{
    if(m_albumArtist != trackAlbumArtist)
    {
        m_albumArtist = trackAlbumArtist;
        return true;
    }
    else
        return false;
}

const QString TrackInfo::getAlbumName()
{
    return m_albumName;
}

bool TrackInfo::setAlbumName(const QString trackAlbumName)
{
    if(m_albumName != trackAlbumName)
    {
        m_albumName = trackAlbumName;
        return true;
    }
    else
        return false;
}

const QString TrackInfo::getArtist()
{
    return m_artist;
}

bool  TrackInfo::setArtist(const QString trackArtist)
{
    if(m_artist != trackArtist)
    {
        m_artist = trackArtist;
        return true;
    }
    else
        return false;
}

const QString TrackInfo::getTitle()
{
    return m_title;
}

bool TrackInfo::setTitle(const QString trackTitle)
{
    if(m_title != trackTitle)
    {
        m_title = trackTitle;
        return true;
    }
    else
        return false;
}

const QString TrackInfo::getYear()
{
    return m_year;
}

bool TrackInfo::setYear(const QString trackYear)
{
    if(m_year != trackYear)
    {
        m_year = trackYear;
        return true;
    }
    else
        return false;
}

const QString TrackInfo::getGenre()
{
    return m_genre;
}

bool TrackInfo::setGenre(const QString trackGenre)
{
    if(m_genre != trackGenre)
    {
        m_genre = trackGenre;
        return true;
    }
    else
        return false;
}

int TrackInfo::getTrackNumber()
{
    return m_trackNumber;
}

bool TrackInfo::setTrackNumber(const int trackNumber)
{
    if(m_trackNumber != trackNumber && trackNumber > 0)
    {
        m_trackNumber = trackNumber;
        return true;
    }
    else
        return false;
}

int TrackInfo::getDiscNumber()
{
    return m_discNumber;
}

bool TrackInfo::setDiscNumber(const int trackDiscNumber)
{
    if(m_discNumber != trackDiscNumber && trackDiscNumber > 0)
    {
        m_discNumber = trackDiscNumber;
        return true;
    }
    else
        return false;
}

const QImage TrackInfo::getCoverArt()
{
    return m_coverArt;
}

bool TrackInfo::setCoverArt(const QImage trackCoverArt)
{
    if(m_coverArt != trackCoverArt)
    {
        m_coverArt = trackCoverArt;
        return true;
    }
    else
        return false;
}
