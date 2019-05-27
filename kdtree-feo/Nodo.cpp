#include "Nodo.h"
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

Nodo::Nodo(vector<pair<int,int>> P, int l, int r, bool b){

	if(b){
	
		sort(P.begin(),P.end());
	}
	
	else{
	
		
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
	
	int v = (l+r)/2;
	
	if(l==r){
	
		pair<int,int> par(P.at(l));
		
		x=par.first;
		y=par.second;
		
		cout<<"Colocado :"<<x<<", "<<y<<endl;
		
		padre=this;
	}
	
	else{
	
		if(b){
			
			pair<int,int> par(P.at(v));
			
			linea = par.first;
			dim = 'x';
		}
		
		else{
			
			
			pair<int,int> par(P.at(v));
			
			linea = par.second;
			dim = 'y';
		}
		
		left = new Nodo(P, l, v, false);
		left->padre=this;
		
		right = new Nodo(P, v+1, r,false);
		right->padre=this;
	}
}
void Nodo::find(std::pair<int, int> in, std::pair<int, int> fin) {
	
	if (linea == 0) {
	
	//	cout<<"Linea = 0\n";
		if (x >= in.first && x <= fin.first && y >= in.second && y <= fin.second) {
			
		//	cout<<"Encontrao\n";
			padre->found.push_back(make_pair(x, y));
		}
	}
	
	else {
		
		if (dim == 'x') {
		
			//cout<<"dim = x\n";
			if (in.first <= linea) {
			
				if(left!=NULL) left->find(in, fin);
			}
			
			if (fin.first >= linea) {
			
				if(right!=NULL) right->find(in, fin);
			}
		}
		else if (dim == 'y') {
				//cout<<"dim = y\n";
			if (in.second <= linea) {
			
				if(left!=NULL) left->find(in, fin);

			}
			
			if (fin.second >= linea) {
			
				if(right!=NULL) right->find(in, fin);
			}
		}
		if (padre != NULL) {
		
			padre->found.insert(padre->found.end(), found.begin(), found.end());
		}
	}
}
					
					
			
