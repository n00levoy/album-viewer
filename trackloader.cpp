#include "trackloader.h"


TrackLoader::TrackLoader(QObject *parent) : QObject(parent)
{

}

QString TrackLoader::loadFromFile(QVariant folder)
{
    QString folderString = folder.toString();
    QString correctedFolderString = folderString.replace("file:///", "");

    TagLib::FileRef f(correctedFolderString.toStdWString().c_str());
    QString artist;
    QString album;
    uint    year;
    QString genre;
    QString title;
    if(!f.isNull() && f.tag())
    {
        artist = f.tag()->artist().toCString(true);
        title  = f.tag()->title().toCString(true);
        album  = f.tag()->album().toCString(true);
        year   = f.tag()->year();
        genre  = f.tag()->genre().toCString(true);
    }

    return artist + " - " + title;
}
