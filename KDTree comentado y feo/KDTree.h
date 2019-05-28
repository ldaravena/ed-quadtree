#include "KD_ADT.h"
#include "Nodo.h"
#include <vector>
#include <utility>

class KDTree : public KD_Tree{

    private:

        int n; //Numero de filas
        int m; //numero de columnas

        //std::vector<std::pair<int,int> > X; ESTOS VECTORES YA NO SON NECESARIOS
        //std::vector<std::pair<int,int> > Y; 

        Nodo* root;


    public:

        KDTree(std::vector<std::pair<int,int> > P, int N, int M); //Metodo constructor que organizan todos los puntos 
		std::vector<std::pair<int, int> > find(std::pair<int, int> in, std::pair<int, int> fin); //Metodo Para encontrar los puntos dentro de un rectangulo
};
