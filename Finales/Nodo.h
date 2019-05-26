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
		
		//Indica si el nodo hoja tiene punto
		bool ocupado;
		
		//Indiica si es nodo padre
		bool dividido;
		
	public:
		//Vector para almacenar los puntos que se encuentran al realizar la búsqueda
		std::vector<std::pair<int,int>> found;
		
		//Métodos constructores del nodo
		Nodo();
		Nodo(int xff, int yff);
		
		//Método para crearle los cuatro hijos al nodo
		void dividir();
		
		//Método para agregar puntos al nodo
		void agregar(int px, int py);
		
		//Método para buscar los puntos dado un rectángulo
		void find(std::pair<int,int> in, std::pair<int,int> fin);
};
