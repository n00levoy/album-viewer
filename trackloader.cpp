#include "trackloader.h"

#include <iostream>
#include <iomanip>
#include <QQmlEngine>
#include <QQmlContext>

#include <taglib/mpegfile.h>
#include <taglib/id3v2tag.h>
#include <taglib/attachedpictureframe.h>
#include <taglib/id3v2frame.h>
#include <taglib/tbytevector.h>

TrackLoader::TrackLoader(QObject *parent) : QObject(parent)
{
    player = new QMediaPlayer(this);
}

QString TrackLoader::loadFromFile(QVariant folder)
{
    QString folderString = folder.toString();
    QString correctedFolderString = folderString.replace("file:///", "");

    TrackFileInfo fileInfo = loadFileInfoFromFile(correctedFolderString);
    TrackMetaData metaData = loadMetaDataFromFile(correctedFolderString);
    TrackTagData  tagData  = loadTagDataFromFile (correctedFolderString);
    MusicImage    coverArt = loadCoverArtFromFile(correctedFolderString);

    TrackInfo info(fileInfo, metaData, tagData, coverArt);

    player->setMedia(QUrl::fromLocalFile(fileInfo.getFilePath()));

    DatabaseManager manager;
    manager.addTrack(info);

    return tagData.getArtist() + " - " + tagData.getTitle();
}

TrackTagData TrackLoader::loadTagDataFromFile(const QString fileName)
{
    if(fileName.endsWith(".mp3"))
    {
        TagLib::MPEG::File file(fileName.toLatin1().constData());

        if(file.isValid() && file.tag())
        {
            TagLib::ID3v2::Tag *tag = file.ID3v2Tag();

            QString title   = tag->title().toCString(true);
            QString artist  = tag->artist().toCString(true);
            QString album   = tag->album().toCString(true);
            int year        = tag->year();
            int trackNumber = tag->track();
            QString genre   = tag->genre().toCString(true);

            int     discNumber  = 0;
            QString albumArtist = QString();
            QString composer    = QString();

            TagLib::PropertyMap propertyList = file.properties();

            for(TagLib::PropertyMap::ConstIterator property = propertyList.begin();
                property != propertyList.end();
                ++property)
            {
                for(TagLib::StringList::ConstIterator propertyField = property->second.begin();
                    propertyField != property->second.end();
                    ++propertyField)
                {
                    QString fieldName    = property->first.toCString(true);
                    QString fieldContent = (*propertyField).toCString(true);

                    if(fieldName == "DISCNUMBER")
                        discNumber = fieldContent.toInt();
                    if(fieldName == "ALBUMARTIST")
                        albumArtist = fieldContent;
                    if(fieldName == "COMPOSER")
                        composer = fieldContent;
                }
            }

            TrackTagData tagData;
            tagData.setTitle      (title);
            tagData.setTrackNumber(trackNumber);
            tagData.setArtist     (artist);
            tagData.setAlbumName  (album);
            tagData.setYear       (year);
            tagData.setGenre      (genre);
            tagData.setAlbumArtist(albumArtist);
            tagData.setComposer   (composer);
            tagData.setDiscNumber (discNumber);

            return tagData;
        }
        else
            return TrackTagData();
    }

    return TrackTagData();
}

MusicImage TrackLoader::loadCoverArtFromFile(const QString fileName)
{
    if(fileName.endsWith(".mp3"))
    {
        TagLib::MPEG::File file(fileName.toLatin1().constData());

        if(file.isValid() && file.hasID3v2Tag())
        {
            TagLib::ID3v2::Tag* tag = file.ID3v2Tag();

            if(!tag->isEmpty())
            {
                TagLib::ID3v2::FrameList listOfMp3Frames = file.ID3v2Tag()->frameListMap()["APIC"];

                if(!listOfMp3Frames.isEmpty())
                {
                    TagLib::ID3v2::FrameList::ConstIterator it = listOfMp3Frames.begin();

                    for(; it != listOfMp3Frames.end() ; it++)
                    {
                        TagLib::ID3v2::AttachedPictureFrame* pictureFrame = static_cast<TagLib::ID3v2::AttachedPictureFrame*> (*it);

                        if(pictureFrame)
                        {
                            QByteArray imageBytes(pictureFrame->picture().data(), pictureFrame->picture().size());

                            QImage  coverArtImage = QImage::fromData(imageBytes);
                            QString imageFileType = pictureFrame->mimeType().toCString(true);

                            return MusicImage(coverArtImage, imageFileType);
                        }
                        else
                            return MusicImage();
                    }
                }
            }
        }
    }

    return MusicImage();
}

TrackFileInfo TrackLoader::loadFileInfoFromFile(const QString fileName)
{
    QFileInfo fileInfo(fileName);
    if(fileInfo.exists() && !fileInfo.canonicalFilePath().isEmpty())
    {
        auto filePath = fileInfo.canonicalFilePath();
        auto fileSize = fileInfo.size();

        TrackFileInfo trackFileInfo;
        trackFileInfo.setFilePath(filePath);
        trackFileInfo.setSizeInBytes(fileSize);
        return trackFileInfo;
    }
    else
        return TrackFileInfo();
}

TrackMetaData TrackLoader::loadMetaDataFromFile(const QString fileName)
{
    TagLib::FileRef file(fileName.toLatin1().constData());

    if(!file.isNull())
    {
        TagLib::AudioProperties* audioProps = file.audioProperties();

        if(audioProps)
        {
            auto bitrate     = audioProps->bitrate();
            auto channelsNum = audioProps->channels();
            auto duration    = audioProps->lengthInSeconds();
            auto sampleRate  = audioProps->sampleRate();

            TrackMetaData metaData(duration, sampleRate, bitrate, channelsNum);
            return metaData;
        }
    }

    return TrackMetaData();
}

void TrackLoader::play()
{
    player->play();
}

void TrackLoader::pause()
{
    player->pause();
}
