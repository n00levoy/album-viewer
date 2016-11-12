#ifndef TRACKINFO_H
#define TRACKINFO_H

#include <QString>
#include <QImage>

class TrackInfo
{
public:
    TrackInfo();

    const QImage getCoverArt();
    bool         setCoverArt(const QImage trackCoverArt);

private:
    QImage m_coverArt;

};

#endif // TRACKINFO_H
