#ifndef GRILLE_H
#define GRILLE_H
#include <vector>
#include <iostream>
using namespace std;

class grille
{

protected:
    short tab[4][4];
    vector<int> cases_vides;
public:
    grille();
    bool est_pleine();
    void move_right();
    void move_left();
    void move_up();
    void move_down();
    void initial();
    void maj();
    friend ostream& operator<<(ostream& sortie, grille& D);
};

#endif // GRILLE_H
