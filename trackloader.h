#ifndef TRACKLOADER_H
#define TRACKLOADER_H

#include <QObject>
#include <QVariant>
#include <QDebug>
#include <QFile>

#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/tpropertymap.h>

#include "trackinfo.h"

class TrackLoader : public QObject
{
    Q_OBJECT
public:
    TrackLoader(QObject *parent = 0);
    Q_INVOKABLE QString loadFromFile(QVariant folder);

    TrackTagData loadTagDataFromFile(const QString fileName);

private:
    QString filename;

signals:

public slots:
};

#endif // TRACKLOADER_H
