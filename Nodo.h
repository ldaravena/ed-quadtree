#include <utility>

class Nodo{

    private:

        int x;
        int y;

        int linea;

        Nodo *padre;
        Nodo *left;
        Nodo *right;

    public:

        Nodo(std::vector<std::pair<int,int>> *X, std::vector<std::pair<int,int>> *Y, bool b));

}
