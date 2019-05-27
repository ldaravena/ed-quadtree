#include <vector>
#include <utility>

class Nodo{

    private:

        int x;
        int y;
		char dim;
        int linea=0;

        Nodo *padre;
        Nodo *left;
        Nodo *right;

    public:
    
		std::vector<std::pair<int, int>> found;

		void find(std::pair<int, int> in, std::pair<int, int> fin);
        Nodo(std::vector<std::pair<int,int>> *X, std::vector<std::pair<int,int>> *Y, bool b);

};
