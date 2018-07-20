#include "algostuff.hpp"
using namespace std;

//所谓Heap，其元素形成一个二叉树
int main01()
{
	vector<int> coll;
	INSERT_ELEMENT(coll, 3, 7);
	INSERT_ELEMENT(coll, 5, 9);
	INSERT_ELEMENT(coll, 1, 4);
	PRINT_ELEMENTS(coll, "on entry: ");

	make_heap(coll.begin(),coll.end());
	PRINT_ELEMENTS(coll, "after make_heap(): ");

	pop_heap(coll.begin(), coll.end());
	coll.pop_back();
	PRINT_ELEMENTS(coll, "after pop_heap(): ");

	coll.push_back(17);
	push_heap(coll.begin(), coll.end());
	PRINT_ELEMENTS(coll, "after push_heap(): ");

	sort_heap(coll.begin(), coll.end());
	PRINT_ELEMENTS(coll, "after sort_heap(): ");
}

//9 8 6 7 7 5 5 3 6 4 1 2 3 4
//			9
//		8			6
//	7		7	 5		5
//3	   6  4   1 2  3  4