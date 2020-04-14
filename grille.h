#ifndef GRILLE_H
#define GRILLE_H
#include <vector>
#include <iostream>
#include <QObject>
using namespace std;

class grille : public QObject
{
    Q_OBJECT
    public:
        explicit grille(QObject *parent = nullptr);
        Q_PROPERTY(QList<QString> grilleQML READ readGrille NOTIFY grilleChanged)
        Q_PROPERTY(QList<QString> couleurQML READ readCouleur NOTIFY grilleChanged)
        Q_PROPERTY(QList<QString> bordureQML READ readBordure NOTIFY difficultyChanged)
        Q_PROPERTY(QString fin_partieQML READ ecranfin NOTIFY endgame)
        Q_PROPERTY(bool fin_partieQML_2 READ ecranfin_2 NOTIFY endgame)

        QList<QString> readBordure();
        QList<QString> readGrille();
        QList<QString> readCouleur();
        QString ecranfin();
        bool ecranfin_2();
        bool est_pleine();
        bool estperdu();
        Q_INVOKABLE bool move_right();
        Q_INVOKABLE bool move_left();
        Q_INVOKABLE bool move_up();
        Q_INVOKABLE bool move_down();
        Q_INVOKABLE void initial();
        Q_INVOKABLE void maj();
        Q_INVOKABLE void retour();
        Q_INVOKABLE void set_difficulty(int new_d);
        Q_INVOKABLE int get_resultat();
        friend ostream& operator<<(ostream& sortie, grille& D);
        void affiche_cases_vides();
        void calcul_cases_vides();
        vector<int> etat_tab();
        int get_difficulty();
        Q_INVOKABLE bool est_vide();

    signals:
        void grilleChanged();
        void difficultyChanged();
        void endgame();
    protected:
        vector<vector<int>> tab;
     // bien que ce ne soit pas le choix le plus optimisé au niveau de l'allocation mémoire,
                                    //on stocke les cases vides en retenant leurs coordonnées (donc sous la forme d'un vecteur contenant lui même des vecteurs (1,2)
                               // cela permet une plus grande simplicité et une meilleur lisibilité du code.
        int a=2;
        vector<vector<int>> cases_vides;
        vector<vector<vector<int>>> memoire;
        int d=0;
        int resultat=0;



};

#endif // GRILLE_H
