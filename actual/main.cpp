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
	
	return 0;
}
	
