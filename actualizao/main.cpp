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
		
	KDTree *kd = new KDTree(&v,N,M);
	
	pair<int,int> ri(2,2);
	pair<int,int> rf(70,88);
	
	vector<pair<int,int>> p = kd->find(ri,rf);
	
	cout<<p.size()<<endl;
	
	for(int i = 0; i<p.size(); i++){
	
		pair<int,int> aux(p.at(i));
		
		cout<<aux.first<<", "<<aux.second<<endl;
	}
	
	return 0;
}
	
