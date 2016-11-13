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

    TrackMetaData(qlonglong trackSize,            // Размер файла (bytes)
                  qlonglong trackDuration,        // Длительность файла (s)
                  qlonglong trackSampleRate  = 0, // Частота сэмплов (Hz)
                  int       trackBitrate     = 0, // Битрейт файла (в kb/s)
                  int       trackChannelsNum = 0  // Количество аудиоканалов
                 );

    // ****************
    //  Методы доступа
    // ****************

    qlonglong getSize();
    void      setSize(const qlonglong trackSizeInBytes);

    qlonglong getDuration();
    void      setDuration(const qlonglong trackDurationInSeconds);

    qlonglong getSampleRate();
    void      setSampleRate(const qlonglong trackSampleRate);


    int  getBitrate();
    void setBitrate(const int trackBitrate);

    int  getChannelsNum();
    void setChannelsNum(const int trackChannelsNum);

private:
    qlonglong m_sizeInBytes;        // Размер файла в байтах
    qlonglong m_durationInSeconds;  // Длительность файла в секундах
    qlonglong m_sampleRate;         // Частота сэмплов (в герцах)

    int m_bitrate;                  // Битрейт файла (в килобайтах в секунду)
    int m_channelsNum;              // Количество аудиоканалов
};

#endif // TRACKMETADATA_H
