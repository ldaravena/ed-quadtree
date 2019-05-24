#include "Quadtree.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

	int N = 25;
	int M = 29;

	vector<pair<int,int>> puntos;

	
	puntos.push_back(make_pair(1,3));
	puntos.push_back(make_pair(1,7));
	puntos.push_back(make_pair(3,4));
	puntos.push_back(make_pair(1,15));
	puntos.push_back(make_pair(2,19));
	puntos.push_back(make_pair(4,28));
	puntos.push_back(make_pair(6,12));
	puntos.push_back(make_pair(7,27));
	puntos.push_back(make_pair(8,10));
	puntos.push_back(make_pair(9,2));
	puntos.push_back(make_pair(10,15));
	puntos.push_back(make_pair(10,23));
	puntos.push_back(make_pair(11,4));
	puntos.push_back(make_pair(14,12));
	puntos.push_back(make_pair(14,21));
	puntos.push_back(make_pair(15,4));
	puntos.push_back(make_pair(16,16));
	puntos.push_back(make_pair(16,29));
	puntos.push_back(make_pair(17,2));
	puntos.push_back(make_pair(18,8));
	puntos.push_back(make_pair(18,14));
	puntos.push_back(make_pair(20,18));
	puntos.push_back(make_pair(21,7));
	puntos.push_back(make_pair(22,3));
	puntos.push_back(make_pair(23,16));
	puntos.push_back(make_pair(24,9));
	puntos.push_back(make_pair(24,23));
	
	Quadtree *qt = new Quadtree(&puntos,N,M);

	vector<pair<int,int>> encontrados = qt->find(make_pair(2,2),make_pair(10,27));

/*	for(int i=0; i<encontrados.size(); i++){
		
		pair<int,int> aux = (encontrados.at(i));
		
		cout<<aux.first<<", "<<aux.second<<endl;
	}

*/	

	return 0;
}
