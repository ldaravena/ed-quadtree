#include "KDTree.h"
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

KDTree::KDTree(vector<pair<int,int>> *P, int N, int M){

    n=N;
    m=M;

    X=*P;
    Y=*P;

    sort(X.begin(),X.end());
    
 /*   cout<<"Vector X ordenado:\n";
    
    for(int i=0; i<X.size(); i++){
    
        pair<int,int> par(X.at(i));
        cout<<par.first<<", "<<par.second<<endl;
    }
*/
    for(int i=0; i<Y.size(); i++){

        pair<int,int> par(Y.at(i));
        Y[i]=make_pair(par.second,par.first);
    }

    sort(Y.begin(),Y.end());

    for(int i=0; i<Y.size(); i++){

        pair<int,int> par(Y.at(i));
        Y[i]=make_pair(par.second,par.first);
    }
    
/*    cout<<"Vector Y ordenado:\n";
    
     for(int i=0; i<Y.size(); i++){
    
        pair<int,int> par(Y.at(i));
        cout<<par.first<<", "<<par.second<<endl;
    }
  */      
    root = new Nodo(&X,&Y,true);
}
std::vector<std::pair<int, int>> KDTree::find(std::pair<int, int> in, std::pair<int, int> fin) {
	root->find(in, fin);

	return(root->found);
}
