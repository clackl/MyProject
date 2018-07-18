#include "algostuff.hpp"
using namespace std;

//逆转元素顺序
int main()
{
	vector<int> coll;

	INSERT_ELEMENT(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	reverse(coll.begin(), coll.end());
	PRINT_ELEMENTS(coll, "coll: ");

	reverse(coll.begin() + 1, coll.end() - 1);
	PRINT_ELEMENTS(coll, "coll: ");

	reverse_copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));

	cout << endl;

}