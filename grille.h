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
        QList<QString> readGrille();
        QList<QString> readCouleur();
        bool est_pleine();
        Q_INVOKABLE bool move_right();
        Q_INVOKABLE bool move_left();
       Q_INVOKABLE bool move_up();
       Q_INVOKABLE bool move_down();
        Q_INVOKABLE void initial();
       Q_INVOKABLE void maj();
        Q_INVOKABLE void retour();
        friend ostream& operator<<(ostream& sortie, grille& D);
        void affiche_cases_vides();
        void calcul_cases_vides();
        vector<int> etat_tab();

    signals:
        void grilleChanged();
    protected:
        vector<vector<int>> tab;
     // bien que ce ne soit pas le choix le plus optimisé au niveau de l'allocation mémoire,
                                    //on stocke les cases vides en retenant leurs coordonnées (donc sous la forme d'un vecteur contenant lui même des vecteurs (1,2)
                               // cela permet une plus grande simplicité et une meilleur lisibilité du code.
        int a=2;
        vector<vector<int>> cases_vides;
        vector<vector<vector<int>>> memoire;




};

#endif // GRILLE_H
