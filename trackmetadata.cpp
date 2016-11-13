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

void TrackMetaData::setSize(const qlonglong trackSizeInBytes)
{
    if(trackSizeInBytes > 0)
        m_sizeInBytes = trackSizeInBytes;
    else
        m_sizeInBytes = 0;
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

void TrackMetaData::setDuration(const qlonglong trackDurationInSeconds)
{
    if(trackDurationInSeconds >  0)
        m_durationInSeconds = trackDurationInSeconds;
    else
        m_durationInSeconds = 0;
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

void TrackMetaData::setSampleRate(const qlonglong trackSampleRate)
{
    if(trackSampleRate > 0)
        m_sampleRate = trackSampleRate;
    else
        m_sampleRate = 0;
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

void TrackMetaData::setBitrate(const int trackBitrate)
{
    if(trackBitrate > 0)
        m_bitrate = trackBitrate;
    else
        m_bitrate = 0;
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

void TrackMetaData::setChannelsNum(const int trackChannelsNum)
{
    if(trackChannelsNum > 0)
        m_channelsNum = trackChannelsNum;
    else
        m_channelsNum = 0;
}
