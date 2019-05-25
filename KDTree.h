#include "KD_ADT.h"
#include "Nodo.h"
#include <vector>
#include <utility>

class KDTree : public KD_Tree{

    private:

        int N;
        int M;

        std::vector<std::pair<int,int>> X;
        std::vector<std::pair<int,int>> Y;

        Nodo root;


    public:

        KDTree(std::vector<std::pair<int,int>> *P, int N, int M);
};
