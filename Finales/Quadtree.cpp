#include "Quadtree.h"
#include <vector>
#include <utility>

Quadtree::Quadtree(std::vector<std::pair<int,int>> *P, int N, int M){
	
	
	//Se crea el nodo raíz con las dimensiones entregadas
	root = new Nodo(N,M);
	
	//Se agregan los puntos desde la raíz
	for(int i=0; i<P->size(); i++){
		
		std::pair<int,int> aux(P->at(i));
		root->agregar(aux.first, aux.second);
	}
}


std::vector<std::pair<int,int>> Quadtree::find(std::pair<int,int> in, std::pair<int,int> fin){
	
	//Se llama al método 'find' de la raíz
	root->find(in,fin);

	return(root->found);
}
