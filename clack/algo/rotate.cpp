#include "algostuff.hpp"
using namespace std;
//复制并同时旋转元素
int main()
{
	set<int> coll;

	INSERT_ELEMENT(coll, 1, 9);
	PRINT_ELEMENTS(coll);

	set<int>::iterator pos = coll.begin();
	advance(pos, 1);
	rotate_copy(coll.begin(), pos, coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	pos = coll.end();
	advance(pos, -2);
	rotate_copy(coll.begin(), pos, coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	rotate_copy(coll.begin(), coll.find(4), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}



//旋转元素次序
int main01()
{
	vector<int> coll;

	INSERT_ELEMENT(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	rotate(coll.begin(), coll.begin() + 1, coll.end());
	PRINT_ELEMENTS(coll, "one left: ");

	rotate(coll.begin(), coll.end() - 2, coll.end());
	PRINT_ELEMENTS(coll, "two right: ");

	rotate(coll.begin(), find(coll.begin(), coll.end(), 4), coll.end());
	PRINT_ELEMENTS(coll, "4 first: ");

}