#include "trackloader.h"

#include <iostream>
#include <iomanip>

TrackLoader::TrackLoader(QObject *parent) : QObject(parent)
{
    player = new QMediaPlayer(this);
}

QString TrackLoader::loadFromFile(QVariant folder)
{
    QString folderString = folder.toString();
    QString correctedFolderString = folderString.replace("file:///", "");

    TrackTagData tagData = loadTagDataFromFile(correctedFolderString);

    player->setMedia(QUrl::fromLocalFile(correctedFolderString));

    return tagData.getArtist() + " - " + tagData.getTitle();
}

TrackTagData TrackLoader::loadTagDataFromFile(const QString fileName)
{
    TagLib::FileRef f(fileName.toLatin1().constData());

    TrackTagData tagData;
    if(!f.isNull() && f.tag())
    {
        TagLib::Tag *tag = f.tag();

        QString title  = tag->title().toCString(true);
        tagData.setTitle(title);

        QString artist = tag->artist().toCString(true);
        tagData.setArtist(artist);

        QString album  = tag->album().toCString(true);
        tagData.setAlbumName(album);

        int year = tag->year();
        tagData.setYear(year);

        int trackNumber = tag->track();
        tagData.setTrackNumber(trackNumber);

        QString genre  = tag->genre().toCString(true);
        tagData.setGenre(genre);

        TagLib::PropertyMap propertyList = f.file()->properties();

        for(TagLib::PropertyMap::ConstIterator i = propertyList.begin(); i != propertyList.end(); ++i) {
            for(TagLib::StringList::ConstIterator j = i->second.begin(); j != i->second.end(); ++j) {
                qDebug() << i->first.toCString(true) << "-" << (*j).toCString(true);
            }
        }

        return tagData;
    }
    else
        return TrackTagData();
}

void TrackLoader::play()
{
    player->play();
}

void TrackLoader::pause()
{
    player->pause();
}
