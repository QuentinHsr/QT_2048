#include "grille.h"
#include <random>
#include <vector>

#include <ctime>
#include <cstdlib>
using namespace std;

grille::grille(QObject *parent) : QObject(parent)
{ for(int i=0; i<4;i++){
        vector<int> colonne;
        for(int j=0; j<4; j++)
        {
            colonne.push_back(0);
            vector<int> w;
            w.push_back(i);
            w.push_back(j);
            cases_vides.push_back(w);
        }
        tab.push_back(colonne);
    }
    emit grilleChanged();
}

void grille::initial()
{
 cases_vides.clear();
 int x1 = rand() % 4;
 int x2 = rand() % 4;
 int y1 = rand() % 4;
 int y2 = rand() % 4;
 tab[x1][y1]=2;
 tab[x2][y2]=2;

 for(int i=0; i<4;i++)
 { for(int j=0; j<4; j++)
     {
     if ((i!=x1 or j!=y1) and (i!=x2 or j!=y2))
        {
         vector<int> v;
         v.push_back(i);
         v.push_back(j);
         cases_vides.push_back(v);

         }
    }
}
 emit grilleChanged();
}

void grille::maj()
{ this->calcul_cases_vides();
  int l=cases_vides.size();
  int r = rand() % l;

  int i =cases_vides[r][0];
  int j =cases_vides[r][1];

  tab[i][j]=2;
emit grilleChanged();
}

bool grille::move_left()
{int c = 0;
bool test = 0;
bool a_bouge= 0;

for (int i=0;i<4;i++)
    {
    for(int j=0;j<3;j++)
    {   test=0;
        c=0;
        while((test==0) && c<=4)
        {    c = c + 1;
                if(tab[i][j]==0)   //déplacement des cases (hors fusion) on retire tous les "0" ie toutes les cases vides avant de fusionner
                {
                for(int k=j+1;k<4;k++)
                 {int val = tab[i][k];
                  tab[i][k-1]=val;
                  if(val !=0)
                  {a_bouge=1;}
                 }
                tab[i][3] = 0;
                 }
            else {test=1;}
         }
    }
    for(int j=0;j<3;j++)        // fusion des cases 2 à 2
    {
        if(tab[i][j]==tab[i][j+1] and tab[i][j]!=0)
            {   int v2=tab[i][j];
                a_bouge=1;
                tab[i][j] = 2*v2;
                tab[i][j+1] = 0;
              for(int k=j+1;k<3;k++) //après la fusion on redéplace pour combler le vide
                 {tab[i][k]=tab[i][k+1];             
                  a_bouge=1;
                 }
               tab[i][3] = 0;
           }
    }
    }
emit grilleChanged();
return a_bouge;
}

bool grille::move_up()
{int c = 0;
bool test = 0;
bool a_bouge= 0;
for (int i=0;i<4;i++)
    {
    for(int j=0;j<3;j++)
    {   test=0;
        c=0;
        while((test==0) && c<=4)
        {    c = c + 1;
                if(tab[j][i]==0)   //déplacement des cases (hors fusion) on retire tous les "0" ie toutes les cases vides avant de fusionner
                {
                for(int k=j+1;k<4;k++)
                 {int val = tab[k][i];
                  tab[k-1][i]=val;
                  if(val !=0)
                  {a_bouge= 1;}
                 }
                tab[3][i] = 0;
                 }
            else {test=1;}
         }
    }
    for(int j=0;j<3;j++)        // fusion des cases 2 à 2
    {
        if(tab[j][i]==tab[j+1][i] and tab[j][i]!=0)
            {   int v2=tab[j][i];
                a_bouge= 1;
                tab[j][i] = 2*v2;
                tab[j+1][i] = 0;
              for(int k=j+1;k<3;k++) //après la fusion on redéplace pour combler le vide
                 {tab[k][i]=tab[k+1][i];
                 a_bouge= 1;
                 }
               tab[3][i] = 0;
           }
    }
    }

return a_bouge;
emit grilleChanged();
}

