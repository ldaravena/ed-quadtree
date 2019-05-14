#include "PR_ADT.h"

struct nodo{

	int x;
	int y;

	nodo *padre;
	nodo *nw;
	nodo *sw;
	nodo *se;
	nodo *ne;
};

struct punto{

	int x;
	int y;
};

class PR: public PR_Tree{

	private:
		
		nodo raiz;
		
	public:
		
		PR(int n,int m,std::vector<punto> puntos);
		bool search(punto);
};
