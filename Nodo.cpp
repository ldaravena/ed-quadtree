#include "Nodo.h"
#include <cstdlib>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

//Método constructor para el resto de los nodos
Nodo::Nodo(){

	nw = NULL;
	sw = NULL;
	se = NULL;
	ne = NULL;
	ocupado = false;
	dividido = false;
}

//Método constructor para el primer nodo (raíz), con parámetros del tamaño del rectángulo inicial
Nodo::Nodo(int xff, int yff){

	xi = 1;
	yi = 1;

	xf = xff;
	yf = yff;

	padre = NULL;

	nw = NULL;
	sw = NULL;
	se = NULL;
	ne = NULL;
	ocupado = false;
	dividido = false;
}

//Método para agregar puntos al nodo
void Nodo::agregar(int px, int py){

	//Si el nodo ya tiene un 'punto'
	if(ocupado){

		//Si no está dividido se divide
		if(!dividido){

			cout<<"Dividiendo...\n";
			dividir();
		}

		//Se verifica en que hijo debe ir el punto agregado
		if(px >= nw->xi && px <= nw->xf && py >= nw->yi && py <= nw->yf){

			nw->agregar(px, py);
			cout<<"nw: "<<px<<", "<<py<<endl;
		}

		else if(px >= sw->xi && px <= sw->xf && py >= sw->yi && py <= sw->yf){

			sw->agregar(px, py);
			cout<<"sw: "<<px<<", "<<py<<endl;
		}

		else if(px >= se->xi && px <= se->xf && py >= se->yi && py <= se->yf){

			se->agregar(px, py);
			cout<<"se: "<<px<<", "<<py<<endl;
		}

		else if(px >= ne->xi && px <= ne->xf && py >= ne->yi && py <= ne->yf){

			ne->agregar(px, py);
			cout<<"ne: "<<px<<", "<<py<<endl;
		}
	}

	//Si el nodo no está ocupado se agrega el 'punto' y se marca como ocupado
	else{

		x = px;
		y = py;

		ocupado = true;
		cout<<"Agregado: "<<px<<", "<<py<<endl;

	}
}

//Método para dividir el nodo en cuatro y heredar el punto actual al hijo correspondiente
void Nodo::dividir(){
	
	bool bh = false;
	bool bv = false;
	
	//Se calculan las dimensiones de los nuevos nodos
	int dx = (xf-xi)/2;
	int dy = (yf-yi)/2;

	if((xf-xi) == 0 && (yf-yi) > 0){

		bh = true;

	}

	if((yf-yi) == 0 && (xf-xi) > 0){

		bv = true;

	}


	//Se marca el nodo como dividido
	dividido = true;

	//Se crea un nuevo nodo auxiliar y se copia la dirección al hijo 'nw'
	nw = new Nodo();

	//Se agrega la dirección del padre
	nw->padre = this;

	//Se agregan las dimensiones iniciales del nodo 'nw'
	nw->xi = xi;
	nw->yi = yi;

	//Se agregan las dimensiones finales
	nw->xf = xi+dx;
	nw->yf = yi+dy;

	//Se verifica si el 'punto' del padre debe heredarse al hijo 'nw'
	if(x >= nw->xi && x <= nw->xf && y >= nw->yi && y <= nw->yf){

		nw->x = x;
		nw->y = y;

		cout<<"Heredado nw: "<<x<<", "<<y<<endl;

		//El padre queda con 'punto' nulo.
		x=0;
		y=0;

		//Se marca el nodo 'nw' como ocupado
		nw->ocupado = true;
	}

	cout<<"Lim sup nw: "<<nw->xi<<", "<<nw->yi<<endl;
	cout<<"Lim inf nw: "<<nw->xf<<", "<<nw->yf<<endl;

	//Se realizan las mismas verificaciones con los otros hijos
	
	if(!bh){
		sw = new Nodo();

		sw->padre = this;

		sw->xi = xi+dx+1;
		sw->yi = yi;

		sw->xf = xf;
		sw->yf = yi+dy;

		if(x >= sw->xi && x <= sw->xf && y >= sw->yi && y <= sw->yf){

			sw->x = x;
			sw->y = y;

			cout<<"Heredado sw: "<<x<<", "<<y<<endl;

			x=0;
			y=0;
			sw->ocupado = true;

		}


		cout<<"Lim sup sw: "<<sw->xi<<", "<<sw->yi<<endl;
		cout<<"Lim inf sw: "<<sw->xf<<", "<<sw->yf<<endl;
	}

	if(!bh && !bv){

		se = new Nodo();

		se->padre = this;

		se->xi = nw->xf+1;
		se->yi = nw->yf+1;

		se->xf = xf;
		se->yf = yf;


		if(x >= se->xi && x <= se->xf && y >= se->yi && y <= se->yf){

			se->x = x;
			se->y = y;

			cout<<"Heredado se: "<<x<<", "<<y<<endl;

			x=0;
			y=0;
			se->ocupado = true;
		}


		cout<<"Lim sup se: "<<se->xi<<", "<<se->yi<<endl;
		cout<<"Lim inf se: "<<se->xf<<", "<<se->yf<<endl;
	}

	if(!bv){	
		ne = new Nodo();

		ne->padre = this;

		ne->xi = xi;
		ne->yi = yi+dy+1;

		ne->xf = xi+dx;
		ne->yf = yf;


		if(x >= ne->xi && x <= ne->xf && y >= ne->yi && y <= ne->yf){

			ne->x = x;
			ne->y = y;

			cout<<"Heredado ne: "<<x<<", "<<y<<endl;

			x=0;
			y=0;
			ne->ocupado = true;
		}


		cout<<"Lim sup ne: "<<ne->xi<<", "<<ne->yi<<endl;
		cout<<"Lim inf ne: "<<ne->xf<<", "<<ne->yf<<endl;
	}
}

