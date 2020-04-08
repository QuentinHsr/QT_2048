#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <grille.h>
#include <iostream>
#include <stdio.h>
using namespace std;


int main(int argc, char *argv[])
{   srand(time(0));
    // tests préliminaires sur la grille et son fonctionnement
    grille G;
    char x;
    G.initial();
    cout<<G<<endl;
    int compteur=0;
    while(G.est_pleine()==0 and compteur<=20)// '0' correspond ici à False
    {compteur+=1;
     x=getchar();
    if (x=='z'){
        G.move_up();
        G.maj();
        cout<<G<<endl;
    }
    if (x=='s'){
       G.move_down();
       G.maj();
       cout<<G<<endl;
    }
    if (x=='q'){
      G.move_left();
      G.maj();
      cout<<G<<endl;}
    if (x=='d'){
        G.move_right();
        G.maj();
        cout<<G<<endl;
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
}
