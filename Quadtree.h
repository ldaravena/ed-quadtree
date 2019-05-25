#include "PR_ADT.h"
#include "Nodo.h"
#include <vector>
#include <utility>

class Quadtree : public PR_Tree{
	
	private:

		Nodo *root;
	
	public:

		Quadtree(std::vector<std::pair<int,int>> *P, int N, int M);
		std::vector<std::pair<int,int>> find(std::pair<int,int> in, std::pair<int,int> fin);
};