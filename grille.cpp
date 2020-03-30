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
{
  int x1 = rand() % 4;
  int x2 = rand() % 4;
  int y1 = rand() % 4;
  int y2 = rand() % 4;
  int l=cases_vides.size();


for(int k=0;k<l;k++)
    {int i = cases_vides[k][0];
     int j = cases_vides[k][1];

     if (i==x1 and j==y1)
      {   tab[x1][y1]=2;
           cases_vides.erase(cases_vides.begin()+k);


      }

     else if (i==x2 and j==y2)                  // problème avec ce elif
       {   tab[x2][y2]=2;
           cases_vides.erase(cases_vides.begin()+k);
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
