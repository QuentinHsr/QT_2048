#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <grille.h>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{   srand(time(0));
    // tests préliminaires sur la grille et son fonctionnement
    grille G;
    G.initial();
    while(not(G.est_pleine())){
    cout<<G<<endl;
    G.calcul_cases_vides();
    G.maj();
    }
    cout<<G<<endl;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
