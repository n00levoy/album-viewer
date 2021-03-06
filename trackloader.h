#ifndef TRACKLOADER_H
#define TRACKLOADER_H

#include "trackinfo.h"
#include "databasemanager.h"

#include <QVariant>
#include <QDebug>
#include <QFile>
#include <QMediaPlayer>

#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/tpropertymap.h>

class TrackLoader : public QObject
{
    Q_OBJECT
public:
    TrackLoader(QObject *parent = 0);
    Q_INVOKABLE QString loadFromFile(QVariant folder);

    Q_INVOKABLE void play();
    Q_INVOKABLE void pause();

    TrackTagData  loadTagDataFromFile (const QString fileName);
    MusicImage    loadCoverArtFromFile(const QString fileName);
    TrackFileInfo loadFileInfoFromFile(const QString fileName);
    TrackMetaData loadMetaDataFromFile(const QString fileName);

private:
    QString filename;
    QMediaPlayer* player;

public slots:
};

#endif // TRACKLOADER_H