void Nodo::find(std::pair<int,int> in, std::pair<int,int> fin){

	if(dividido){
		
		std::pair<int,int> corner2(fin.first,in.second);
		std::pair<int,int> corner4(in.first,fin.second);

		if((in.first >= nw->xi && in.first <= nw->xf && in.second >= nw->yi && in.second <= nw->yf) || (corner2.first >= nw->xi && corner2.first <= nw->xf && corner2.second >= nw->yi && corner2.second <= nw->yf) || (fin.first >= nw->xi && 	fin.first <= nw->xf && fin.second >= nw->yi && fin.second <= nw->yf) || (corner4.first >= nw->xi && corner4.first <= nw->xf && corner4.second >= nw->yi && corner4.second <= nw->yf)){

			nw->find(in,fin);
		}

		else if((in.first >= sw->xi && in.first <= sw->xf && in.second >= sw->yi && in.second <= sw->yf) || (corner2.first >= sw->xi && corner2.first <= sw->xf && corner2.second >= sw->yi && corner2.second <= sw->yf) || (fin.first >= sw->xi && fin.first <= sw->xf && fin.second >= sw->yi && fin.second <= sw->yf) || (corner4.first >= sw->xi && corner4.first <= sw->xf && corner4.second >= sw->yi && corner4.second <= sw->yf)){

			sw->find(in,fin);
		}
		
		else if((in.first >= se->xi && in.first <= se->xf && in.second >= se->yi && in.second <= se->yf) || (corner2.first >= se->xi && corner2.first <= se->xf && corner2.second >= se->yi && corner2.second <= se->yf) || (fin.first >= se->xi && fin.first <= se->xf && fin.second >= se->yi && fin.second <= se->yf) || (corner4.first >= se->xi && corner4.first <= se->xf && corner4.second >= se->yi && corner4.second <= se->yf)){

			se->find(in,fin);
		}
		
		else if((in.first >= ne->xi && in.first <= ne->xf && in.second >= ne->yi && in.second <= ne->yf) || (corner2.first >= ne->xi && corner2.first <= ne->xf && corner2.second >= ne->yi && corner2.second <= ne->yf) || (fin.first >= ne->xi && fin.first <= ne->xf && fin.second >= ne->yi && fin.second <= ne->yf) || (corner4.first >= ne->xi && corner4.first <= ne->xf && corner4.second >= ne->yi && corner4.second <= ne->yf)){

			ne->find(in,fin);
		}

		if(padre!=NULL) padre->found.insert(padre->found.end(),found.begin(),found.end());
		
	}

	else{
		
		if(x >= in.first && x <= fin.first && y >= in.second && y <= fin.second){

			padre->found.push_back(make_pair(x,y));
		}
	}

			
}

	
