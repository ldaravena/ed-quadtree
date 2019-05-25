#ifndef PR_ADT_
#define PR_ADT_
#include <vector>
#include <utility>

class PR_Tree{

	public:

		virtual std::vector<std::pair<int,int>> find(std::pair<int,int>,std::pair<int,int>)= 0;
};


#endif
