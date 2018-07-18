#include "algostuff.hpp"
using namespace std;

//赋值并替换元素
int main()
{
	list<int> coll;

	INSERT_ELEMENT(coll, 2, 6);
	INSERT_ELEMENT(coll, 4, 9);
	PRINT_ELEMENTS(coll);

	replace_copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "), 5, 55);
	cout << endl;

	replace_copy_if(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "),
		bind2nd(less<int>(), 5), 42);
	cout << endl;


	replace_copy_if(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "),
		bind2nd(modulus<int>(), 2), 0);
	cout << endl;
}









//替换元素
int main01()
{
	list<int> coll;
	INSERT_ELEMENT(coll, 2, 7);
	INSERT_ELEMENT(coll, 4, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	replace(coll.begin(), coll.end(), 6, 42);
	PRINT_ELEMENTS(coll, "coll: ");

	replace_if(coll.begin(), coll.end(), bind2nd(less<int>(), 5), 0);

	PRINT_ELEMENTS(coll, "coll: ");
}