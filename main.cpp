#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngine>

#include "GoogleImages/Search.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QtWebEngine::initialize();

    qmlRegisterType<google_images::Search>("GoogleImages", 1, 0, "GoogleImagesSearch");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
