#ifndef GRILLE_H
#define GRILLE_H
#include <vector>
#include <iostream>
using namespace std;

class grille
{

protected:
    short tab[4][4];
     // bien que ce ne soit pas le choix le plus optimisé au niveau de l'allocation mémoire,
                                    //on stocke les cases vides en retenant leurs coordonnées (donc sous la forme d'un vecteur contenant lui même des vecteurs (1,2)
                               // cela permet une plus grande simplicité et une meilleur lisibilité du code.
    int a=2;
    vector<vector<int>> cases_vides;
    vector<short> memoire;
public:

    grille();
    bool est_pleine();
    bool move_right();
    bool move_left();
    bool move_up();
    bool move_down();
    void initial();
    void maj();
    friend ostream& operator<<(ostream& sortie, grille& D);
    void affiche_cases_vides();
    void calcul_cases_vides();
};

#endif // GRILLE_H
