#include "Nodo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

	Nodo *Qtree = new Nodo(20,20);

	int m[10][2];

	m[1][0] = 3;
	m[1][1] = 3;

	m[2][0] = 2;
	m[2][1] = 12;

	m[3][0] = 4;
	m[3][1] = 14;

	m[4][0] = 5;
	m[4][1] = 16;

	m[5][0] = 8;
	m[5][1] = 7;

	m[6][0] = 8;
	m[6][1] = 11;

	m[7][0] = 13;
	m[7][1] = 3;

	m[8][0] = 16;
	m[8][1] = 6;

	m[9][0] = 16;
	m[9][1] = 16;

	m[0][0] = 17;
	m[0][1] = 17;

	
	for(int i=0; i<10; i++){

		cout<<m[i][0]<<", "<<m[i][1]<<endl;

		Qtree->agregar(m[i][0],m[i][1]);
		cout<<Qtree->x<<", "<<Qtree->y<<endl;
		cout<<&Qtree<<endl;

	}


	return 0;
}
