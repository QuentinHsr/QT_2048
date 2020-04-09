#include <QtQml>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <grille.h>
#include <iostream>
#include <stdio.h>
using namespace std;


int main(int argc, char *argv[])
{   srand(time(0));
    // tests préliminaires sur la grille et son fonctionnement

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

        QGuiApplication app(argc, argv);

        QQmlApplicationEngine engine;

        grille Gri;
        engine.rootContext()->setContextProperty("vueObjetCpt",&Gri);

    const QUrl mainQml(QStringLiteral("qrc:/main.qml"));
    engine.load(mainQml);

    return app.exec();

}
