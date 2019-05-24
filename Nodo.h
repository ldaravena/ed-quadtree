#include <vector>
#include <utility>

class Nodo{

	private:

		//Coordenadas del Punto
		int x;
		int y;

		//Coordenadas iniciales del tamaño del nodo
		int xi;
		int yi;
	
		//Coordenadas finales del tamaño del nodo
		int xf;
		int yf;
		
		//Punteros al padre y los hijos
		Nodo *padre;
		Nodo *nw;
		Nodo *sw;
		Nodo *se;
		Nodo *ne;
	
		bool ocupado;
		bool dividido;
		
	public:
		
		std::vector<std::pair<int,int>> found;
		//Métodos del Nodo
		Nodo();
		Nodo(int xff, int yff);
		void dividir();
		void agregar(int px, int py);
		void find(std::pair<int,int> in, std::pair<int,int> fin);
};
