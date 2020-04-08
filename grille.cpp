#include "grille.h"
#include <random>
#include <vector>

#include <ctime>
#include <cstdlib>
using namespace std;

grille::grille()
{ for(int i=0; i<4;i++){
        for(int j=0; j<4; j++)
        {
            tab[i][j]=0;
            vector<int> w;
            w.push_back(i);
            w.push_back(j);
            cases_vides.push_back(w);
        }
    }
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
}

void grille::maj()
{ this->calcul_cases_vides();
  int l=cases_vides.size();
  int r = rand() % l;

  int i =cases_vides[r][0];
  int j =cases_vides[r][1];

  tab[i][j]=2;

}

void grille::move_left()
{int c = 0;
bool test = 0;

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

                tab[i][j] = 2*v2;
                tab[i][j+1] = 0;
              for(int k=j+1;k<3;k++) //après la fusion on redéplace pour combler le vide
                 {tab[i][k]=tab[i][k+1];
                 }
               tab[i][3] = 0;
           }
    }
    }

}

void grille::move_up()
{int c = 0;
bool test = 0;

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

                tab[j][i] = 2*v2;
                tab[j+1][i] = 0;
              for(int k=j+1;k<3;k++) //après la fusion on redéplace pour combler le vide
                 {tab[k][i]=tab[k+1][i];
                 }
               tab[3][i] = 0;
           }
    }
    }

}

void grille::move_down()
{int c = 0;
bool test = 0;

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

                tab[j-1][i] = 0;
                tab[j][i] =2*v2;
              for(int k=j-1;k>0;k--) //après la fusion on redéplace pour combler le vide
                 {tab[k][i]=tab[k-1][i];
                }
              tab[0][i] = 0;
           }
    }
    }

}

void grille::move_right()    // ça marche pas encore
{int c = 0;
bool test = 0;

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

                tab[i][j-1] = 0;
                tab[i][j] =2*v2;
              for(int k=j-1;k>0;k--) //après la fusion on redéplace pour combler le vide
                 {tab[i][k]=tab[i][k-1];
                 }
               tab[i][0] = 0;
           }
    }
    }

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
