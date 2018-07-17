#include <iostream>
#include <list>
#include <algorithm>
#include "print.hpp"
using namespace std;

class Nth {
private:
	int nth;
	int count;
public:
	Nth(int n) :nth(n), count(0) {
	}

	bool operator()(int) {
		return ++count == nth;
	}
};

//template<class Forwiter,class Predicate>
//Forwiter std::remove_if(Forwiter beg, Forwiter end, Predicate op)
//{
//	while (beg != end && !op(*beg)) {
//		++beg;
//	}
//	if (beg == end) {
//		return beg;
//	}
//	else {
//		Forwiter next = beg;
//		return remove_copy_if(++next, end, beg.op);
//	}
//}


int main()
{
	list<int> coll;
	for (int i = 1; i <= 9; ++i) {
		coll.push_back(i);
	}

	PRINT_ELEMENTS(coll, "coll: ");

	list<int>::iterator pos;
	//remove_if算法会把所有“令单参数判断式结果为true的元素移除”
	pos = remove_if(coll.begin(), coll.end(), Nth(3));

	coll.erase(pos, coll.end());
	PRINT_ELEMENTS(coll, "nth removed: ");
}