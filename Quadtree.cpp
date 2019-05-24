#include "Quadtree.h"
#include <vector>
#include <utility>

Quadtree::Quadtree(std::vector<std::pair<int,int>> *P, int N, int M){

	root = new Nodo(N,M);

	for(int i=0; i<P->size(); i++){
	
		std::pair<int,int> aux(P->at(i));
		root->agregar(aux.first, aux.second);
	}
}


std::vector<std::pair<int,int>> Quadtree::find(std::pair<int,int> in, std::pair<int,int> fin){

	root->find(in,fin);

	return(root->found);
}
