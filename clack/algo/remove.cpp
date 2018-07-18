#include "algostuff.hpp"
using namespace std;

//复制时一并移除元素
int main()
{
	list<int> coll1;
	INSERT_ELEMENT(coll1, 1, 6);
	INSERT_ELEMENT(coll1, 1, 9);
	PRINT_ELEMENTS(coll1);

	remove_copy(coll1.begin(), coll1.end(), ostream_iterator<int>(cout, " "), 3);
	cout << endl;
	PRINT_ELEMENTS(coll1,"coll1: ");

	remove_copy_if(coll1.begin(), coll1.end(), ostream_iterator<int>(cout, " "), bind2nd(greater<int>(), 4));
	cout << endl;
	PRINT_ELEMENTS(coll1,"coll1: ");

	multiset<int> coll2;
	remove_copy_if(coll1.begin(), coll1.end(), inserter(coll2, coll2.end()), bind2nd(less<int>(), 4));
	PRINT_ELEMENTS(coll2);

}

//移除某序列的元素
int main01()
{
	vector<int> coll;

	INSERT_ELEMENT(coll, 2, 6);
	INSERT_ELEMENT(coll, 4, 9);
	INSERT_ELEMENT(coll, 1, 7);
	PRINT_ELEMENTS(coll, "coll: ");

	vector<int>::iterator pos;
	pos = remove(coll.begin(), coll.end(), 5);
	PRINT_ELEMENTS(coll, "size not change: ");

	coll.erase(pos, coll.end());
	PRINT_ELEMENTS(coll, "size changed: ");

	coll.erase(remove_if(coll.begin(), coll.end(), bind2nd(less<int>(), 4)), coll.end());
	PRINT_ELEMENTS(coll, "<4 removed: ");

}