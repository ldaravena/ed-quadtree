#include "KDTree.h"
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

KDTree::KDTree(vector<pair<int,int> > P, int N, int M){

    n=N;  
    m=M;

	
    root = new Nodo(P,0,P.size()-1,true); // Esto entra en una recursividad que arma todo el arbol
}
std::vector<std::pair<int, int> > KDTree::find(std::pair<int, int> in, std::pair<int, int> fin) { 
	
	root->find(in, fin); //Empieza la recursividad con la raiz;

	return(root->found); //Retorna el vector de "encontrados"
}
