QT += qml quick quickcontrols2

CONFIG += c++11

SOURCES += main.cpp \
    trackinfo.cpp \
    trackinfomanager.cpp

RESOURCES += qml.qrc

INCLUDEPATH += "C:\Program Files (x86)\taglib\include"

LIBS += "C:\Program Files (x86)\taglib\lib\libtag.dll.a" \
        "C:\Program Files (x86)\taglib\lib\libtag_c.dll.a"

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    trackinfo.h \
    trackinfomanager.h
