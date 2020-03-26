#include "grille.h"
#include <random>
using namespace std;

grille::grille()
{ for(int i=0; i<4;i++){
        for(int j=0; j<4; j++)
        {
            tab[i][j]=0;

        }
    }
}

void grille::initial()
{
 int p = rand()%16;
 int q = rand()%16;
 int x1= 16/p;
 int y1= 16%p;
 int x2= 16/q;
 int y2= 16%q;

cout << "test"<<endl;

 tab[x1][y1]=2;
 tab[x2][y2]=2;

 cout << "test2"<<endl;

 for(int i=0; i<16;i++){
     if (i!=p and i!=q){
         cout << "aae";
         cases_vides.push_back(i);}
 }}

 ostream& operator<<(ostream& sortie, grille& g){
     cout<<endl;
     for (int i = 0; i < 4; i++){
         for (int j = 0; j < 4; j++){
             cout<<g.tab[i][j]<<" "  ;
         }

         cout<<endl;

     };

}
