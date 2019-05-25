#include "Quadtree.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main(){

	int N;
	int M;
	int n;
	int x, y;
	vector<pair<int,int>> puntos;
	cout << "Que dimensiones del espacio bidimensional desea?" << endl;
	cin >> N;
	cin >> M;
	cout << "Cuantos puntos desea agregar?" << endl;
	cin >> n;

	srand(time(NULL));

	for(int i=0; i < n; i++){
		x = rand()%N + 1;
		y = rand()%M +1;

		sort(puntos.begin(),puntos.end());

		pair<int,int> aux(make_pair(x,y));

		if(binary_search(puntos.begin(),puntos.end(),aux)){

			i--;
			continue;
		}

		puntos.push_back(make_pair(x,y));
		cout<<i<<" ";
	}

	//
	// puntos.push_back(make_pair(1,3));
	// puntos.push_back(make_pair(1,7));
	// puntos.push_back(make_pair(3,4));
	// puntos.push_back(make_pair(1,15));
	// puntos.push_back(make_pair(2,19));
	// puntos.push_back(make_pair(4,28));
	// puntos.push_back(make_pair(6,12));
	// puntos.push_back(make_pair(7,27));
	// puntos.push_back(make_pair(8,10));
	// puntos.push_back(make_pair(9,2));
	// puntos.push_back(make_pair(10,15));
	// puntos.push_back(make_pair(10,23));
	// puntos.push_back(make_pair(11,4));
	// puntos.push_back(make_pair(14,12));
	// puntos.push_back(make_pair(14,21));
	// puntos.push_back(make_pair(15,4));
	// puntos.push_back(make_pair(16,16));
	// puntos.push_back(make_pair(16,29));
	// puntos.push_back(make_pair(17,2));
	// puntos.push_back(make_pair(18,8));
	// puntos.push_back(make_pair(18,14));
	// puntos.push_back(make_pair(20,18));
	// puntos.push_back(make_pair(21,7));
	// puntos.push_back(make_pair(22,3));
	// puntos.push_back(make_pair(23,16));
	// puntos.push_back(make_pair(24,9));
	// puntos.push_back(make_pair(24,23));
	//
	// puntos.push_back(make_pair(24,23));
	//

	//sort(puntos.begin(),puntos.end());




	Quadtree *qt = new Quadtree(&puntos,N,M);

	pair<int,int> in(17,21);
	pair<int,int> fin(20,25);

	vector<pair<int,int>> encontrados = qt->find(in,fin);

//	vector<pair<int,int>> encontrados = qt->find(make_pair(1,1),make_pair(25,29));


	cout<<"Puntos Encontrados:\n";

	for(int i=0; i<encontrados.size(); i++){

		pair<int,int> aux = (encontrados.at(i));

		cout<<aux.first<<", "<<aux.second<<endl;
	}

	cout<<"Puntos: "<<encontrados.size()<<endl;

	cout<<"\nPuntos Existentes:\n";

	int p=0;

	for(int i=0; i<puntos.size(); i++){

		pair<int,int> aux2 = (puntos.at(i));

		if(aux2.first >= in.first && aux2.first <= fin.first && aux2.second >= in.second && aux2.second <=  fin.second){

			p++;

			cout<<aux2.first<<", "<<aux2.second<<endl;
		}
	}

	cout<<"Puntos: "<<p<<endl;



	return 0;
}
