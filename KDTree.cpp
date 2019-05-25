#include "KDTree.h"
#include <vector>
#include <utility>
#include <algorithms>

using namespace std;

KDTree::KDTree(vector<pair<int,int>> *P, int N, int M){

    this.N=N;
    this.M=M;

    X=*P;
    Y=*P;

    sort(X.begin(),X.end());

    for(int i=0; i<Y.size(); i++){

        pair<int,int> par(Y.at(i));
        Y[i]=make_pair(par.second,par.first);
    }

    sort(Y.begin(),Y.end());

    for(int i=0; i<Y.size(); i++){

        pair<int,int> par(Y.at(i));
        Y[i]=make_pair(par.second,par.first);
    }

    root = new Nodo(&X,&Y,true);
}
