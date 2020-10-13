#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include "myclass.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject* root = engine.rootObjects()[0];
    MyClass myClass(root);
    engine.rootContext()->setContextProperty("_myClass", &myClass);

    return app.exec();
}
