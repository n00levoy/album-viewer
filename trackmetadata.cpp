#include "trackmetadata.h"

// *******************************************
//
//  Инициализация пустого объекта мета-данных
//
// *******************************************

TrackMetaData::TrackMetaData()
{
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

TrackMetaData::TrackMetaData(const qlonglong trackDuration,   // Длительность файла (s)
                             const qlonglong trackSampleRate, // Частота сэмплов (Hz)
                             const int       trackBitrate,    // Битрейт файла (в kb/s)
                             const int       trackChannelsNum // Количество аудиоканалов
                            )
{
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

// ***************************************
//
//  Управление полем "Длительность файла"
//
// ***************************************

qlonglong TrackMetaData::getDuration() const
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

qlonglong TrackMetaData::getSampleRate() const
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

int TrackMetaData::getBitrate() const
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

int TrackMetaData::getChannelsNum() const
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
