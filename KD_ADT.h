#ifndef KD_ADT_
#define KD_ADT_

class KD_Tree{

    public:

		virtual std::vector<std::pair<int, int>> find(std::pair<int, int>, std::pair<int, int>) = 0;
};

#endif
