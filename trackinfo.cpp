#include "trackinfo.h"
#include "tracktagdata.h"

TrackInfo::TrackInfo()
{
    m_coverArt = QImage();
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


