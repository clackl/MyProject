#include "algostuff.hpp"
using namespace std;
//与某序列相等的最后一个子序列
int main()
{
	deque<int> coll;
	list<int> subcoll;

	INSERT_ELEMENT(coll, 1, 7);
	INSERT_ELEMENT(coll, 1, 7);

	INSERT_ELEMENT(subcoll, 3, 6);

	PRINT_ELEMENTS(coll, "coll: ");
	PRINT_ELEMENTS(subcoll, "subcoll: ");

	deque<int>::iterator pos;
	pos = find_end(coll.begin(), coll.end(), subcoll.begin(), subcoll.end());

	deque<int>::iterator end(coll.end());
	while (pos != end) {
		cout << "subcoll found starting with element "
			<< distance(coll.begin(), pos) + 1 << endl;

		end = pos;
		pos = find_end(coll.begin(), end, subcoll.begin(), subcoll.end());
	}

}