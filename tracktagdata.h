#ifndef TRACKTAGDATA_H
#define TRACKTAGDATA_H

#include <QString>

// **************************************
//
//  Класс-хранилище данных ID3v2.3-тегов
//
// **************************************

class TrackTagData
{
public:
    // **************************
    //  Создание пустого объекта
    // **************************

    TrackTagData();

    // *****************************************
    //  Создание объекта с полным набором информации
    // *****************************************

    TrackTagData(const QString trackTitle,                   // Название трека
                 int           trackNumber,                  // Номер трека
                 const QString trackArtist,                  // Исполнитель
                 const QString trackAlbum,                   // Альбом
                 const QString trackYear        = QString(), // Год
                 const QString trackGenre       = QString(), // Жанр
                 const QString trackAlbumArtist = QString(), // Исполнитель альбома
                 const QString trackComposer    = QString(), // Композитор
                 int           trackDiscNumber  = 0          // Номер диска
                );

    // ****************
    //  Методы доступа
    // ****************

    const QString getAlbumArtist();
    bool          setAlbumArtist(const QString trackAlbumArtist);

    const QString getAlbumName();
    bool          setAlbumName(const QString trackAlbumName);

    const QString getArtist();
    bool          setArtist(const QString trackArtist);

    const QString getTitle();
    bool          setTitle(const QString trackTitle);

    const QString getYear();
    bool          setYear(const QString trackYear);

    const QString getGenre();
    bool          setGenre(const QString trackGenre);

    const QString getComposer();
    bool          setComposer(const QString trackComposer);


    int  getTrackNumber();
    bool setTrackNumber(const int trackNumber);

    int  getDiscNumber();
    bool setDiscNumber(const int trackDiscNumber);

private:
    QString m_albumArtist;  // Исполнитель альбома
    QString m_albumName;    // Название альбома
    QString m_artist;       // Исполнитель
    QString m_title;        // Название трека
    QString m_year;         // Год (дата)
    QString m_genre;        // Жанр
    QString m_composer;     // Композитор

    int m_trackNumber;      // Номер трека
    int m_discNumber;       // Номер диска
};

#endif // TRACKTAGDATA_H
