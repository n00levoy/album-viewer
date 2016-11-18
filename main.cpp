#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQuickControls2>

#include "trackloader.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/images/album-viewer.png"));

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    TrackLoader trackLoader;
    engine.rootContext()->setContextProperty("loader", &trackLoader);

    return app.exec();
}
