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
    cout<<G<<endl;
    int compteur=0;
    while(G.est_pleine()==0 and compteur<=30)
    {compteur+=1;
    G.move_left();
    cout<<G<<endl;

    G.maj();
    cout<<G<<endl;
    }


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
