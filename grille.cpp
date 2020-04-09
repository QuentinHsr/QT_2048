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
 int val1 = rand() % 6;
 int val2 = rand() % 6;
 if(val1==0)
 {tab[x1][y1]=4;}
 else
 {tab[x1][y1]=2;}
 if(val2==0)
 {tab[x2][y2]=4;}
 else
 {tab[x2][y2]=2;}

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
 memoire.push_back(tab);
 emit grilleChanged();
}

void grille::maj()
{ this->calcul_cases_vides();
  int l=cases_vides.size();
  int r = rand() % l;

  int i =cases_vides[r][0];
  int j =cases_vides[r][1];
  int val = rand() % 6;
  if(val==0)
  {tab[i][j]=4;}
  else if(val==1)
    {if (d==0){tab[i][j]=2;}
     else {tab[i][j]=3;}
      }
  else
  {tab[i][j]=2;}
  memoire.push_back(tab);
emit grilleChanged();

}

void grille::retour()
{   if (memoire.size()>1){
    memoire.pop_back();
    vector<vector<int>> tableau = memoire.back();
    tab=tableau;
    emit grilleChanged();
    }
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
            {tableaulinearise.append(QString("#f9f6f2"));}
            else if(tab[i][j]==2)
            {tableaulinearise.append(QString("#eee4da"));}
            else if(tab[i][j]==4)
            {tableaulinearise.append(QString("#ede0c8"));}
            else if(tab[i][j]==8)
            {tableaulinearise.append(QString("#f2b179"));}
            else if(tab[i][j]==16)
            {tableaulinearise.append(QString("#f59563"));}
            else if(tab[i][j]==32)
            {tableaulinearise.append(QString("#f67c5f"));}
            else if(tab[i][j]==64)
            {tableaulinearise.append(QString("#f65e3b"));}
            else if(tab[i][j]==128)
            {tableaulinearise.append(QString("#edcf72"));}
            else if(tab[i][j]==256)
            {tableaulinearise.append(QString("#edcc61"));}
            else if(tab[i][j]==512)
            {tableaulinearise.append(QString("#edc850"));}
            else if(tab[i][j]==1024)
            {tableaulinearise.append(QString("#edc53f"));}
            else if(tab[i][j]==2048)
            {tableaulinearise.append(QString("#edc22e"));}
            else if(tab[i][j]==3)
            {tableaulinearise.append(QString("#b4d9ff"));}
            else if(tab[i][j]==6)
            {tableaulinearise.append(QString("#919ae9"));}
            else if(tab[i][j]==12)
            {tableaulinearise.append(QString("#9d91e9"));}
            else if(tab[i][j]==24)
            {tableaulinearise.append(QString("#b691e9"));}
            else if(tab[i][j]==48)
            {tableaulinearise.append(QString("#d697ee"));}
            else if(tab[i][j]==96)
            {tableaulinearise.append(QString("#ff9cf7"));}
            else if(tab[i][j]==192)
            {tableaulinearise.append(QString("#ff5697"));}
            else if(tab[i][j]==384)
            {tableaulinearise.append(QString("#f46f8b"));}
            else if(tab[i][j]==1536)
            {tableaulinearise.append(QString("#dc546f"));}
            else if(tab[i][j]==3072)
            {tableaulinearise.append(QString("#fa3f49"));}



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

void grille::set_difficulty(int new_d)
{
    d = new_d;
    for(int i=0;i<4;i++){
        for(int j=0; j<4; j++){
        tab[i][j]=0;

        }
     }
    memoire.clear();
    emit grilleChanged();
    emit difficultyChanged();
}


int grille::get_difficulty(){
  cout<<d;
  return d;
}

QList<QString> grille::readBordure(){
    QList<QString> bordure;
    if (d==0){
        bordure.append(QString("3"));
        bordure.append(QString("0"));
    }
    if (d==1){
        bordure.append(QString("0"));
        bordure.append(QString("3"));
    }

    return bordure;

}

bool grille::est_vide(){
    bool a=0;
    for(int i=0;i<4;i++){
        for(int j=0; j<4; j++){
         if (tab[i][j]!=0){
             a=1;
         }


}
}
    return a;
}
