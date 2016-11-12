#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuickControls2>

#include "trackloader.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    TrackLoader trackLoader;
    engine.rootContext()->setContextProperty("loader", &trackLoader);

    return app.exec();
}
