#include "algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll;
	INSERT_ELEMENT(coll, 3, 7);
	INSERT_ELEMENT(coll, 2, 6);
	INSERT_ELEMENT(coll, 1, 5);
	PRINT_ELEMENTS(coll);

	nth_element(coll.begin(), coll.begin() + 3, coll.end());
	PRINT_ELEMENTS(coll);
	cout << "the four lowest elements are: ";
	copy(coll.begin(), coll.begin() + 4, ostream_iterator<int>(cout, " "));
	cout << endl;

	nth_element(coll.begin(), coll.end() - 4, coll.end());
	PRINT_ELEMENTS(coll);

	cout << "the four highest elements are: ";
	copy(coll.end() - 4, coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	nth_element(coll.begin(), coll.begin() + 3, coll.end(), greater<int>());
	PRINT_ELEMENTS(coll);
	cout << "the four highest elements are: ";
	copy(coll.begin(), coll.begin()+4, ostream_iterator<int>(cout, " "));
	cout << endl;

}