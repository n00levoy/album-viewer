#ifndef TRACKLOADER_H
#define TRACKLOADER_H

#include <QObject>
#include <QVariant>
#include <QDebug>
#include <QFile>
#include <taglib/fileref.h>

class TrackLoader : public QObject
{
    Q_OBJECT
public:
    TrackLoader(QObject *parent = 0);
    Q_INVOKABLE QString loadFromFile(QVariant folder);

private:
    QString filename;

signals:

public slots:
};

#endif // TRACKLOADER_H
