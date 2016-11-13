#include "trackloader.h"

#include <iostream>
#include <iomanip>

TrackLoader::TrackLoader(QObject *parent) : QObject(parent)
{

}

QString TrackLoader::loadFromFile(QVariant folder)
{
    QString folderString = folder.toString();
    QString correctedFolderString = folderString.replace("file:///", "");

    TrackTagData tagData = loadTagDataFromFile(correctedFolderString);

    return tagData.getArtist() + " - " + tagData.getTitle();
}

TrackTagData TrackLoader::loadTagDataFromFile(const QString fileName)
{
    TagLib::FileRef f(fileName.toStdWString().c_str());

    TrackTagData tagData;
    if(!f.isNull() && f.tag())
    {
        QString title  = f.tag()->title().toCString(true);
        tagData.setTitle(title);

        QString artist = f.tag()->artist().toCString(true);
        tagData.setArtist(artist);

        QString album  = f.tag()->album().toCString(true);
        tagData.setAlbumName(album);

        int year = f.tag()->year();
        tagData.setYear(year);

        int trackNumber = f.tag()->track();
        tagData.setTrackNumber(trackNumber);

        QString genre  = f.tag()->genre().toCString(true);
        tagData.setGenre(genre);

        QString albumArtist = artist;
        tagData.setAlbumArtist(albumArtist);

        TagLib::PropertyMap propertyList = f.tag()->properties();

        unsigned int longest = 0;
        for(TagLib::PropertyMap::ConstIterator i = propertyList.begin(); i != propertyList.end(); ++i) {
          if (i->first.size() > longest) {
            longest = i->first.size();
          }
        }

        for(TagLib::PropertyMap::ConstIterator i = propertyList.begin(); i != propertyList.end(); ++i) {
          for(TagLib::StringList::ConstIterator j = i->second.begin(); j != i->second.end(); ++j) {
            std::cout << std::left << std::setw(longest) << i->first << " - " << '"' << *j << '"' << std::endl;
          }
        }

        return tagData;
    }
    else
        return TrackTagData();
}
