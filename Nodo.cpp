#include "Nodo.h"
#include <utility>

using namespace std;

Nodo::Nodo(vector<pair<int,int>> *X, vector<pair<int,int>> *Y, bool b){

    if(X->size() == 1){

        pair<int,int> punto(X->at(0))

        x=punto.first;
        y=punto.second;

    }

    if(b){

        int v = X->size()/2;

        vector<pair<int,int>> Xl,Xr,Yl,Yr;

        vector<pair<int,int>>::iterator it=X->begin()+v;

        Xl.insert(Xl.end(),X->begin(),it);

        Xr.insert(Xr.end(),it,X->end());

        pair<int,int> parx(X->at(v));

        for(int i=0; Y->size(); i++){


            pair<int,int> pary(Y->at(i));


            if(pary.first <= parx.first){

                Yl.push_back(pary);
            }

            else{

                Yr.push_back(pary);
            }
        }

        linea = parx.first;

        left = new Nodo(&Xl,&Yl,false);
        left->padre = this;

        right = new Nodo(&Xr,&Yr,false);
        right->padre = this;
    }

    else{

        int v = Y->size()/2;

        vector<pair<int,int>> Xl,Xr,Yl,Yr;

        vector<pair<int,int>>::iterator it=Y->begin()+v;

        Yl.insert(Xl.end(),Y->begin(),it);

        Yr.insert(Yr.end(),it,Y->end());

        pair<int,int> pary(Y->at(v));

        for(int i=0; X->size(); i++){


            pair<int,int> parx(X->at(i));


            if(parx.second <= pary.second){

                Xl.push_back(parx);
            }

            else{

                Xr.push_back(parx);
            }
        }

        linea = pary.second;

        left = new Nodo(&Xl,&Yl,true);
        left->padre = this;

        right = new Nodo(&Xr,&Yr,true);
        right->padre = this;
    }
}
