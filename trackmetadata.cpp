#include "trackmetadata.h"

// *******************************************
//
//  Инициализация пустого объекта мета-данных
//
// *******************************************

TrackMetaData::TrackMetaData()
{
    m_sizeInBytes       = 0;
    m_durationInSeconds = 0;
    m_sampleRate        = 0;
    m_bitrate           = 0;
    m_channelsNum       = 0;
}

// ***************************************************************
//
//  Инициализация объекта мета-данных с полным набором информации
//
// ***************************************************************

TrackMetaData::TrackMetaData(qlonglong trackSize,       // Размер файла (bytes)
                             qlonglong trackDuration,   // Длительность файла (s)
                             qlonglong trackSampleRate, // Частота сэмплов (Hz)
                             int       trackBitrate,    // Битрейт файла (в kb/s)
                             int       trackChannelsNum // Количество аудиоканалов
                            )
{
    if(trackSize > 0)
        m_sizeInBytes = trackSize;
    else
        m_sizeInBytes = 0;

    if(trackDuration > 0)
        m_durationInSeconds = trackDuration;
    else
        m_durationInSeconds = 0;

    if(trackSampleRate > 0)
        m_sampleRate = trackSampleRate;
    else
        m_sampleRate = 0;

    if(trackBitrate > 0)
        m_bitrate = trackBitrate;
    else
        m_bitrate = 0;

    if(trackChannelsNum > 0)
        m_channelsNum = trackChannelsNum;
    else
        m_channelsNum = 0;
}

// *********************************
//
//  Управление полем "Размер файла"
//
// *********************************

qlonglong TrackMetaData::getSize()
{
    return m_sizeInBytes;
}

bool TrackMetaData::setSize(const qlonglong trackSizeInBytes)
{
    if(trackSizeInBytes != m_sizeInBytes && trackSizeInBytes > 0)
    {
        m_sizeInBytes = trackSizeInBytes;
        return true;
    }
    else
        return false;
}

// ***************************************
//
//  Управление полем "Длительность файла"
//
// ***************************************

qlonglong TrackMetaData::getDuration()
{
    return m_durationInSeconds;
}

bool TrackMetaData::setDuration(const qlonglong trackDurationInSeconds)
{
    if(trackDurationInSeconds != m_durationInSeconds &&
       trackDurationInSeconds >  0)
    {
        m_durationInSeconds = trackDurationInSeconds;
        return true;
    }
    else
        return false;
}

// ************************************
//
//  Управление полем "Частота сэмплов"
//
// ************************************

qlonglong TrackMetaData::getSampleRate()
{
    return m_sampleRate;
}

bool TrackMetaData::setSampleRate(const qlonglong trackSampleRate)
{
    if(trackSampleRate != m_sampleRate && trackSampleRate > 0)
    {
        m_sampleRate = trackSampleRate;
        return true;
    }
    else
        return false;
}

// **********************************
//
//  Управление полем "Битрейт файла"
//
// **********************************

int TrackMetaData::getBitrate()
{
    return m_bitrate;
}

bool TrackMetaData::setBitrate(int trackBitrate)
{
    if(trackBitrate != m_bitrate && trackBitrate > 0)
    {
        m_bitrate = trackBitrate;
        return true;
    }
    else
        return false;
}

// ***************************************
//
//  Управление полем "Количество каналов"
//
// ***************************************

int TrackMetaData::getChannelsNum()
{
    return m_channelsNum;
}

bool TrackMetaData::setChannelsNum(int trackChannelsNum)
{
    if(trackChannelsNum != m_channelsNum && trackChannelsNum > 0)
    {
        m_channelsNum = trackChannelsNum;
        return true;
    }
    else
        return false;
}
