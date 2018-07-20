#include "algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll1;
	vector<int> coll6(6);
	vector<int> coll30(30);

	INSERT_ELEMENT(coll1, 3, 7);
	INSERT_ELEMENT(coll1, 2, 6);
	INSERT_ELEMENT(coll1, 1, 5);
	PRINT_ELEMENTS(coll1);


	vector<int>::iterator pos6;
	pos6 = partial_sort_copy(coll1.begin(), coll1.end(), coll6.begin(), coll6.end());

	copy(coll6.begin(), pos6, ostream_iterator<int>(cout, " "));
	cout << endl;

	vector<int>::iterator pos30;
	pos30 = partial_sort_copy(coll1.begin(), coll1.end(), coll30.begin(), coll30.end(), greater<int>());

	copy(coll30.begin(), pos30, ostream_iterator<int>(cout, " "));
	cout << endl;


}


int main03()
{
	deque<int> coll;

	INSERT_ELEMENT(coll, 3, 7);
	INSERT_ELEMENT(coll, 2, 6);
	INSERT_ELEMENT(coll, 1, 5);
	PRINT_ELEMENTS(coll);

	partial_sort(coll.begin(), coll.begin() + 2, coll.end());
	PRINT_ELEMENTS(coll);

	partial_sort(coll.begin(), coll.begin() + 2, coll.end(), greater<int>());
	PRINT_ELEMENTS(coll);

	partial_sort(coll.begin(), coll.end(), coll.end());

	PRINT_ELEMENTS(coll);

}



bool lessLength(const string& s1, const string& s2) {
	return s1.length() < s2.length();
}

int main02()
{
	vector<string> coll1;
	vector<string> coll2;

	coll1.push_back("1xxx");
	coll1.push_back("2x");
	coll1.push_back("3x");
	coll1.push_back("4x");
	coll1.push_back("5xx");
	coll1.push_back("6xxxx");
	coll1.push_back("7xx");
	coll1.push_back("8xxx");
	coll1.push_back("9xx");
	coll1.push_back("10xxx");
	coll1.push_back("11");
	coll1.push_back("12");
	coll1.push_back("13");
	coll1.push_back("14xx");
	coll1.push_back("15");
	coll1.push_back("16");
	coll1.push_back("17");
	coll2 = coll1;

	PRINT_ELEMENTS(coll1, "on entry:\n ");

	sort(coll1.begin(), coll1.end(), lessLength);

	stable_sort(coll2.begin(), coll2.end(), lessLength);

	PRINT_ELEMENTS(coll1, "\nwith sort():\n ");
	PRINT_ELEMENTS(coll2, "\nwith stable_sort():\n ");

}


int main01()
{
	deque<int> coll;
	INSERT_ELEMENT(coll, 1, 9);
	INSERT_ELEMENT(coll, 1, 9);

	PRINT_ELEMENTS(coll, "coll: ");
	sort(coll.begin(), coll.end());

	PRINT_ELEMENTS(coll, "on entry: ");

	sort(coll.begin(), coll.end(), greater<int>());

	PRINT_ELEMENTS(coll, "sorted: ");
}