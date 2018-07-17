#include "algostuff.hpp"
#include <iterator>
using namespace std;

int main()
{
	vector<int> coll;
	vector<int>::iterator pos;


	INSERT_ELEMENT(coll, 1, 9);

	PRINT_ELEMENTS(coll, "coll: ");

	pos = find_if(coll.begin(), coll.end(),
		bind2nd(greater<int>(), 3));

	cout << "the" << distance(coll.begin(), pos) + 1
		<< ". element is the first greater than 3" << endl;

	pos = find_if(coll.begin(), coll.end(),
		not1(bind2nd(modulus<int>(), 3)));

	cout << "the" << distance(coll.begin(), pos) + 1
		<< ". element is the first divisible by 3" << endl;

}




int main01()
{
	list<int> coll;

	INSERT_ELEMENT(coll, 1, 9);
	INSERT_ELEMENT(coll, 1, 9);

	PRINT_ELEMENTS(coll, "coll: ");

	list<int>::iterator pos1;
	pos1 = find(coll.begin(), coll.end(), 4);

	list<int>::iterator pos2;
	if (pos1 != coll.end()) {
		pos2 = find(++pos1, coll.end(), 4);
	}

	if (pos1 != coll.end() && pos2 != coll.end()) {
		copy(--pos1, ++pos2, ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}
