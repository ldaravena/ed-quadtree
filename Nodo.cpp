#include "Nodo.h"
#include <cstdlib>

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
	
	//Se calculan las dimensiones de los nuevos nodos
	int fx = xf/2;
	int fy = yf/2;
	
	//Se marca el nodo como dividido
	dividido = true;
	
	//Se crea un nuevo nodo auxiliar y se copia la dirección al hijo 'nw'
	Nodo *aux = new Nodo();
	nw = aux;
	
	//Se agrega la dirección del padre
	nw->padre = this;
	
	//Se agregan las dimensiones iniciales del nodo 'nw'
	nw->xi = xi;
	nw->yi = yi;
	
	//Se agregan las dimensiones finales
	nw->xf = fx;
	nw->yf = fy;
	
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
	
	Nodo *aux2 = new Nodo();

	sw = aux2;

	sw->padre = this;

	sw->xi = fx +1;
	sw->yi = yi;

	sw->xf = xf;
	sw->yf = fy;

	if(x >= sw->xi && x <= sw->xf && y >= sw->yi && y <= sw->yf){

		sw->x = x;
		sw->y = y;
		
		cout<<"Heredado sw: "<<x<<", "<<y<<endl;
		
		x=0;
		y=0;
		sw->ocupado = true;
		
	}

	Nodo *aux3 = new Nodo();

	se = aux3;

	se->padre = this;

	se->xi = fx + 1;
	se->yi = fy + 1;

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

	Nodo *aux4 = new Nodo();

	ne = aux4;

	ne->padre = this;

	ne->xi = xi;
	ne->yi = fy +1;

	ne->xf = fx;
	ne->yf = yf;


	if(x >= ne->xi && x <= ne->xf && y >= ne->yi && y <= ne->yf){

		ne->x = x;
		ne->y = y;
		
		cout<<"Heredado ne: "<<x<<", "<<y<<endl;

		x=0;
		y=0;
		ne->ocupado = true;
	}
}
