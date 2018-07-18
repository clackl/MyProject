#include "algostuff.hpp"
#include <iterator>
using namespace std;

int main()
{
	vector<int> coll1;
	list<int> coll2;

	INSERT_ELEMENT(coll1, 1, 9);
	PRINT_ELEMENTS(coll1, "coll1: ");

	transform(coll1.begin(), coll1.end(), coll1.begin(), coll1.begin(), multiplies<int>());
	PRINT_ELEMENTS(coll1, "squared: ");

	transform(coll1.begin(), coll1.end(), coll1.rbegin(), back_inserter(coll2), plus<int>());
	PRINT_ELEMENTS(coll2, "coll2: ");

	cout << "diff: ";
	transform(coll1.begin(), coll1.end(), coll2.begin(), ostream_iterator<int>(cout, " "), minus<int>());
	cout << endl;
}

int main01()
{
	vector<int> coll1;
	list<int> coll2;

	INSERT_ELEMENT(coll1, 1, 9);
	PRINT_ELEMENTS(coll1, "coll1: ");

	transform(coll1.begin(), coll1.end(), coll1.begin(), negate<int>());

	PRINT_ELEMENTS(coll1, "negate: ");

	transform(coll1.begin(), coll1.end(), back_inserter(coll2), bind2nd(multiplies<int>(), 10));
	PRINT_ELEMENTS(coll2, "coll2:");

	transform(coll2.rbegin(), coll2.rend(), ostream_iterator<int>(cout, " "),negate<int>());

	cout << endl;

}