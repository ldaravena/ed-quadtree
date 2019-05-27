#include "Nodo.h"
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

Nodo::Nodo(vector<pair<int,int>> *X, vector<pair<int,int>> *Y, bool b){

    if(X->size() == 1){

		pair<int, int> punto(X->at(0));
		
		X->pop_back();
		
        x=punto.first;
        y=punto.second;
        
        cout<<"Punto colocado: "<<x<<", "<<y<<endl;		

    }

    else if(b){
		
//		cout<<"Division en X\n";
		
        int v =(X->size() /2);
        
  //      cout<<"X: "<<v<<endl;
		
		
		    vector<pair<int,int>> Xl,Xr,Yl,Yr;

		    vector<pair<int,int>>::iterator it=X->begin()+v;

		    Xl.insert(Xl.end(),X->begin(),it);

		    Xr.insert(Xr.end(),it,X->end());

		    pair<int,int> parx(X->at(v));
		    

		    for(int i=0; i< Y->size(); i++){


		        pair<int,int> pary(Y->at(i));


		        if(pary.first < parx.first){

		            Yl.push_back(pary);
		        }

		        else{

		            Yr.push_back(pary);
		        }
		    }

		    linea = parx.first;
			dim = 'x';
/*			
			cout<<"Xleft :\n";
			
			for(int i=0; i<Xl.size(); i++){
				
				pair<int,int> aux(Xl.at(i));
				
				cout<<aux.first<<", "<<aux.second<<endl;
			}
			
			cout<<"Xright :\n";
			
			for(int i=0; i<Xr.size(); i++){
				
				pair<int,int> aux(Xr.at(i));
				
				cout<<aux.first<<", "<<aux.second<<endl;
			}
			
			cout<<"Yleft :\n";
			
			for(int i=0; i<Yl.size(); i++){
				
				pair<int,int> aux(Yl.at(i));
				
				cout<<aux.first<<", "<<aux.second<<endl;
			}
			
			cout<<"Yright :\n";

			for(int i=0; i<Yr.size(); i++){
				
				pair<int,int> aux(Yr.at(i));
				
				cout<<aux.first<<", "<<aux.second<<endl;
			}
			*/
			
			if(Yl.size() > 0){ 
			    left = new Nodo(&Xl,&Yl,false);
			    left->padre = this;
		}
			
		if(Yr.size() > 0){ 
		    	right = new Nodo(&Xr,&Yr,false);
		    	right->padre = this;
			}
    }

    else{
		
	//	cout<<"Division en Y\n";
		
        int v =(Y->size() /2);
        
    //    cout<<"Y: "<<v<<endl;
		
		    vector<pair<int,int>> Xl,Xr,Yl,Yr;

		    vector<pair<int,int>>::iterator it=Y->begin()+v;

		    Yl.insert(Yl.end(),Y->begin(),it);

		    Yr.insert(Yr.end(),it,Y->end());

		    pair<int,int> pary(Y->at(v));
		    
		    for(int i=0; i< X->size(); i++){


		        pair<int,int> parx(X->at(i));


		        if(parx.second < pary.second){

		            Xl.push_back(parx);
		        }

		        else{

		            Xr.push_back(parx);
		        }
		    }

		    linea = pary.second;
			dim = 'y';
			
/*		//				cout<<"Xleft :\n";
			
			for(int i=0; i<Xl.size(); i++){
				
				pair<int,int> aux(Xl.at(i));
				
		//		cout<<aux.first<<", "<<aux.second<<endl;
			}
			
		//	cout<<"Xright :\n";
			
			for(int i=0; i<Xr.size(); i++){
				
				pair<int,int> aux(Xr.at(i));
				
				cout<<aux.first<<", "<<aux.second<<endl;
			}
			
			cout<<"Yleft :\n";
			
			for(int i=0; i<Yl.size(); i++){
				
				pair<int,int> aux(Yl.at(i));
				
				cout<<aux.first<<", "<<aux.second<<endl;
			}
			
			cout<<"Yright :\n";

			for(int i=0; i<Yr.size(); i++){
				
				pair<int,int> aux(Yr.at(i));
				
				cout<<aux.first<<", "<<aux.second<<endl;
			}
	*/		
			if(Xl.size() > 0){ 
			
				left = new Nodo(&Xl,&Yl,true);
				left->padre = this;
			}
			
			if(Xr.size() > 0){ 
				right = new Nodo(&Xr,&Yr,true);
				right->padre = this;
		   }
    }
}
void Nodo::find(std::pair<int, int> in, std::pair<int, int> fin) {
	
	if (linea == 0) {
		if (x >= in.first && x <= fin.first && y >= in.second && y <= fin.second) {

			padre->found.push_back(make_pair(x, y));
		}
	}
	else {
		if (dim == 'x') {
			if (in.first <= linea) {
				left->find(in, fin);
			}
			if (fin.first > linea) {
				right->find(in, fin);
			}
		}
		else if (dim == 'y') {
			if (fin.second <= linea) {
				left->find(in, fin);

			}
			if (in.second > linea) {
				right->find(in, fin);
			}
		}
		if (padre != NULL) {
			padre->found.insert(padre->found.end(), found.begin(), found.end());
		}
	}
}
