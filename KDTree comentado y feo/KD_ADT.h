#ifndef KD_ADT_
#define KD_ADT_

#include <vector>
#include <utility>

class KD_Tree{

    public:

		virtual std::vector<std::pair<int, int> > find(std::pair<int, int>, std::pair<int, int>) = 0; 	//Metodo find del KDTree para encontrar puntos dentro de un rectangulo determinado en el espacio
};

#endif
