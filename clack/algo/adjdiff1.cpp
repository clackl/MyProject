#include "algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll;
	INSERT_ELEMENT(coll, 1, 6);
	PRINT_ELEMENTS(coll);

	adjacent_difference(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	adjacent_difference(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "), plus<int>());
	cout << endl;
	adjacent_difference(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "), multiplies<int>());
	cout << endl;
}