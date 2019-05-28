#include <vector>
#include <utility>

class Nodo{

    private:

        int x; //x, y son los valores del puntos almacenado (x,y)
        int y;
		char dim; //representa la dimension del nodo (Aplica solo para nodos padres) 
        int linea=0; //este entero almacena el valor de la linea, por ejemplo: Si el nodo es dimension x, y linea = 4, esto representa la recta x=4

        Nodo *padre; //puntero al padre y sus hijos izquierdo y derecho
        Nodo *left;
        Nodo *right;

    public:
    
		std::vector<std::pair<int, int> > found; //vector de los puntos encontrados en el metodo find

		void find(std::pair<int, int> in, std::pair<int, int> fin); //metodo buscar recursivo de los nodos
        Nodo(std::vector<std::pair<int,int> > P, int l, int r, bool b);//constructor recursivo de los nodos

};
