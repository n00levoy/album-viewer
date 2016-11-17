#ifndef TRACKMETADATA_H
#define TRACKMETADATA_H

#include <QtCore>

// *************************************
//
//  Класс-хранилище данных о аудиофайле
//
// *************************************

class TrackMetaData
{
public:
    // **************************
    //  Создание пустого объекта
    // **************************

    TrackMetaData();

    // **********************************************
    //  Создание объекта с полным набором информации
    // **********************************************

    TrackMetaData(const qlonglong trackDuration,        // Длительность файла (s)
                  const qlonglong trackSampleRate  = 0, // Частота сэмплов (Hz)
                  const int       trackBitrate     = 0, // Битрейт файла (в kb/s)
                  const int       trackChannelsNum = 0  // Количество аудиоканалов
                 );

    // ****************
    //  Методы доступа
    // ****************

    qlonglong getDuration();
    void      setDuration(const qlonglong trackDurationInSeconds);

    qlonglong getSampleRate();
    void      setSampleRate(const qlonglong trackSampleRate);


    int  getBitrate();
    void setBitrate(const int trackBitrate);

    int  getChannelsNum();
    void setChannelsNum(const int trackChannelsNum);

private:
    qlonglong m_durationInSeconds;  // Длительность файла в секундах
    qlonglong m_sampleRate;         // Частота сэмплов (в герцах)

    int m_bitrate;                  // Битрейт файла (в килобайтах в секунду)
    int m_channelsNum;              // Количество аудиоканалов
};

#endif // TRACKMETADATA_H
