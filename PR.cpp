#include "PR.h"
#include <bits/stdc++.h>

using namespace std;

/*	El constructor del PR-Quadtree recibe como parámetros las coordenadas de la
	esquina superior izquierda del rectángulo inicial (xi, yi), el tamaño del rectángulo
	(filas: N, columnas: M) y el vector con los puntos a colocar 	*/

PR::PR(int xi, int yi, int N, int M, vector<pair<int,int>> puntos){

	int i,j;

	//bool exit_i;
	bool exit_j;

	//Variable para controlar si el existe un punto en el rectángulo actual
	bool ocupado=false;

	//Ciclo para recorrer las filas del rectángulo
	for(i=xi; i<N; i++){

		//Ciclo para recorrer las columnas del rectángulo
		for(j=yi; j<M; j++){

			exit_j=false;

			//Ciclo para recorrer el vector de puntos
			for(k=0; k < puntos.size(); k++){

				//Punto actual a comparar
				pair<int,int> actual(puntos.at(k));

				/*	Si la coordenada x del punto actual es mayor a la coordenada x del rectángulo
					no se revisan más puntos y se sale del ciclo de revisión de la coordenada y	*/
				if(i < actual.first){

					exit_j=true;

					break;
				}

				//Si la coordenada x del punto es igual a la coordenada del rectángulo
				if(i == actual.first){

					/*	Si la coordenada 'y' del punto es mayor a la coordenada 'y' del rectángulo
					 	se sale del ciclo de revisión de los puntos*/
					if(j < actual.second) break;

					//Si la coordenada 'y' del punto es igual a la coordenada del rectángulo
					else if(j == actual.second){

						//Si el rectángulo actual no tiene puntos se crea un nuevo nodo
						if(!ocupado){

							nodo *nuevo = new nodo;

							//Se completa con los datos del punto
							nodo->x=actual.first;
							nodo->y=actual.second;

							//Si es el primer nodo que se crea se le asigna puntero a la raiz
							if(raiz==NULL){

								raiz=nodo;
							}

/*********************/ /*ACÁ SE COLOCA EL NODO CREADO EN SU POSICIÓN CORRESPONDIENTE*/
							//Se borra el punto del vector de puntos
							puntos.erase(k);

							//Se marca el rectángulo como ocupado
							ocupado = true;
						}

/*********************/	/*ACÁ EMPIEZA LA MAGIA CON LA DIVISIÓN DEL RECTÁNGULO*/

						//Si el rectángulo ya tiene punto:
						else{

						}
					}
				}
			}

			if(exit_j) break;
		}
	}
}
