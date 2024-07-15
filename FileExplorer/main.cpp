#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "FilesController.h"
#include "ShortcutsController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    FilesController *filesController = new FilesController(&app);
    qmlRegisterSingletonInstance("fs.controllers.FilesController", 1, 0, "FilesController", filesController);

    ShortcutsController *shortcutsController = new ShortcutsController(&app);
    qmlRegisterSingletonInstance("fs.controllers.ShortcutsController", 1, 0, "ShortcutsController", shortcutsController);

    const QUrl url(QStringLiteral("qrc:/FileExplorer/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
