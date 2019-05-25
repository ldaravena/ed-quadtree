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

			cout<<"nw: "<<px<<", "<<py<<endl;
			nw->agregar(px, py);

		}

		else if(px >= sw->xi && px <= sw->xf && py >= sw->yi && py <= sw->yf){

			cout<<"sw: "<<px<<", "<<py<<endl;
			sw->agregar(px, py);

		}

		else if(px >= se->xi && px <= se->xf && py >= se->yi && py <= se->yf){

			cout<<"se: "<<px<<", "<<py<<endl;
			se->agregar(px, py);

		}

		else if(px >= ne->xi && px <= ne->xf && py >= ne->yi && py <= ne->yf){

			cout<<"ne: "<<px<<", "<<py<<endl;
			ne->agregar(px, py);

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


	//Se calculan las dimensiones de los nuevos nodos
	int dx = (xf-xi)/2;
	int dy = (yf-yi)/2;


	dividido = true;
	//Se marca el nodo como dividido

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


	cout<<"Lim sup nw: "<<nw->xi<<", "<<nw->yi<<endl;
	cout<<"Lim inf nw: "<<nw->xf<<", "<<nw->yf<<endl;


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



//Se realizan las mismas verificaciones con los otros hijos

	sw = new Nodo();

	sw->padre = this;

	sw->xi = xi+dx+1;
	sw->yi = yi;

	sw->xf = xf;
	sw->yf = yi+dy;

	cout<<"Lim sup sw: "<<sw->xi<<", "<<sw->yi<<endl;
	cout<<"Lim inf sw: "<<sw->xf<<", "<<sw->yf<<endl;

	if(x >= sw->xi && x <= sw->xf && y >= sw->yi && y <= sw->yf){

		sw->x = x;
		sw->y = y;

		cout<<"Heredado sw: "<<x<<", "<<y<<endl;

		x=0;
		y=0;
		sw->ocupado = true;

	}



	se = new Nodo();

	se->padre = this;

	se->xi = nw->xf+1;
	se->yi = nw->yf+1;

	se->xf = xf;
	se->yf = yf;

	cout<<"Lim sup se: "<<se->xi<<", "<<se->yi<<endl;
	cout<<"Lim inf se: "<<se->xf<<", "<<se->yf<<endl;

	if(x >= se->xi && x <= se->xf && y >= se->yi && y <= se->yf){

		se->x = x;
		se->y = y;

		cout<<"Heredado se: "<<x<<", "<<y<<endl;

		x=0;
		y=0;
		se->ocupado = true;
	}

	ne = new Nodo();

	ne->padre = this;

	ne->xi = xi;
	ne->yi = yi+dy+1;

	ne->xf = xi+dx;
	ne->yf = yf;

	cout<<"Lim sup ne: "<<ne->xi<<", "<<ne->yi<<endl;
	cout<<"Lim inf ne: "<<ne->xf<<", "<<ne->yf<<endl;

	if(x >= ne->xi && x <= ne->xf && y >= ne->yi && y <= ne->yf){

		ne->x = x;
		ne->y = y;

		cout<<"Heredado ne: "<<x<<", "<<y<<endl;

		x=0;
		y=0;
		ne->ocupado = true;
	}

}


void Nodo::find(std::pair<int,int> in, std::pair<int,int> fin){

	if(dividido){

		cout<<"Buscando en ";

		if( (((nw->xi <= in.first) && (in.first <= nw->xf)) || ((nw->xi <= fin.first) && (fin.first <= nw-> xf)) || ((in.first <= nw->xi) && (nw->xi <= fin.first)) || ((in.first <= nw->xf) && (nw->xf <= fin.first))) && (((nw->yi <= in.second) && (in.second <= nw->yf)) || ((nw->yi <= fin.second) && (fin.second <= nw->yf)) || ((in.second <= nw->yi) && (nw->yi <= fin.second)) || ((in.second <= nw->yf) && (nw->yf <= fin.second))) ){

			cout<<"NW:\n";

			nw->find(in,fin);
		}

		if( (((sw->xi <= in.first) && (in.first <= sw->xf)) || ((sw->xi <= fin.first) && (fin.first <= sw-> xf)) || ((in.first <= sw->xi) && (sw->xi <= fin.first)) || ((in.first <= sw->xf) && (sw->xf <= fin.first))) && (((sw->yi <= in.second) && (in.second <= sw->yf)) || ((sw->yi <= fin.second) && (fin.second <= sw->yf)) || ((in.second <= sw->yi) && (sw->yi <= fin.second)) || ((in.second <= sw->yf) && (sw->yf <= fin.second))) ){

			cout<<"SW:\n";

			sw->find(in,fin);
		}

		if( (((se->xi <= in.first) && (in.first <= se->xf)) || ((se->xi <= fin.first) && (fin.first <= se-> xf)) || ((in.first <= se->xi) && (se->xi <= fin.first)) || ((in.first <= se->xf) && (se->xf <= fin.first))) && (((se->yi <= in.second) && (in.second <= se->yf)) || ((se->yi <= fin.second) && (fin.second <= se->yf)) || ((in.second <= se->yi) && (se->yi <= fin.second)) || ((in.second <= se->yf) && (se->yf <= fin.second))) ){

			cout<<"SE:\n";

			se->find(in,fin);
		}

		if( (((ne->xi <= in.first) && (in.first <= ne->xf)) || ((ne->xi <= fin.first) && (fin.first <= ne-> xf)) || ((in.first <= ne->xi) && (ne->xi <= fin.first)) || ((in.first <= ne->xf) && (ne->xf <= fin.first))) && (((ne->yi <= in.second) && (in.second <= ne->yf)) || ((ne->yi <= fin.second) && (fin.second <= ne->yf)) || ((in.second <= ne->yi) && (ne->yi <= fin.second)) || ((in.second <= ne->yf) && (ne->yf <= fin.second))) ){

			cout<<"NE:\n";

			ne->find(in,fin);
		}

		if(padre!=NULL){

			cout<<"Uniendo vectores\n";

			padre->found.insert(padre->found.end(),found.begin(),found.end());

		}

	}

	else{

		cout<<"En hoja\n";

		if(x >= in.first && x <= fin.first && y >= in.second && y <= fin.second){

			padre->found.push_back(make_pair(x,y));
			cout<<"Push back de "<<x<<", "<<y<<endl;
		}
	}
}
