#include "KDTree.h"
#include <bits/stdc++.h>

using namespace std;

int main(){

	int N,M,n,x,y;
	
	vector<pair<int,int>> v;
	
	cin>>N>>M>>n;
	
	for(int i=0; i<n; i++){
	
		cin>>x>>y;
		
		v.push_back(make_pair(x,y));
	}
		
	KDTree *kd = new KDTree(v,N,M);
	
	pair<int,int> ri(10,15);
	pair<int,int> rf(50,75);
	
	vector<pair<int,int>> p = kd->find(ri,rf);
	
	cout<<"Puntos encontrados :"<<p.size()<<endl;
	
/*	for(int i = 0; i<p.size(); i++){
	
		pair<int,int> aux(p.at(i));
		
		cout<<aux.first<<", "<<aux.second<<endl;
	}
*/
	
	
	int pn=0;

	for(int i=0; i<v.size(); i++){

		pair<int,int> aux2 = (v.at(i));

		if(aux2.first >= ri.first && aux2.first <= rf.first && aux2.second >= ri.second && aux2.second <=  rf.second){

			pn++;

		}
	}

	cout<<"\nPuntos Existentes: "<<pn<<endl;
		
	return 0;
}
	