bool grille::move_down()
{int c = 0;
bool test = 0;
bool a_bouge= 0;
for (int i=0;i<4;i++)
    {
    for(int j=3;j>0;j--)
    {   test=0;
        c=0;
        while((test==0) && c<4)
        {    c = c + 1;
                if(tab[j][i]==0)   //déplacement des cases (hors fusion) on retire tous les "0" ie toutes les cases vides avant de fusionner
                {
                for(int k=j;k>0;k--)
                 {int val = tab[k-1][i];
                  tab[k][i]=val;
                  if(val !=0)
                  {a_bouge= 1;}
                 }
                tab[0][i] = 0;
                 }
            else {test=1;}
         }
    }
    for(int j=3;j>0;j--)        // fusion des cases 2 à 2
    {
        if(tab[j][i]==tab[j-1][i] and tab[j][i]!=0)
            {   int v2=tab[j][i];
                a_bouge= 1;
                tab[j-1][i] = 0;
                tab[j][i] =2*v2;
              for(int k=j-1;k>0;k--) //après la fusion on redéplace pour combler le vide
                 {tab[k][i]=tab[k-1][i];
                  a_bouge= 1;
                }
              tab[0][i] = 0;
           }
    }
    }

return a_bouge;
emit grilleChanged();
}

bool grille::move_right()
{int c = 0;
bool test = 0;
bool a_bouge= 0;
for (int i=0;i<4;i++)
    {
    for(int j=3;j>0;j--)
    {   test=0;
        c=0;
        while((test==0) && c<=4)
        {    c = c + 1;
                if(tab[i][j]==0)   //déplacement des cases (hors fusion) on retire tous les "0" ie toutes les cases vides avant de fusionner
                {
                for(int k=j;k>0;k--)
                 {int val = tab[i][k-1];
                  tab[i][k]=val;
                  if(val !=0)
                  {a_bouge= 1;}
                 }
                tab[i][0] = 0;
                 }
            else {test=1;}
         }
    }
    for(int j=3;j>0;j--)        // fusion des cases 2 à 2
    {
        if(tab[i][j]==tab[i][j-1] and tab[i][j]!=0)
            {   int v2=tab[i][j];
                a_bouge= 1;
                tab[i][j-1] = 0;
                tab[i][j] =2*v2;
              for(int k=j-1;k>0;k--) //après la fusion on redéplace pour combler le vide
                 {tab[i][k]=tab[i][k-1];
                 a_bouge= 1;
              }
               tab[i][0] = 0;
           }
    }
    }

return a_bouge;
emit grilleChanged();
}

void grille::calcul_cases_vides()
{
    cases_vides.clear();

    for(int i=0;i<4;i++)
    {for (int j=0;j<4;j++)
        {if (tab[i][j]== 0)
            {
                vector<int> w;
                w.push_back(i);
                w.push_back(j);
                cases_vides.push_back(w);
            }

        }
    }

}

void grille::affiche_cases_vides()
{   int l = cases_vides.size();
    for(int k=0;k<l;k++)
    {int i = cases_vides[k][0];
     int j = cases_vides[k][1];
     cout<<"("<<i<<";"<<j<<")"<<endl;
    }
}

bool grille::est_pleine()
{   this->calcul_cases_vides();
    return (cases_vides.empty());

}
QList<QString> grille::readGrille()
{   QList<QString> tableaulinearise;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if(tab[i][j]!=0)
            {tableaulinearise.append(QString::number(tab[i][j]));}
            else
            {tableaulinearise.append(QString(""));}
        }
        }
    return(tableaulinearise);
}
QList<QString> grille::readCouleur()
{   QList<QString> tableaulinearise;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if(tab[i][j]==0)
            {tableaulinearise.append(QString("#e4e4e4"));}
            else if(tab[i][j]==2)
            {tableaulinearise.append(QString("#ece6cf"));}
            else if(tab[i][j]==4)
            {tableaulinearise.append(QString("#e4d9ac"));}
            else if(tab[i][j]==8)
            {tableaulinearise.append(QString("#e9cd5a"));}
            else if(tab[i][j]==16)
            {tableaulinearise.append(QString("#f7ea2e"));}

        }
        }
    return(tableaulinearise);
}
vector<int> grille::etat_tab()
{   vector<int> tableaulinearise;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
           tableaulinearise.push_back(tab[i][j]);
        }
        }
    return(tableaulinearise);
}
ostream& operator<<(ostream& sortie, grille& g)
 {
     cout<<endl;
     for (int i = 0; i < 4; i++){
         for (int j = 0; j < 4; j++){
             cout<<g.tab[i][j]<<" "  ;
         }
         cout<<endl;

     };

}

