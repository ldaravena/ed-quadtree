#include "Nodo.h"
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

Nodo::Nodo(vector<pair<int,int> > P, int l, int r, bool b){

	if(b){ //Esta es la bandera que comienza en true, en true genera una division en X, en false una division en Y.  //Aqui se ordenan los puntos c/r a X
	
		sort(P.begin(),P.end());
	}
	
	else{ //Aqui se ordenan los puntos c/r a Y
	
		
		for(int i=0; i<P.size(); i++){

		    pair<int,int> par(P.at(i));
		    P[i]=make_pair(par.second,par.first);
		}

		sort(P.begin(),P.end());

		for(int i=0; i<P.size(); i++){

		    pair<int,int> par(P.at(i));
		    P[i]=make_pair(par.second,par.first);
		}
		
	}
	
	int v = (l+r)/2; //Aca sacamos la posision de la mediana
	
	if(l==r){ //Si los indices l y r son iguales se llego a dividir sucesivamente hasta tener un punto posible en las dimensiones finales, este punto se agrega y quedara como hoja
	
		pair<int,int> par(P.at(l));
		
		x=par.first; 
		y=par.second;
		linea = 0;
		
		//cout<<"Colocado :"<<x<<", "<<y<<endl;
		
		padre=this;
	}
	
	else{ //Si todavia hay mas de 1 punto en las dimensiones actuales hay que seguir restringiendo las dimensiones hasta encontrar otra hoja
	
		if(b){ //Como se dijo previamente cuando b es true, se hace una division en X (Pues el arreglo fue ordenado con respecto a X previamente)
			
			pair<int,int> par(P.at(v));
			
			linea = par.first;
			dim = 'x';
		}
		
		else{ //Caso contrario el arreglo se divide c/r a Y
			
			pair<int,int> par(P.at(v));
			
			linea = par.second;
			dim = 'y';
		}
		
		left = new Nodo(P, l, v, false); //en ambos casos se tiene que crear la siguiente dimension, o la hoja, depende de si los tamaños de estos left y right sean >1 o no.
		left->padre=this;
		
		right = new Nodo(P, v+1, r,false);
		right->padre=this;
	}
}
void Nodo::find(std::pair<int, int> in, std::pair<int, int> fin) {
	if (linea == 0) { //Si el nodo es hoja significa que almacena un numero y por ende...
	

		if (x >= in.first && x <= fin.first && y >= in.second && y <= fin.second) { //Verificamos que el par ordenado este efectivamente dentro del rectangulo de analisis, si es asi, al padre se le transfiere el punto a su arreglo de "encontrados"
			
			padre->found.push_back(make_pair(x, y));
		}
	}
	
	else { //Si el nodo es interno
		
		if (dim == 'x') { //Si su dimension es X hay puntos a su izquierda o derecha, por lo tanto...
		
			if (in.first <= linea) { //Si el punto mas izquierdo del rectangulo es menor o igual a la recta "x= linea" esto significa que es posible encontrar un punto en el lado izquierdo
			
				if(left!=NULL) left->find(in, fin);
			}
			
			if (fin.first > linea) { //Si el punto mas derecho del rectangulo es mayor a la recta "x= linea" esto significa que es posible encontrar un punto en el lado derecho
			
				if(right!=NULL) right->find(in, fin);
			}
		}
		else if (dim == 'y') {
				//cout<<"dim = y\n";
			if (in.second <= linea) { //Si el punto mas arriba del rectangulo es menor o igual a la recta " y = linea" esto significa que es posible encontrar un punto hacia arriba
			
				if(left!=NULL) left->find(in, fin); 

			}
			
			if (fin.second > linea) {//Si el punto mas abajo del rectangulo es mayor a la recta " y = linea" esto significa que es posible encontrar un punto hacia abajo
			
				if(right!=NULL) right->find(in, fin);
			}
		}
		if (padre != NULL) { // Si el nodo tiene padre, traspasar todos sus puntos encontrados a EL, cuando el nodo analizado sea la raiz, este sera el final de la recursion.
		
			padre->found.insert(padre->found.end(), found.begin(), found.end());
		}
	}
}
					
					
			
